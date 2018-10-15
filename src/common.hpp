#ifndef LE_SDL_COMMON_HPP
#define LE_SDL_COMMON_HPP

#include <SDL.h>

#include <iostream>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const std::string ICON_PATH = "";

void logSDL(std::ostream& os, const std::string& s);

#endif