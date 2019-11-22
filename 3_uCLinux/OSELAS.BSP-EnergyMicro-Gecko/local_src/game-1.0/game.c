// Define this before the <unistd> include for usleep()
//---------------------------------------------------
#define _BSD_SOURCE

// Includes
//---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <stdbool.h>
#include "colors.h"
#include <signal.h>
#include "snake.h"
#include <unistd.h>
#include <fcntl.h>

// Definitions
//---------------------------------------------------
#define LEFT 0xfe
#define RIGHT 0xfb
#define UP 0xfd
#define DOWN 0xf7
#define FRAME_THICK 5
#define SPEED 60000

#define MICRO_S 10000

// Variables
//---------------------------------------------------
int fd_gamepad;

// Prototypes
//---------------------------------------------------
void signal_handler(); // Prototype
void welcome_screen();

// Main
//---------------------------------------------------
int main(int argc, char *argv[])
{
	// Get rid of compiler warning for argc and *argv[] 
	char *prog = argv[0];
    (void)argc;

	printf("Welcome to Snake!!\n");

	// Enable interrupts
	signal(SIGIO, &signal_handler); /* sigaction() is better */
	//fcntl(STDIN_FILENO, F_SETOWN, getpid());
	//oflags = fcntl(STDIN_FILENO, F_GETFL);
	//fcntl(STDIN_FILENO, F_SETFL, oflags | FASYNC);

	// Initializers
	display_init(BLACK);
	welcome_screen();
	snake_init(true);

	//Opening driver file for later usage
	char buff[2];
	printf("Im going to try to read the buttons state:");
	fd_gamepad = open("/dev/gamePad",O_RDONLY);
	if(fd_gamepad < 0){
		printf("error opening the device!");
	}



	
	// Loop
	//---------------------------------------------------
	while(1){
		usleep(SPEED);
		read(fd_gamepad,buff, 2);
		switch (*buff)
		{
		    case RIGHT:
		    	printf("Going RIGHT\n");
		    	snake_update(right);
		        break;
		    
		    case LEFT:
		    	printf("Going LEFT\n");
		    	snake_update(left);
		        break;

		     case UP:
		    	printf("Going UP!\n");
		    	snake_update(up);
		        break;   
		    
		    case DOWN:
		    	printf("Going DOWN!\n");
		    	snake_update(down);
		        break;

		    default:
		    	printf("No dir change\n");
		    	snake_update(none);
	    }
	    snake_draw();

	    //if(snake_check_game_over())
	    	//welcome_screen();
	}
	
	
	close(fd_gamepad);
	exit(EXIT_SUCCESS);
}

void signal_handler()
{


}

void welcome_screen()
{
	display_set_background(BLACK);
	display_draw_frame(20, 20, 230, SCREEN_HEIGHT/2, 5, WHITE);
	display_draw_rect(26, 26, 224, SCREEN_HEIGHT/2 -5, BLUE);
	

	// Left
	display_draw_rect(80,    60,    5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-5,  60,    5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-10, 60,    5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-15, 60,    5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-20, 60,    5, 5, GREEN);

	// Down
	display_draw_rect(80-20, 60+5,  5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-20, 60+10, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-20, 60+15, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-20, 60+20, 5, 5, GREEN);

	// Right
	display_draw_rect(80-20, 60+20,  5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-15, 60+20,  5, 5, GREEN);
	usleep(MICRO_S);	
	display_draw_rect(80-10, 60+20,  5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-5,  60+20,  5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80,    60+20,  5, 5, GREEN);


	// Down
	display_draw_rect(80, 60+25,  5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80, 60+30, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80, 60+35, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80, 60+40, 5, 5, GREEN);

	// Left
	display_draw_rect(80,    60+40,    5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-5,  60+40,    5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-10, 60+40,    5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-15, 60+40,    5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80-20, 60+40,    5, 5, GREEN);
	/////////////////////////////////////////////////
	// N - Letter
	display_draw_rect(80+20, 60+40, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+20, 60+35, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+20, 60+30, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+20, 60+25, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+20, 60+20, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+20, 60+15, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+20, 60+10, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+20, 60+ 5, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+20, 60+ 0, 5, 5, GREEN);

	display_draw_rect(80+25, 60+0, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+30, 60+0, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+35, 60+0, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+40, 60+0, 5, 5, GREEN);

	display_draw_rect(80+40, 60+5, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+40, 60+10, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+40, 60+15, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+40, 60+20, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+40, 60+25, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+40, 60+30, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+40, 60+35, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+40, 60+40, 5, 5, GREEN);

	// E - Letter
	display_draw_rect(80+60, 60   , 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+60, 60+5 , 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+60, 60+10, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+60, 60+15, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+60, 60+20, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+60, 60+25, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+60, 60+30, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+60, 60+35, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+60, 60+40, 5, 5, GREEN);

	display_draw_rect(80+65, 60+40, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+70, 60+40, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+75, 60+40, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+80, 60+40, 5, 5, GREEN);

	display_draw_rect(80+65, 60+20, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+70, 60+20, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+75, 60+20, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+80, 60+20, 5, 5, GREEN);

	display_draw_rect(80+65, 60+0, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+70, 60+0, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+75, 60+0, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+80, 60+0, 5, 5, GREEN);

	// K-letter
	display_draw_rect(80+100, 60+0, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+100, 60+5, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+100, 60+10, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+100, 60+15, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+100, 60+20, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+100, 60+25, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+100, 60+30, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+100, 60+35, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+100, 60+40, 5, 5, GREEN);

	display_draw_rect(80+105, 60+20, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+110, 60+25, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+115, 60+30, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+120, 60+35, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+125, 60+40, 5, 5, GREEN);

	display_draw_rect(80+105, 60+20, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+110, 60+15, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+115, 60+10, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+120, 60+5, 5, 5, GREEN);
	usleep(MICRO_S);
	display_draw_rect(80+125, 60+0, 5, 5, GREEN);



	usleep(3000000);
	display_set_background(BLACK);
	display_border();
}



