#include "input.h"

Input::Input() {

}

Input::~Input() {

}

void Input::update() {
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_EVENT_QUIT) {
            m_keyStates[SDLK_ESCAPE] = true;
        } else if (e.type == SDL_EVENT_KEY_DOWN) {
            m_keyStates[e.key.key] = true;
        } else if (e.type == SDL_EVENT_KEY_UP) {
            m_keyStates[e.key.key] = false;
        }
    }
}

bool Input::isKeyDown(SDL_Keycode key) const {
    auto it = m_keyStates.find(key);
    if (it != m_keyStates.end()) {
        return it->second;
    }

    return false;
}