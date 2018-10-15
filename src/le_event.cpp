#include "le_event.hpp"
#include "le_graphic.hpp"

#include <SDL.h>
#include <SDL_events.h>

#include <iostream>

le_event* le_event::m_instance = 0;

le_event& le_event::get()
{
	if (m_instance == 0) {
		m_instance = new le_event();
	}
	return *m_instance;
}

void le_event::porcess_events()
{
	// event handler
	SDL_Event event;

	while (!m_quit) {
		// handle events on queue
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				m_quit = true;
			} else if (event.type == SDL_KEYDOWN) {
				m_quit = true;
			}
		}
		// render the scene
		le_graphic& g = le_graphic::get();
		SDL_Renderer* r = g.get_renderer();
		SDL_Texture* t = g.get_texture();
		SDL_RenderClear(r);
		SDL_RenderCopy(r, t, 0, 0);	
		SDL_RenderPresent(r);
		//SDL_Delay(2000);
	}
}