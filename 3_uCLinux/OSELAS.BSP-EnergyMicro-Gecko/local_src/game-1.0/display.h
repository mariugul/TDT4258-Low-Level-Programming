/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *                  Display "driver"                     *
 *                                                       *
 *  This is the display drawing functions that is used   *
 *  to display figures and text on the screen.           *
 *														 *
 * By: Marius C. K. Gulbrandsen                          *
 *     Antoni Climent Munoz                              *
 *     Andrea Mazzoli							         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Header Guard
//---------------------------------------------------
#ifndef __DISPLAY_H__
#define __DISPLAY_H__

// Includes
//---------------------------------------------------
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "colors.h" // Defines the color codes
#include "defines.h"

// Function Prototypes
//---------------------------------------------------
void display_close();
void display_border();
void display_refresh_all();
void display_init(uint16_t color);
void display_set_background(uint16_t color);
void display_refresh(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void display_draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void display_draw_frame(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t frame_thickness, uint16_t color);

#endif