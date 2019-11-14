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

// Definitions 
//---------------------------------------------------
#define SNAKE_WIDTH 10
#define SNAKE_HEIGHT 10
#define SNAKE_SIZE (10 * 10)
#define SNAKE_GROUND (SCREEN_SIZE / SNAKE_SIZE)

// Variables
//---------------------------------------------------
bool snake_position[SNAKE_GROUND] = {};

// Typedefs
//---------------------------------------------------
typedef enum {
    left, 
    right, 
    up,
    down
}direction;

// Function Prototypes
//---------------------------------------------------
void snake_grow();
void snake_put_food();
void snake_update();

#endif