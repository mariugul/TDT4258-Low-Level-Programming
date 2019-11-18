// Includes
//---------------------------------------------------
#include "snake.h"

// Variables
//---------------------------------------------------
bool alive, food_eaten;
int seed;
int food_pos_x; //From 0 to 39
int food_pos_y; //From 0 to 29
int pos_snake_x[30]; //From 0 to 39
int pos_snake_y[30]; //From 0 to 29
int snake_lenght = 3;

direction_t head_direction;

// Function Definitions
//---------------------------------------------------
void snake_grow(direction_t dir) 
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
        food_pos_x = rand() % 38 + 1; //pseudo-random number between 0 and 31
        food_pos_y = rand() % 28 + 1; //pseudo-random number between 0 and 23
        display_draw_rect(food_pos_x, food_pos_y, SNAKE_WIDTH, SNAKE_HEIGHT, GREEN);
    }
}

void snake_init(){
    //display_draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
    pos_snake_x[0] = 20;
    pos_snake_y[0] = 15;
    pos_snake_x[1] = 21;
    pos_snake_y[1] = 15;
    pos_snake_x[2] = 22;
    pos_snake_y[2] = 15;
    head_direction = right;

    food_pos_x = 10;
    food_pos_y = 10;

    display_draw_rect(food_pos_x*8,food_pos_y*8,8,8,RED);

    for(int i=0;i<snake_lenght;++i){
        display_draw_rect(pos_snake_x[i]*8,pos_snake_y[i]*8,8,8,GREEN);
    }
}

void getMoreFood(){
    food_pos_x = rand() % 38 + 1; //pseudo-random number between 1 and 39
    food_pos_y = rand() % 28 + 1; //pseudo-random number between 1 and 29
    display_draw_rect(food_pos_x*8,food_pos_y*8,8,8,RED);
}

void snake_update(direction_t bottonPressed) 
{
    switch (head_direction) //Change head direction if needed
    {
        case up:
        case down:
            switch (bottonPressed)
            {
                case right:
                    head_direction = right;
                    break;
                case left:
                    head_direction = left;
                    break;
                default:
                    break;
            }
            break;
        
        case left:
        case right:
            switch (bottonPressed)
            {
                case up:
                    head_direction = up;
                    break;
                case down:
                    head_direction = down;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    //Update position of the snake:
    display_draw_rect(pos_snake_x[snake_lenght-1]*8,pos_snake_y[snake_lenght-1]*8,8,8,BLACK);
    
    //We will need the tail possition if the snake eats 
    int x_tail = pos_snake_x[snake_lenght-1];
    int y_tail = pos_snake_y[snake_lenght-1];

    //Update the position of each square that forms the snake
    for(int i = snake_lenght-1; i > 0;--i){
        pos_snake_x[i] = pos_snake_x[i-1];
        pos_snake_y[i] = pos_snake_y[i-1];
    }
    //Compute the position of the head, using its direction
    switch(head_direction){
        case left:
            --pos_snake_x[0];
            break;
        case right:
            ++pos_snake_x[0];
            break;
        case up:
            --pos_snake_y[0];
            break;
        case down:
            ++pos_snake_y[0];
            break;
        default:
            break;
    }

    //Check if snake is eating food
    if(food_pos_x == pos_snake_x[0] && food_pos_y == pos_snake_y[0]){
        //This means that it is eating
        ++snake_lenght;
        pos_snake_x[snake_lenght-1] = x_tail;
        pos_snake_y[snake_lenght-1] = y_tail;
        getMoreFood();
    }

}

void snake_draw()
{
    for(int i=0; i<snake_lenght;++i){
        display_draw_rect(pos_snake_x[i]*8, pos_snake_y[i]*8, 8, 8, GREEN);
    }
    
}

