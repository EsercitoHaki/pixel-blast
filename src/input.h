#pragma once

#include <SDL3/SDL.h>
#include <map>

class Input {
public:
    Input();
    ~Input();

    void update();
    bool isKeyDown(SDL_Keycode key) const;
private:
    std::map<SDL_Keycode, bool> m_keyStates;
};