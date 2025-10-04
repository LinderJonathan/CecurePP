#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <functional>
#include <string>
#include "widget.hpp"
#include "themes.hpp"

class button : public widget
{
private:

public:

    TTF_Font *font;
    std::function<void()> callback;

    button(
        int x, int y, 
        int w, int h, 
        int fontSize,
        const char *id, 
        std::function<void()> callback,
        widgetTheme theme
    );
    ~button();

    void render(SDL_Renderer *renderer) override;
    void handleEvent(SDL_Event *event) override;
};