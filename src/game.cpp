#include "game.h"
#include "texture.h"
#include "ecs/transform_component.h"
#include "ecs/sprite_component.h"
#include "SDL3_image/SDL_image.h"

SDL_Renderer* Game::m_renderer = nullptr;

Game::Game() : m_isRunning(false),
            m_window(nullptr), 
            m_lastTick(0), 
            m_deltaTime(0.0) {

}

Game::~Game() {
    clean();
}

bool Game::init(const char* title, int width, int height, bool fullscreen) {
    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    m_window = SDL_CreateWindow(
        title,
        width,
        height,
        flags
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

    auto& newPlayer(manager.addEntity());

    newPlayer.addComponent<TransformComponent>(400.0f, 300.0f, 3.0f, 3.0f, 0.0f);

    SDL_Texture* playerTexture = Texture::loadTexture("../assets/player.png");
    newPlayer.addComponent<SpriteComponent>(playerTexture, 1);

    auto& sprite = newPlayer.getComponent<SpriteComponent>();
    sprite.setSize(64, 44);

    

    m_map = new Map();

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
    Uint64 currentTick = SDL_GetPerformanceCounter();
    m_deltaTime = (double)((currentTick - m_lastTick) * 1000 / (double)SDL_GetPerformanceFrequency()) / 1000.0;
    m_lastTick = currentTick;

    manager.update();
}

void Game::render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    m_map->drawMap();

    manager.draw();

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