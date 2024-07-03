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
extern int posx;

#endif