#ifndef square_h
#define square_h

#include "stdio.h"
typedef struct
{
    int x, y;
    short life;
    char *name;
} Square;

Square square;

extern int *square_ptrx = &square.x;
extern int *square_ptry = &square.y;
extern int screen_h = 1080, screen_w = 1920;
#endif