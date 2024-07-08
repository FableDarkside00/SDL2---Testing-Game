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

    if(SDL_GetCurrentDisplayMode(0, &display) != 0){
        SDL_Log("Failure to get the display mode: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    printf("| w: %d | h: %d \n", display.w, display.h);
    int heigth = display.h;
    int width = display.w;


    //Cria uma janela com as seguintes definições
    window = SDL_CreateWindow("Jogo",                   //Nome da Janela
                               SDL_WINDOWPOS_CENTERED, //Posição inicial x
                               SDL_WINDOWPOS_CENTERED, //Posição Inicial y
                               width,                     //Largura em pixels
                               heigth,                     //Altura em pixels
                               0                             //Flags
    );
    
    //Cria o render(desenho), usando a GPU
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        SDL_Log("Unable to render by error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    //Valor para abrir a janela em processEvents
    int done = 0;

    int *square_ptrx = &square.x;
    int *square_ptry = &square.y;
         
    //Enquanto não terminar
    while (!done){

        //Função para processar eventos.
        done = processEvents(window);
    
        //Renderiza os elementos no display
        doRender(renderer);

        //100 milisegundos delay para presevar o pc
        SDL_Delay(100);

    printf("| posy: %d|\n\a", *square_ptry);
    printf("| posx: %d|\n\a", *square_ptrx);
    }


    //Fecha e destroi a janela
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();    
    
    return 0;

}