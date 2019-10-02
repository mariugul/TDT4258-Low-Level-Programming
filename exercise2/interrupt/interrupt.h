#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__


void nvic_init();	// Enable interrupts

void __attribute__ ((interrupt)) TIMER1_IRQHandler ();		// TIMER1 interrupt handler 
void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler ();	// GPIO even pin interrupt handler 
void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler ();	// GPIO odd pin interrupt handler 


#endif
