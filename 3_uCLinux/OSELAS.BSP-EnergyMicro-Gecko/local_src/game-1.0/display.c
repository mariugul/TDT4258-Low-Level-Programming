#include "display.h"
#include <stdint.h>

#define FBFD
#define FB_REFRESH 0x4680
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240


// Variables
int fd; 				 // Framebuffer communication
uint16_t* map;
struct fb_copyarea rect; // The area to update the screen
struct fb_var_screeninfo vinfo;


// Hold the screen pixels and their color
uint16_t screen_pixels [320][240] = {};
uint16_t screen [SCREEN_WIDTH * SCREEN_HEIGHT] = {}


void display_init(uint16_t background_color)
{
	// Open framebuffer communication
	fd = open("/dev/fb0", O_RDWR);

	// Set backgrond
    display_set_background(background_color);
}

void display_refresh(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
	// Refresh screen
    rect.dx = x;
    rect.dy = y; 
    rect.width = w;
    rect.height = h;

    ioctl(fd, FB_REFRESH, &rect);
}

void display_draw_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color)
{	

	int screensize_bytes = SCREEN_HEIGHT * SCREEN_WIDTH * vinfo.bits_per_pixel / 8;
	map = (uint16_t*)mmap(NULL, screensize_bytes, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	// Offset variables
	uint8_t width_offset = x + w;
	uint8_t heigth_offset = y + h;
	
	// Calculate the pixels
	for(int i = x; i < width_offset; i++)
	{
		for(int j = y; j < heigth_offset; j++)
			screen_pixels[x][y] = color;
	}

	// Test array 
	for (int i = x; i < ; i++)
		map[i] = color;

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