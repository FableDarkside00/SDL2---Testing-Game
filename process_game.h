#include <stdio.h>
#include "square.h"
#include "SDL2/SDL.h"

int processEvents(SDL_Window *window)
{
    //Inicializa os eventos no objeto event
    SDL_Event event;

    //Define 'termino' = 0
    int done = 0;

    //Define uma altura padrao em square.y
    
    
    int *square_ptrx = &square.x;
    int *square_ptry = &square.y;
    
     
    //Valor imutavel 0-1 para seta cima 
    static int upPressed;
        
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
            
            //Switch para os eventos de teclado
            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    {
                        done = 1;
                        break;
                    }

                    case SDLK_F11:
                    {
                        SDL_SetWindowFullscreen(window, 0);
                        break;
                    }

                    case SDLK_UP:
                    {
                        upPressed = 1;

                        break;
                    }

                    case SDLK_RIGHT:
                    {
                        if (*square_ptrx <= display.w)
                        {
                            *square_ptrx += 10; 
                        }

                        break;
                    }

                    case SDLK_LEFT:
                    {
                        if (*square_ptrx >= 5)
                        {
                            *square_ptrx -= 10; 
                        }

                        break;
                    }
                
                }
            }

            break;

            case SDL_KEYUP:
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                    {
                        upPressed = 0;
                        break;
                    }
                }
            }    
            break;
        }
    
    }

    //Sistema de pulo simples:

    *square_ptry = display.h/1.2;
    if (upPressed == 1) {
        *square_ptry -= 125;
    }

    return done;
}
