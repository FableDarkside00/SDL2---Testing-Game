#include "SDL2/SDL.h"
#include <stdio.h>
/// @brief 
typedef struct
{
    int x, y;
    short life;
    char *name;
} Man;

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
                break;
                }
            }
            break;
        }    
    }

    return done;
}

void doRender(SDL_Renderer *renderer)
{
    //Definir a cor do render
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    //Limpar tela (para azul)
    SDL_RenderClear(renderer);

    //Definir a cor de desenho para branco
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //Desenha o objeto (Quadrado)
    SDL_Rect rect = {220,140,200,200};
    SDL_RenderFillRect(renderer, &rect);

    //Mostrando o desenho na tela
    SDL_RenderPresent(renderer);

}

int main(int argc, char const *argv[])
{

    SDL_Window *window;             //Declara uma janela
    SDL_Renderer *renderer;         //Declara a render

    SDL_Init(SDL_INIT_EVERYTHING);  //Inicia o SDL2

    //Cria uma janela com as seguintes definições
    window = SDL_CreateWindow("Jogo",                   //Nome da Janela
                               SDL_WINDOWPOS_UNDEFINED, //Posição inicial x
                               SDL_WINDOWPOS_UNDEFINED, //Posição Inicial y
                               640,                     //Largura em pixels
                               480,                     //Altura em pixels
                               0                        //Flags
    );
    
    //Cria o render(desenho), usando a GPU
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    //Valor para abrir a janela em processEvents
    int done = 0;
         
    //Enquanto não terminar
    while (!done){

        //Função para processar eventos.
        done = processEvents(window);
    
        //Renderiza os elementos no display
        doRender(renderer);

        //100 milisegundos delay para presevar o pc
        SDL_Delay(100);

    }

    //Fecha e destroi a janela
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();    
    
    return 0;

}
