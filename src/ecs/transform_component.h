#pragma once

#include "component.h"
#include "common.h"

class TransformComponent : public Component {
public:
    Vector2 position;
    Vector2 scale;
    float rotation;

    TransformComponent(float x = 0, float y = 0, float scaleX = 1.0f, float scaleY = 1.0f, float rot = 0.0f)
        : position(x, y), scale(scaleX, scaleY), rotation(rot) {}

    void translate(float dx, float dy) {
        position.x += dx;
        position.y += dy;
    }

    void setPosition(float x, float y) {
        position.x = x;
        position.y  = y;
    }

};