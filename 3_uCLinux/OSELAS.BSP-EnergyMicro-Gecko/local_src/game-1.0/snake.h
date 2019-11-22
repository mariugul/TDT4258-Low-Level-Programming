/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *                         Snake                         *
 *                                                       *
 *  These are the functions for controlling the snake.   *
 *														 *
 * By: Marius C. K. Gulbrandsen                          *
 *     Antoni Climent Munoz                              *
 *     Andrea Mazzoli							         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Header Guard
//---------------------------------------------------
#ifndef __SNAKE_H__
#define __SNAKE_H__

// Includes
//---------------------------------------------------
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "colors.h" 
#include "defines.h"
#include "display.h"

// Definitions 
//---------------------------------------------------
#define SNAKE_WIDTH 10
#define SNAKE_HEIGHT 10
#define SNAKE_SIZE (10 * 10)
#define SNAKE_GROUND (SCREEN_SIZE / SNAKE_SIZE)

// Typedefs
//---------------------------------------------------
typedef enum {
    left, 
    right, 
    up,
    down,
    none,
}direction_t;

// Function Prototypes
//---------------------------------------------------
void snake_draw();
void snake_remove();
void snake_get_food();
bool snake_check_game_over();
void snake_init(bool first_init);
void snake_update_head_direction();
void snake_update(direction_t bottonPressed);
void snake_update(direction_t bottonPressed);
#endif