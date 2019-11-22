#ifndef __FONT_H__
#define __FONT_H__

// Insert fonts here

// Display welcome text
	display_draw_frame(20, 20, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 5, WHITE);
	
	
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

#endif