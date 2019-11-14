#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <stdbool.h>
#include "colors.h"

int main(int argc, char *argv[])
{
	printf("Welcome to Snake!!\n");

	// Initializers
	display_init(BLACK);

	// Test screen
	display_draw_rect(100, 100, 60, 10, WHITE);
	display_draw_rect(160, 100, 10, 60, WHITE);
	display_draw_rect(80, 160, 90, 10, WHITE);
	display_draw_rect(80, 230, 10, 150, WHITE);
  
    /*
	while (true)
	{
		// Code
	}
    */


	exit(EXIT_SUCCESS);
}