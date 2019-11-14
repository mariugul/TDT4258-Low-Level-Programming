#include "display.h"
#include <stdint.h>

#define FB_REFRESH 0x4680
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCREEN_SIZE 320*240


// Error handler
#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

// Variables
int fb; 				   // Framebuffer communication
uint16_t* map;			   // Pointer to the display memory map 
struct fb_copyarea screen; // The area to update the screen
struct fb_var_screeninfo vinfo;



void display_init(uint16_t color)
{
	// Open framebuffer communication and error check
	fb = open("/dev/fb0", O_RDWR);
	if (fb == -1) {
    	handle_error("Error on open");
    }           

    // Save pointer to memory map and error check
	map = (uint16_t*)mmap(NULL, SCREEN_SIZE*2, PROT_READ | PROT_WRITE, MAP_SHARED, fb, 0);
	if (map == MAP_FAILED) {
        handle_error("Error on mmap");
    }

    // Set background color
    display_set_background(color);
	

}

void display_refresh(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	// Refresh screen
    screen.dx = x;
    screen.dy = y; 
    screen.width = w;
    screen.height = h;

    ioctl(fb, FB_REFRESH, &screen);
}

void display_draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{	
	// Variable calculations
	uint16_t start_pos     = SCREEN_WIDTH * y + x;
	uint16_t width_offset  = start_pos    + w;
	//uint16_t heigth_offset = start_pos    + SCREEN_WIDTH * h;  // Not used
	//uint16_t end_pos       = width_offset + SCREEN_WIDTH * h;  // Not used

	// Draw square
	for (int i = 0; i < h; i++) {

		uint16_t row_offset = i * SCREEN_WIDTH;
		for (int j = start_pos; j < width_offset; j++) 
			map[j+row_offset] = color;
	}

	// Refresh the new part of the screen
    display_refresh(x, y, w, h);
}

void display_add_snake() {}

void display_game_over() {}

void display_start_game() {}

void display_snake_food() {}

void display_set_background(uint16_t color) {
	display_draw_rect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT, color);
}

void display_close()
{
	munmap(map, SCREEN_SIZE);
	close(fb);
}