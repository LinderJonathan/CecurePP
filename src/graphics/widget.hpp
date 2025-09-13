#pragma once

#include <SDL2/SDL.h>
#include <functional>
#include <string>

#define BUTTON_HEIGHT_CONFIG_1          50
#define BUTTON_WIDTH_CONFIG_1           100
#define BUTTON_HEIGHT_CONFIG_2          100
#define BUTTON_WIDTH_CONFIG_2           200  

struct buttonColor {
    int r, g, b
};

class button
{
private:
    /* data */
public:

    SDL_Rect rect;
    const std::string &label;
    std::function<void()> callback;

    button(
        int x,
        int y,
        int width,
        int height,
        buttonColor,
        const std::string &label,
        std::function<void()> callback
    );
    ~button();

    void render(SDL_Renderer *renderer);
    void handleEvent(SDL_Event *event);
};