#pragma once

#include <SDL2/SDL.h>
#include <functional>
#include <string>

#define BUTTON_HEIGHT_CONFIG_1                  50
#define BUTTON_WIDTH_CONFIG_1                   100
#define BUTTON_HEIGHT_CONFIG_2                  100
#define BUTTON_WIDTH_CONFIG_2                   200  

#define BUTTON_BACKGROUND_COLOR_R_THEME_1       255
#define BUTTON_BACKGROUND_COLOR_G_THEME_1       52    
#define BUTTON_BACKGROUND_COLOR_B_THEME_1       3    
#define BUTTON_BACKGROUND_COLOR_ALPHA_THEME_1   255    
#define BUTTON_OUTLINE_COLOR_R_THEME_1          0
#define BUTTON_OUTLINE_COLOR_G_THEME_1          0
#define BUTTON_OUTLINE_COLOR_B_THEME_1          0
#define BUTTON_OUTLINE_COLOR_ALPHA_THEME_1      255
#define BUTTON_TEXT_COLOR_R_THEME_1             0
#define BUTTON_TEXT_COLOR_G_THEME_1             0
#define BUTTON_TEXT_COLOR_B_THEME_1             0
#define BUTTON_TEXT_COLOR_ALPHA_THEME_1         255

struct color {
    int r, g, b, alpha;
};

struct buttonTheme {
    color bgColor;
    color outlineColor;
    color textColor;
};

inline buttonTheme BUTTON_THEME_1 = {
    {
        BUTTON_BACKGROUND_COLOR_R_THEME_1,
        BUTTON_BACKGROUND_COLOR_G_THEME_1,
        BUTTON_BACKGROUND_COLOR_B_THEME_1,
        BUTTON_BACKGROUND_COLOR_ALPHA_THEME_1
    },
    {
        BUTTON_OUTLINE_COLOR_R_THEME_1,
        BUTTON_OUTLINE_COLOR_G_THEME_1,
        BUTTON_OUTLINE_COLOR_B_THEME_1,
        BUTTON_OUTLINE_COLOR_ALPHA_THEME_1
    },
    {
        BUTTON_TEXT_COLOR_R_THEME_1,
        BUTTON_TEXT_COLOR_G_THEME_1,
        BUTTON_TEXT_COLOR_B_THEME_1,
        BUTTON_TEXT_COLOR_ALPHA_THEME_1
    }
};

class button
{
private:
    /* data */
public:

    SDL_Rect rect;
    const std::string &label;
    std::function<void()> callback;
    struct buttonTheme theme;

    button(
        int x,
        int y,
        int width,
        int height,
        const std::string &lbl,
        std::function<void()> callback
    );
    ~button();

    void render(SDL_Renderer *renderer, buttonTheme theme);
    void handleEvent(SDL_Event *event);
};