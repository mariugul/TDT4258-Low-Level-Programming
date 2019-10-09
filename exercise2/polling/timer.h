#ifndef __TIMER_H__		// HEADER GUARD
#define __TIMER_H__

int global_var;


void timer_init(uint16_t period);
void timer_set_prescaler();
void timer_set_period();
void timer_enable_interrupt();
void timer_start();

#endif
