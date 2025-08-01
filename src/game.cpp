#include "game.h"

Game::Game() : m_isRunning(false), 
            m_window(nullptr), 
            m_renderer(nullptr), 
            m_lastTick(0), 
            m_deltaTime(0.0) {

}

Game::~Game() {
    clean();
}

bool Game::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    m_window = SDL_CreateWindow(
        title,
        width,
        height,
        0
    );

    if (m_window == nullptr) {
        SDL_Log("Window could not created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }
    
    SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    m_renderer = SDL_CreateRenderer(m_window, nullptr);

    if (m_renderer == nullptr) {
        SDL_Log("Rendere could not created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_isRunning = true;
    m_lastTick = SDL_GetPerformanceCounter();
    return true;
}

void Game::handleEvents() {
    m_input.update();

    if(m_input.isKeyDown(SDLK_ESCAPE)) {
        m_isRunning = false;
    }
}

void Game::update() {
    Uint64 currentTime = SDL_GetPerformanceCounter();
    m_deltaTime = (double)(currentTime - m_lastTick) * 1000 / (double)SDL_GetPerformanceFrequency() / 1000.0;
    m_lastTick = currentTime;
}

void Game::render() {
    SDL_RenderClear(m_renderer);

    SDL_RenderPresent(m_renderer);
}

void Game::clean() {
    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;
    }
    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
    SDL_Quit();
    m_isRunning = false;
}