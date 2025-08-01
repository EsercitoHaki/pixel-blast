#pragma once

#include "input.h"
#include <SDL3/SDL.h>

class Game {
public:
    Game();
    ~Game();

    bool init(const char* title, int width, int height);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool isRunning() const { return m_isRunning; };
private:
    bool m_isRunning = false;

    Input m_input;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    
    Uint64 m_lastTick;
    double m_deltaTime;
};