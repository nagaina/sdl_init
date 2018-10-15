#include "common.hpp"

void logSDL(std::ostream& os, const std::string& s)
{
	os << s << " error:" << SDL_GetError() << std::endl;
}