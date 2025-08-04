#pragma once
#include "../game.h"
#include "component.h"
#include "common.h"
#include <SDL3/SDL.h>

class SpriteComponent : public Component {
public:
    SDL_Texture* texture;
    SDL_FRect srcRect;
    SDL_FRect desRect;
    bool flipX, flipY;
    float alpha;
    SDL_Color tint;
    int zOrder;

    SpriteComponent(SDL_Texture* tex = nullptr, int z = 0)
        : texture(tex), flipX(false), flipY(false), alpha(1.0f),
            tint{255, 255, 255, 255}, zOrder(z) {
        if (texture) {
            float w, h;
            SDL_GetTextureSize(texture, &w, &h);
            srcRect = {0, 0, w, h};
            desRect = {0, 0, w, h};

            SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
        }
    }
    
    void setTexture(SDL_Texture* tex) {
        if (tex) {
            float w, h;
            SDL_GetTextureSize(tex, &w, &h);
            srcRect = {0, 0, w, h};
            desRect = {0, 0, w, h};
            SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_NEAREST);
        }
    }

    void draw() override {
        if (entity->hasComponent<TransformComponent>()) {
            auto& transform = entity->getComponent<TransformComponent>();
            desRect.x = transform.position.x;
            desRect.y = transform.position.y;

            desRect.w = srcRect.w * transform.scale.x; 
            desRect.h = srcRect.h * transform.scale.y;

            SDL_RenderTexture(Game::m_renderer, texture, &srcRect, &desRect);
        }
    }

    void setSrcRect(float x, float y, float w, float h) {
        srcRect = {x, y, w, h};
    }

    void setSize(float w, float h) {
        desRect.w = w;
        desRect.h = h;
    }
};