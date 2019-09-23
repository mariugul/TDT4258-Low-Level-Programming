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
	
	    // MACROS
	    CMU_BASE 		 	 = 0x400c8000 		// base address
	    CMU_HFPERCLKEN0 	 = 0x044			// offset from base
		CMU_HFPERCLKEN0_GPIO = 13				// bit to enable GPIO
	    
	        
	    // load CMU base address
	    ldr r1, =CMU_BASE
	    
	    // load current value of HFPERCLK ENABLE
	    ldr r2, [r1, #CMU_HFPERCLKEN0]	
	    
	    // set bit for GPIO clk
	    mov r3, #1								// move 1 into r3
	    lsl r3, r3, #CMU_HFPERCLKEN0_GPIO		// create the GPIO clk enable mask
	    orr r2, r2, r3							// OR the mask with the current values so
	    										// the settings are not lost
	    
	    // store the new value in CMU_HFPERCLKEN0
	    str r2, [r1, #CMU_HFPERCLKEN0]
	    
	    
	    
	/**SET HIGH DRIVE STRENGTH (20mA pins)**/ 
	   	
	   	// MACROS
	   	GPIO_BASE    = 0x40006000
	   	GPIO_PA_CTRL = 0x000         // therefore not needed
	   	HIGH_DRIVE   = 0x2
	  	
	   	
	   	// load base address
	   	ldr r1, =GPIO_BASE
	   	
	   	// load the HIGH drive value
	   	ldr r2, =HIGH_DRIVE
	   	
	   	// store HIGH drive
	   	str r2, [r1]
	   	
	   	
	   	
	/**SET PINS 8-15 to OUTPUT**/
		
		// MACROS
		GPIO_PA_MODEH = 0x008
		SET_PINS 	  = 0x55555555
					
		// load base address
	   	ldr r1, =GPIO_BASE
	   	
	   	// set bits for GPIO_BASE
	   	ldr r3, =SET_PINS
	   	
	   	// store new value in GPIO_BASE
	   	str r3, [r1, #GPIO_PA_MODEH]
	   	
	   	
	   	
    /**SET PINS 0-7 to INPUT**/
		
		// MACROS
		GPIO_PC_MODEL = 0x04c
		SET_PINS 	  = 0x33333333
					
		// load base address
	   	ldr r1, =GPIO_BASE
	   	
	   	// set bits for GPIO_BASE
	   	ldr r3, =SET_PINS
	   	
	   	// store new value in GPIO_BASE
	   	str r3, [r1, #GPIO_PC_MODEL]



	/**ENABLE INTERNAL PULL-UP**/
   	
		// MACROS
		GPIO_PC_DOUT = 0x054
		SET_PINS 	  = 0xff
					
		// load base address
	   	ldr r1, =GPIO_BASE
	   	
	   	// set bits for GPIO_BASE
	   	ldr r3, =SET_PINS
	   	
	   	// store new value in GPIO_BASE
	   	str r3, [r1, #GPIO_PC_DOUT]
	   	
	   
	
	
	/**ENABLE INTERRUPTS**/

	/**SET GPIO_EXTIPSELL**/

	// MACROS
	GPIO_EXTIPSELL = 0x100
	SET_PINS 	  = 0x22222222
				
	// load base address
   	ldr r1, =GPIO_BASE
   	
   	// set bits for GPIO_BASE
   	ldr r3, =SET_PINS
   	
   	// store new value in GPIO_BASE
   	str r3, [r1, #GPIO_EXTIPSELL]
   	
  	
   	/**SET GPIO_EXTIFALL and GPIO_EXTIRISE and GPIO_IEN**/

   	// MACROS
	GPIO_EXTIFALL = 0x10c
	GPIO_EXTIRISE = 0x108
	GPIO_IEN      = 0x110
	
   	// set bits for GPIO_BASE
   	mov r3, #0xFF
   
   	// store new value in GPIO_BASE
   	str r3, [r1, #GPIO_EXTIFALL]
   	str r3, [r1, #GPIO_EXTIRISE]
   	str r3, [r1, #GPIO_IEN]

 
 	

	ISERO    = 0XE000e100
	
	// load base address
	ldr r1, =ISERO

	// set bits for GPIO_BASE
	movw r3, #0x802	// Set pins
	   	
	// store new value in GPIO_BASE
	str r3, [r1]



   	
   	/** ENABLE ENERGY MODE **/ 
	
	// MACROS
	EMU_BASE = 0x400C6000
	EMU_CTRL = 0x000	
	SCR_BASE = 0xE000ED10	
	
	// Enable energy mode 2

	ldr r0, =EMU_BASE
	mov r1, #0
	str r1, [r0]
	
	ldr r0, =SCR_BASE
	mov r1, #1
	lsl r1, #2
	str r1, [r0]
	
	ldr r0, =EMU_BASE
	mov r1, #0
	str r1, [r0]
	
	ldr r0, =EMU_BASE
	mov r1, #0
	lsl r1, #1
	str r1, [r0]
	
	ldr r0, =0x028 // load CMU_LFCLKSEL
	mov r1, #0
	mov r2, #0
	lsl r1, r1, #16
	lsl r1, r2, #4
	str r1, [r0]
	

	
	
	
	// INITIALIZE LEDS AS OFF
	//Load input
	mov r0, #0xFF
	
	// Load GPIO_BASE
	ldr r1, =GPIO_PA_BASE
		
	//Shift to the left 8 positions
	lsl r0, r0, #8
		
	// store new value
	str r0, [r1, #GPIO_DOUT]
	  	
	
	b main 		// jump to main
	
	/////////////////////////////////////////////////////////////////////////////
	//
  	// GPIO handler (LEDs are GPIO 8-15 of PortA)
  	// The CPU will jump here when there is a GPIO interrupt
	//
	/////////////////////////////////////////////////////////////////////////////
	
        .thumb_func
gpio_handler:  

	GPIO_PA_DOUT  = 0x00C  			//Offset for setting led light
	GPIO_PC_DIN   = 0x064			//Offset for reading the imput
	LEDS_OFF      = 0x0000ff00
	LEDS_ON	      = 0xffff00ff
	GPIO_IFC	  = 0x11c
	GPIO_IF 	  = 0x114

	// load base address
	ldr r1, =GPIO_BASE
	
	//Load input
	ldr r0, [r1,#GPIO_PA_DOUT]

	//Shift to the left 1 positions
	lsl r0, r0, #1

	// store new value
	// ldr r3, =LEDS_ON
	str r0, [r1, #GPIO_PA_DOUT]  
	
	#Cleaning interrupt:
	ldr r0, [r1,#GPIO_IF]
	str r0, [r1,#GPIO_IFC]
	
	
	bx lr  // branch back to link register  	

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
		
    	wfi 		// low power mode
    	b main


