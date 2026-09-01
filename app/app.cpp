#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
        0
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);    

    bool running = true;
    SDL_Event curEvent;
    while (running) {

        while (SDL_PollEvent(&curEvent)) {
            switch (curEvent.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            
            case SDL_KEYDOWN:
                running = false;
                break;

            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 223, 232, 190, 100);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }


    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}