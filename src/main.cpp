#include <iostream>

#include "le_event.hpp"
#include "le_graphic.hpp"
#include <SDL.h>

int main(int argc, char** argv)
{
	le_event& e = le_event::get();
	
	le_graphic& g = le_graphic::get();
	if (g.init()) {
		g.load_image("C:\\Users\\elen\\Desktop\\my_projects\\sdl_begin\\SDL_maze_game\\SDL_maze_game\\cat.png");
		e.porcess_events();
		g.release();
	}
	return 0; // SDL main must return void value
}