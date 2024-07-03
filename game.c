#include <stdio.h>
#include "square.h"
#include "SDL2/SDL.h"
#include "process_game.h"
#include "render_game.h"

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