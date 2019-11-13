#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <stdbool.h>
#include "colors.h"

int main(int argc, char *argv[])
{
	printf("Hello World, I'm game!\n");
	display_init(WHITE);
	display_draw_rect(2, 2, 2, 2, WHITE);

	exit(EXIT_SUCCESS);
}