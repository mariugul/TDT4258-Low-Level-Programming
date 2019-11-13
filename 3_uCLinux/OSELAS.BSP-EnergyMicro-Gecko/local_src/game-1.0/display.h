#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "colors.h" // Defines the color codes


void display_init(uint16_t background_color);
void display_refresh(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
void display_draw_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);
void display_init();
void display_add_snake();
void display_game_over();
void display_start_game();
void display_snake_food();
void display_set_background(uint16_t color);

#endif