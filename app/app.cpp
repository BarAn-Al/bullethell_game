#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entities/entities.h"
#include <iostream>

int main() {
    SDL_InitSubSystem(SDL_INIT_VIDEO);

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    window = SDL_CreateWindow(
        "bullethell_game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_FULLSCREEN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);    

    bool running = true;
    SDL_Event curEvent;
    Object character(10, 10, 2);
    character.w = 100;
    character.h = 100;
    while (running) {

        while (SDL_PollEvent(&curEvent)) {
            switch (curEvent.type) {
            case SDL_KEYDOWN:
                if (curEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    running = false;
                }
                break;
            case SDL_MOUSEMOTION:
                character.setX(curEvent.motion.x - character.w / 2);
                character.setY(curEvent.motion.y - character.h / 2);                
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 223, 232, 190, 100);
        SDL_RenderFillRect(renderer, &character);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }


    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}