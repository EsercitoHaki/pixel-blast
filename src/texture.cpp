#include "texture.h"
#include "game.h"
#include <SDL3_image/SDL_image.h>

SDL_Texture* Texture::loadTexture(const char* texture) {
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::m_renderer, tempSurface);
    SDL_DestroySurface(tempSurface);

    return tex;
}

void Texture::draw(SDL_Texture* tex, SDL_FRect src, SDL_FRect dest) {
    SDL_RenderTexture(Game::m_renderer, tex, &src, &dest);
}