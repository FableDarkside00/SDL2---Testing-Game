#include "SDL2/SDL.h"

int processEvents(SDL_Window *window)
{
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
                    break;
                }
                case SDL_FINGERUP:
                break;
                }
            }
            break;
        }    
    }

    return done;
}
