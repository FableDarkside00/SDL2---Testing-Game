#include "SDL2/SDL.h"
#include "square.h"

void doRender(SDL_Renderer *renderer)
{
    int *square_ptrx = &square.x;
    int *square_ptry = &square.y;

    //Definir a cor do render
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    //Limpar tela (para azul)
    SDL_RenderClear(renderer);

    //Definir a cor de desenho para branco
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //Desenha o objeto (Quadrado)
    SDL_Rect rect = {*square_ptrx,*square_ptry,50,50};
    SDL_RenderFillRect(renderer, &rect);

    //Mostrando o desenho na tela
    SDL_RenderPresent(renderer);

}
