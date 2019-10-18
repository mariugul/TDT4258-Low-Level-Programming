#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <stdbool.h>

extern int song_buff[100][2];
extern bool song_finish;

void interrupt_init();                                  // Enable interrupts
void __attribute__((interrupt)) TIMER1_IRQHandler();    // TIMER1 interrupt handler
void __attribute__((interrupt)) GPIO_EVEN_IRQHandler(); // GPIO even pin interrupt handler
void __attribute__((interrupt)) GPIO_ODD_IRQHandler();  // GPIO odd pin interrupt handler
void __attribute__((interrupt)) LETIMER0_IRQHandler();  // Low energy timer interrupt handler
void gpio_handler();
void TIF_clear();  // Timer Interrupt Flag clear
void GIF_clear();  // Gpio Interrupt Flag clear
void LEIF_clear(); // Low Energy Interrupt Flag clear

#endif
