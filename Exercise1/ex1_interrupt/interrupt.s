        .syntax unified
	
	      .include "efm32gg.s"

	/////////////////////////////////////////////////////////////////////////////
	//
  	// Exception vector table
  	// This table contains addresses for all exception handlers
	//
	/////////////////////////////////////////////////////////////////////////////
	
        .section .vectors
	
	      .long   stack_top               /* Top of Stack                 */
	      .long   _reset                  /* Reset Handler                */
	      .long   dummy_handler           /* NMI Handler                  */
	      .long   dummy_handler           /* Hard Fault Handler           */
	      .long   dummy_handler           /* MPU Fault Handler            */
	      .long   dummy_handler           /* Bus Fault Handler            */
	      .long   dummy_handler           /* Usage Fault Handler          */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* SVCall Handler               */
	      .long   dummy_handler           /* Debug Monitor Handler        */
	      .long   dummy_handler           /* Reserved                     */
	      .long   dummy_handler           /* PendSV Handler               */
	      .long   dummy_handler           /* SysTick Handler              */

	      /* External Interrupts */
	      .long   dummy_handler
	      .long   gpio_handler            /* GPIO even handler */
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   gpio_handler            /* GPIO odd handler */
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler
	      .long   dummy_handler

	      .section .text

	/////////////////////////////////////////////////////////////////////////////
	//
	// Reset handler
  	// The CPU will start executing here after a reset
	//
	/////////////////////////////////////////////////////////////////////////////

	      .globl  _reset
	      .type   _reset, %function
        .thumb_func
_reset: 
	/** ENABLE GPIO CLOCK IN CMU**/
	        
	    ldr r1, =CMU_BASE						// load CMU base address
	    ldr r2, [r1, #CMU_HFPERCLKEN0]			// load current value of HFPERCLK ENABLE
	    mov r3, #1								// move value 1 into r3
	    lsl r3, r3, #CMU_HFPERCLKEN0_GPIO		// create the GPIO clk enable mask
	    orr r2, r2, r3							// OR the mask with the current values
	    str r2, [r1, #CMU_HFPERCLKEN0]			// store the new value in CMU_HFPERCLKEN0
	    
	    
	/**SET HIGH STRENGTH**/ 
	   	
	   	LOWEST   = 0x1							// 0.1mA drive current
	    LOW      = 0x3 							// 1mA drive current
	    STANDARD = 0x0							// 6mA drive current
	   	HIGH     = 0x2							// 20mA drive current
	   	
	   	ldr r1, =GPIO_PA_BASE					// load base address
	   	ldr r2, =LOW							// load drive value
	   	str r2, [r1, #GPIO_CTRL]				// store drive value
	   	
	   	
	/**SET PINS 8-15 to OUTPUT**/
	
	   	ldr r1, =GPIO_PA_BASE					// load base address
	   	ldr r3, =0x55555555						// load value
	   	str r3, [r1, #GPIO_MODEH]				// store new value in GPIO_MODEH
	   	
		// initialize LEDs as off
		ldr r0, =0xFF00							// Load "off" bits 
		str r0, [r1, #GPIO_DOUT]				// Store new value in GPIO_PA_DOUT
		  
	   	
    /**SET PINS 0-7 to INPUT**/
					
	   	ldr r1, =GPIO_PC_BASE					// load base address
	   	ldr r3, =0x33333333						// load value
	   	str r3, [r1, #GPIO_MODEL]				// store new value in GPIO_MODEL


	/**ENABLE INTERNAL PULL-UP**/
   						
	   	ldr r1, =GPIO_PC_BASE					// load base address
	   	ldr r3, =0xFF 							// load value
	   	str r3, [r1, #GPIO_DOUT]				// store new value in GPIO_DOUT	   	
	
	
	/**ENABLE INTERRUPTS**/
		
		ldr r1, =GPIO_BASE					    // load base address
		ldr r0, [r1,#GPIO_IF]					// load flag
		str r0, [r1,#GPIO_IFC]					// store clean
		
	   	ldr r3, =0x22222222						// load value
	   	str r3, [r1, #GPIO_EXTIPSELL]			// store new value in GPIO_EXTISPELL
	   	
	   	ldr r3, =0xFF
	   	str r3, [r1, #GPIO_EXTIFALL]			// store new value in EXTIFALL
	   	ldr r3, =0x00
	   	str r3, [r1, #GPIO_EXTIRISE]			// store new value in EXTIRISE
	   	ldr r3, =0xFF
	   	str r3, [r1, #GPIO_IEN]					// store new value in IEN

		ldr r1, =ISER0							// load base address	
		ldr r3, =0x802							// 
		str r3, [r1]							// store new value in ISER0


	/**ENABLE ENERGY MODE**/
		ldr r3, =SCR							// load address
		mov r1, #0x6							// load value
		str r1, [r3]							// store in SCR
		
	b main 										// jump to main
	
	/////////////////////////////////////////////////////////////////////////////
	//
  	// GPIO handler (Interrupt handler)
  	// The CPU will jump here when there is a GPIO interrupt
	//
	/////////////////////////////////////////////////////////////////////////////
	
        .thumb_func
gpio_handler:  

	ldr r0, =GPIO_PC_BASE					// load base address
	ldr r1, [r0, #GPIO_DIN]					// load button values
	lsl r1, r1, #8							// shift into LED registers
	ldr r2, =GPIO_PA_BASE					// load DOUT base
	str r1, [r2, #GPIO_DOUT]				// store LED values

	ldr r1, =GPIO_BASE						// load base address
	ldr r2, [r1,#GPIO_IF]					// load interrupt flag
	str r2, [r1,#GPIO_IFC]					// clean interrupt
	
    //ldr r1, =GPIO_PA_BASE					// load base address
	//ldr r3, [r1, #GPIO_DIN]				// load LED values
	//eor r3, r3, r3						// turn on/off

 	bx lr									// continue where left off

	/////////////////////////////////////////////////////////////////////////////
	
        .thumb_func
dummy_handler:  
        b .  // do nothing
    
        
    /////////////////////////////////////////////////////////////////////////////
	//
  	// MAIN PROGRAM 														   //
  	//
	/////////////////////////////////////////////////////////////////////////////
	
main:	
    	wfi 								// enter low power mode
    	
    	// should never reach this
    	b main								// loop main
    	
    	
    	
    	
    	
    	
    	
    	


