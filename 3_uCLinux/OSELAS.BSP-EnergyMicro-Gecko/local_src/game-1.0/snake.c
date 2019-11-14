// Includes
//---------------------------------------------------
#include "snake.h"

// Variables
//---------------------------------------------------
bool alive;
int seed;
int food_pos_x;
int food_pos_y;
int snake_lenght = 1;

// Function Definitions
//---------------------------------------------------
void snake_grow(direction dir) 
{
    // Choose action from the direction to grow
    switch (dir)
    {
    case left:
        break;
    
    case right:
        break;
    case up:
        break;
    case down:
        break;
    default:
        break;
    }
}

void snake_put_food() 
{
    //srand(); //to set the seed for rand function
    if (alive)
    {
        food_pos_x = rand() % 32; //pseudo-random number between 0 and 31
        food_pos_y = rand() % 24; //pseudo-random number between 0 and 23
        display_draw_rect(food_pos_x, food_pos_y, SNAKE_WIDTH, SNAKE_HEIGHT, GREEN);
    }
}

void snake_update() 
{

}

