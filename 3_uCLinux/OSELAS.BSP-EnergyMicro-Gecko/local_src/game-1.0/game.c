#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "display.h"
#include "colors.h"
#include "snake.h"

#define _BSD_SOURCE
#define LEFT 0xfe
#define RIGHT 0xfb
#define UP 0xfd
#define DOWN 0xf7

int main(int argc, char *argv[])
{
	printf("Welcome to Snake!!\n");

	// Initializers
	display_init(BLACK);

	snake_init(true);
	display_border();

	//Opening driver file for later usage
	char buff[2];
	printf("Im going to try to read the buttons state:");
	int fd = open("/dev/gamePad",O_RDONLY);
	if(fd < 0){
		printf("error opening the device!");
	}

	//Mian loop of the game
	while(1){
		usleep(100000);
		read(fd,buff,2);
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
	}
	close(fd);
	exit(EXIT_SUCCESS);
}