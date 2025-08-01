#pragma once

#include "input.h"
#include <SDL3/SDL.h>

class Player {
public:
    Player(SDL_Renderer* renderer, int x, int y, float speed);
    ~Player();

    void update();
    void render();

    void setInputHandler(Input* input) {
        m_input = input;
    }
private:
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    SDL_FRect m_rect;
    SDL_Color m_color;
    float m_speed;
    Input* m_input;
};