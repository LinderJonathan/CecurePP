#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "themes.hpp"

class widget
{
private:
    
public:

    SDL_Rect rect;    
    const char *identifier;
    widgetTheme theme;

    widget(int x, int y, int w, int h, const char *id, widgetTheme theme) {
        this->rect = {x, y, w, h};
        this->identifier = id;
        this->theme = theme;
    }

    virtual ~widget() = default;

    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void handleEvent(SDL_Event *event) = 0;
};

