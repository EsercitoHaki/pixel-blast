#include <iostream>
#include <SDL3/SDL.h>

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_Log("Failed to initialize SDL: ", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (window == nullptr) {
        SDL_Log("Window could not created!, SDL_Error: ", SDL_GetError());
        return 1;
    }

    bool quit = false;
    SDL_Event e;
    SDL_zero( e );

    while (quit == false) {
        while (SDL_PollEvent(&e) == true)
        {
            if (e.type == SDL_EVENT_QUIT){
                quit = true;
            }
        }
    }

    window = nullptr;
    SDL_Quit();

    return 0;
}