#ifndef square_h
#define square_h
#include "SDL2/SDL.h"
typedef struct
{
    int x, y;
    short life;
    char *name;
} Square;

Square square;

SDL_DisplayMode display;
#endif