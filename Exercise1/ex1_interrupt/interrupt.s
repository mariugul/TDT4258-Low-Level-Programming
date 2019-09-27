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
	    
	    
	/**SET HIGH DRIVE STRENGTH (20mA pins)**/ 
	   	
	   	LOWEST   = 0x1							// 0.1mA drive current
	    LOW      = 0x3 							// 1mA drive current
	    STANDARD = 0x0							// 6mA drive current
	   	HIGH     = 0x2							// 20mA drive current
	   	
	   	ldr r1, =GPIO_PA_BASE					// load base address
	   	ldr r2, =LOW							// load the HIGH drive value
	   	str r2, [r1]							// store HIGH drive
	   	
	   	
	/**SET PINS 8-15 to OUTPUT**/
	
	   	ldr r1, =GPIO_PA_BASE					// load base address
	   	mov r3, #0x55555555						// load value
	   	str r3, [r1, #GPIO_MODEH]				// store new value in GPIO_MODEH
	   	
		// initialize LEDs as off
		mov r0, #0xFF00							// Load "off" bits 
		str r0, [r1, #GPIO_PA_DOUT]				// Store new value in GPIO_PA_DOUT
		  
	   	
    /**SET PINS 0-7 to INPUT**/
					
	   	ldr r1, =GPIO_PA_BASE					// load base address
	   	mov r3, #0x33333333						// load value
	   	str r3, [r1, #GPIO_PC_MODEL]				// store new value in GPIO_MODEL


	/**ENABLE INTERNAL PULL-UP**/
   						
	   	ldr r1, =GPIO_PA_BASE					// load base address
	   	ldr r3, =0xFF 							// load value
	   	str r3, [r1, #GPIO_PC_DOUT]				// store new value in GPIO_DOUT	   	
	
	
	/**ENABLE INTERRUPTS**/
		
	   	ldr r1, =GPIO_PA_BASE					// load base address
	   	ldr r3, =0x22222222						// load value
	   	str r3, [r1, #GPIO_EXTIPSELL]			// store new value in GPIO_EXTISPELL
	   	
	   	mov r3, #0xFF
	   	str r3, [r1, #GPIO_EXTIFALL]			// store new value in EXTIFALL
	   	str r3, [r1, #GPIO_EXTIRISE]			// store new value in EXTIRISE
	   	str r3, [r1, #GPIO_IEN]					// store new value in IEN

		ldr r1, =ISER0							// load base address	
		movw r3, #0x802							// 
		str r3, [r1]							// store new value in ISER0

   	
   	/** ENABLE ENERGY MODE 3 **/ 
   	
		ldr r0, =EMU_BASE						// load base
		mov r1, #0								// load value
		str r1, [r0]							// store value in EMU_BASE
	
		ldr r3, =SCR							// load address
		mov r1, #1								// load value
		lsl r1, #2								// left shift into correct position
		str r1, [r3]							// store in SCR
		
		// optimize this block
		mov r1, #0								// load value
		str r1, [r0]							// store into EMU_BASE
		lsl r1, #1								// left shift into correct position
		str r1, [r0]							// store into EMU_BASE
		
		// optimize this block
		ldr r0, =0x028 							// load CMU_LFCLKSEL
		mov r1, #0							
		mov r2, #0
		lsl r1, r1, #16
		lsl r1, r2, #4
		str r1, [r0]
	  	
	b main 										// jump to main
	
	/////////////////////////////////////////////////////////////////////////////
	//
  	// GPIO handler (Interrupt handler)
  	// The CPU will jump here when there is a GPIO interrupt
	//
	/////////////////////////////////////////////////////////////////////////////
	
        .thumb_func
gpio_handler:  
	
	button1:
	ldr r0, =GPIO_PC_BASE						// load base address
	ldr r1, [r0, #GPIO_PC_DIN]					// load button values
    ldr r2, =0b11111110                         // mask for button 1
    orr r3, r2, r1                              // or with the mask 
	cmp r3, r2                                  // if the mask equals the result
	bneq clean
	
	
	ldr r1, =GPIO_PA_BASE						// load base address
	ldr r0, [r1, #GPIO_PA_DOUT]					// load offset
	lsl r0, r0, #1								// shift to the left 1 positions
	str r0, [r1, #GPIO_PA_DOUT]  				// store new value
	
	
	clean:
	#Cleaning interrupt:
	ldr r0, [r1,#GPIO_IF]
	str r0, [r1,#GPIO_IFC]

	
	bx lr  										// continue where left off  	

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
		
    	wfi 									// enter low power mode
    	b main									// loop main
    	
    	
    	
    	
    	
    	
    	
    	


