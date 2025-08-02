#pragma once

#include "input.h"
#include "player.h"
#include "map.h"
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

    static SDL_Renderer* m_renderer;
private:
    bool m_isRunning = false;

    Input m_input;

    SDL_Window* m_window;
    
    Uint64 m_lastTick;
    double m_deltaTime;

    Player* m_player;
    Map* m_map;
};