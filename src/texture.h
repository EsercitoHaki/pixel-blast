#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

class Texture {
public:
    static SDL_Texture* loadTexture(const char* fileName);
    static void draw(SDL_Texture* texture, SDL_FRect src, SDL_FRect dest);
};