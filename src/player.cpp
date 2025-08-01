#include "player.h"

Player::Player(SDL_Renderer* renderer, int x, int y, float speed) 
                : m_renderer(renderer), m_speed(0.0), m_input(nullptr) {
    m_rect = {
        (float)x, (float)y, 50, 50
    };

    m_color = { 255, 0, 0, 255 };
}

Player::~Player() {
    
}

void Player::update() {

}

void Player::render() {
    SDL_SetRenderDrawColor(m_renderer, m_color.r, m_color.g, m_color.b, m_color.a);
    SDL_RenderFillRect(m_renderer, &m_rect);
}