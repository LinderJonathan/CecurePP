#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class widget
{
private:
    
public:
    SDL_Rect rect;
    
    // TODO: take from button class
    //widgetTheme theme;
    //const char *label;

    widget(int x, int y, int w, int h) {
        rect = {x, y, w, h};
    }

    virtual ~widget() = default;

    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void handleEvent(SDL_Event *event) = 0;
};

