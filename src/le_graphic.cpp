#include "le_graphic.hpp"
#include "common.hpp"

#include <SDL_image.h>

le_graphic* le_graphic::m_instance = 0;

le_graphic& le_graphic::get()
{
	if (m_instance == nullptr) {
		m_instance = new le_graphic();
	}
	return *m_instance;
}

le_graphic::le_graphic()
{
}

bool le_graphic::init()
{
	bool s = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		logSDL(std::cout, "Video init");
		s = false;
	} else {
		// create window
		m_window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == nullptr) {
			logSDL(std::cout, "Create Winow");
			s = false;
		} else {
			m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (m_renderer == nullptr) {
				logSDL(std::cout, "Create Rnederer");
				s = false;
			} else {
				//Initialize renderer color 
				SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0xFF );
				// Init PNG loading
				int img_flags = IMG_INIT_PNG;
				if (!IMG_Init(img_flags) & img_flags) {
					logSDL(std::cout, "Init flags");
					s = false;
				}
			}
		}
	}
	return s;
}

void le_graphic::release()
{
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_texture = nullptr;
	m_window = nullptr;
	m_renderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}

void le_graphic::load_image(const std::string& path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface != nullptr) {
		m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
		//SDL_QueryTexture(m_texture, 0, 0, 0, 0);
		SDL_FreeSurface(surface);
	} else {
		logSDL(std::cout, "Image loead");
	}
}