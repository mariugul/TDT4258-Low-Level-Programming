#ifndef __TIMER_H__ // HEADER GUARD
#define __TIMER_H__

int global_var;

void timer_init();
void timer_enable_clock();
void timer_set_prescaler();
void timer_set_period();
void timer_enable_interrupt();
void timer_start();
void timer_stop();
void timer_le_start();
void timer_le_stop();

#endif
