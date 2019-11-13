#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "colors.h" // Defines the color codes


void display_init();
void display_refresh();
void display_draw_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
void display_add_snake();
void display_game_over();
void display_start_game();
void display_snake_food();
void display_set_background(uint8_t color);

#endif