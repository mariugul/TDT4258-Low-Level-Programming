#include "display.h"

#define FBFD
#define FB_REFRESH 0x4680

void display_init(uint8_t background_color)
{
    display_set_background(background_color);
}

void display_refresh()
{
    ioctl1(FBFD, FB_REFRESH, &rect);
}

void display_draw_rect(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
    rect.dx = x;
    rect.dy = y;
    rect.width = w;
    rect.height = h;
}

void display_add_snake() {}

void display_game_over() {}

void display_start_game() {}

void display_snake_food() {}

void display_set_background(uint8_t color)
{

}