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
    int posy = 860;
     
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
                    case SDLK_UP:
                    {
                        upPressed = 1;

                        break;
                    }

                    case SDLK_RIGHT:
                    {
                        if (*square_ptrx <= 1865)
                        {
                            *square_ptrx += 10; 
                        }else
                        {
                            square_ptrx += 0;
                        }

                        break;
                    }

                    case SDLK_LEFT:
                    {
                        if (*square_ptrx >= 5)
                        {
                            *square_ptrx -= 10; 
                        }else
                        {
                            square_ptrx -= 0;
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
    /*Ponteiro para y recebe a posição base (posy = 860). Para posy = 840; Se quando pressionar cima for true e a posição square.y for maior que 840 e menor que 890 retire 1 da posição (ir pra cima 1). 
    Se pra cima pressionado for true, a posição square.y tera o valor de posy (860 - 840) => sobe 20px
    '*/

    *square_ptry = posy; //860
    for (posy = 820; upPressed > 0 && *square_ptry > 840 && *square_ptry < 890; --posy) {
        if (upPressed == 1) {
            *square_ptry = posy;
        }
    }

    return done;
}
