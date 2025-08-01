#include "game.h"
#include <iostream>
#include <SDL3/SDL.h>

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
    Game game;

    if (game.init("Pixel Blast", SCREEN_WIDTH, SCREEN_HEIGHT)) {
        while (game.m_isRunning) {
            game.update();
            game.render();
        }
    }
    else {
        std::cerr << "Failed to initialize game!" << std::endl;
        return 1;
    }

    std::cerr << "Game exited cleanly." << std::endl;

    return 0;
}