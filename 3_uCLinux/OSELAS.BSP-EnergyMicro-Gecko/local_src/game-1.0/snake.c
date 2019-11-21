// Includes
//---------------------------------------------------
#include "snake.h"

// Variables
//---------------------------------------------------
int food_pos_x; //From 0 to 39
int food_pos_y; //From 0 to 29
int pos_snake_x[300]; //From 0 to 39
int pos_snake_y[300]; //From 0 to 29
int snake_lenght;

direction_t head_direction;

// Function Definitions

void removeSnake(){
    for(int i=0; i<snake_lenght;++i){
        display_draw_rect(pos_snake_x[i]*8, pos_snake_y[i]*8, 8, 8, BLACK);
    }
    display_draw_rect(food_pos_x*8,food_pos_y*8,8,8,BLACK);
}

void snake_init(bool firstInit){
    
    if(!firstInit) removeSnake();
    //display_draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
    pos_snake_x[0] = 20;
    pos_snake_y[0] = 15;
    pos_snake_x[1] = 21;
    pos_snake_y[1] = 15;
    pos_snake_x[2] = 22;
    pos_snake_y[2] = 15;
    head_direction = left;
    snake_lenght = 3;

    food_pos_x = 10;
    food_pos_y = 10;

    display_draw_rect(food_pos_x*8,food_pos_y*8,8,8,RED);

    //for(int i=0;i<snake_lenght;++i){
    //  display_draw_rect(pos_snake_x[i]*8,pos_snake_y[i]*8,8,8,GREEN);
    //}
}

void getMoreFood(){
    food_pos_x = rand() % 37 + 1; //pseudo-random number between 1 and 38
    food_pos_y = rand() % 24 + 1; //pseudo-random number between 1 and 25
    display_draw_rect(food_pos_x*8,food_pos_y*8,8,8,RED);
}

void update_head_direction(direction_t bottonPressed){
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
}

bool check_game_over(){
    //Check if the snake is eating its tail:
    for(int i = 1; i < snake_lenght;++i){
        if(pos_snake_x[i] == pos_snake_x[0] && pos_snake_y[i] == pos_snake_y[0]){
            //It means that it is eating its tail
            printf("Snake has eaten its tail!");
            return true;
        }
    }

    //Check if snake out of boundaries
    if(pos_snake_x[0] == 1 || pos_snake_x[0] == 38 || pos_snake_y[0] == 0 || pos_snake_y[0] == 25){
        return true;
    }
    return false;
}

void snake_update(direction_t bottonPressed) 
{

    if(check_game_over()){
        snake_init(false);
        display_border();
    }
    else{
        //Update the head direction of the snake, depending on the input
        update_head_direction(bottonPressed);
        //Update position of the snake:
        //Erase tail of the snake
        //printf("Black1 x:%d, y: %d\n",pos_snake_x[snake_lenght-1],pos_snake_y[snake_lenght-1]);
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
}

void snake_draw()
{
    for(int i=0; i<snake_lenght;++i){
        display_draw_rect(pos_snake_x[i]*8, pos_snake_y[i]*8, 8, 8, GREEN);
    }
}