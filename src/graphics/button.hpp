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
    /* data */
public:

    TTF_Font *font;
    const char *label;
    std::function<void()> callback;
    struct buttonTheme theme;


    button(
        int x,
        int y,
        int width,
        int height,
        int fontSize,
        const char *lbl,
        std::function<void()> callback,
        buttonTheme theme

    );
    ~button();

    void render(SDL_Renderer *renderer) override;
    void handleEvent(SDL_Event *event) override;
};