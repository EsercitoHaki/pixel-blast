#include "player.h"

Player::Player(SDL_Renderer* renderer, int x, int y, float speed) 
                : m_renderer(renderer), m_speed(speed), m_input(nullptr) {
    m_rect = {
        (float)x, (float)y, 50, 50
    };

    m_texture = Texture::loadTexture("../assets/player.png");

    if (m_texture == nullptr) {
        SDL_Log("Could not load player texture! Will use rectangle instead.");
    }
}

Player::~Player() {
    
}

void Player::update(double deltaTime) {
    if (m_input == nullptr) {
        return;
    }

    if (m_input->isKeyDown(SDLK_UP) || m_input->isKeyDown(SDLK_W)) {
        m_rect.y -= m_speed * deltaTime;
    }
    if (m_input->isKeyDown(SDLK_DOWN) || m_input->isKeyDown(SDLK_S)) {
        m_rect.y += m_speed * deltaTime;
    }
    if (m_input->isKeyDown(SDLK_LEFT) || m_input->isKeyDown(SDLK_A)) {
        m_rect.x -= m_speed * deltaTime;
    }
    if (m_input->isKeyDown(SDLK_RIGHT) || m_input->isKeyDown(SDLK_D)) {
        m_rect.x += m_speed * deltaTime;
    }

    int window_w, window_h;
    SDL_GetWindowSize(SDL_GetRenderWindow(m_renderer), &window_w, &window_h);

    if (m_rect.x < 0) m_rect.x = 0;
    if (m_rect.y < 0) m_rect.y = 0;
    if (m_rect.x + m_rect.w > window_w) m_rect.x = (float)window_w - m_rect.w;
    if (m_rect.y + m_rect.h > window_h) m_rect.y = (float)window_h - m_rect.h;
}

void Player::render() {
    SDL_RenderTexture(m_renderer, m_texture, nullptr, &m_rect);
}