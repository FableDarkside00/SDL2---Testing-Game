#include "SDL2/SDL.h"

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
