#include <stdio.h>
#include "square.h"
#include "SDL2/SDL.h"

int processEvents(SDL_Window *window)
{
    square.x = 220;

    //Inicializa os eventos no objeto event
    SDL_Event event;

    //Define 'termino' = 0
    int done = 0;
        
    //SDL_PollEvent() Checa a ocorrencia e manutenção da ordem de eventos
    while (SDL_PollEvent(&event))
    {
        //Switch para os tipos de evento
        switch (event.type)
        {
            case SDL_WINDOWEVENT_CLOSE:
            {    
                if (window)
                {
                    SDL_DestroyWindow(window);
                    window = NULL;
                }
            }
            break;
            
            case SDL_KEYDOWN:
            {
                //Switch para os eventos de teclado
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                {
                    done = 1;
                    break;
                }
                case SDLK_RIGHT:
                {
                    square.x += 5;

                    break;
                }
                case SDLK_LEFT:
                {
                    square.x -= 5;
                    break;
                }
                break;
                }
            }
            break;
        }    
    }
    posx = square.x;
    return done;
}
