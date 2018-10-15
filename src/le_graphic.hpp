#ifndef LE_SDL_GRAPHIC_HPP
#define LE_SDL_GRAPHIC_HPP

#include <SDL_Video.h>

#include <string>

class SDL_Renderer;
class SDL_Texture;

class le_graphic
{
public:
	static le_graphic& get();

	bool init();
	void release();

	void load_image(const std::string&);

	SDL_Renderer* get_renderer() const { return m_renderer; }
	SDL_Texture* get_texture() const { return m_texture; }

private:
	le_graphic();

	le_graphic(const le_graphic&) = delete;
	le_graphic& operator=(const le_graphic&) = delete;

private:
	static le_graphic* m_instance;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
};

#endif