#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <functional>
#include <string>

#define FONT_PATH_1                             "utils/graphics/fonts/BoldPixels.ttf"

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

#define BUTTON_FONTSIZE_12                      12
#define BUTTON_FONTSIZE_16                      16
#define BUTTON_FONTSIZE_18                      18
#define BUTTON_FONTSIZE_24                      24
#define BUTTON_FONTSIZE_36                      36
#define BUTTON_FONTSIZE_48                      48


struct color {
    int r, g, b, alpha;
};

struct buttonTheme {
    SDL_Color bgColor;
    SDL_Color outlineColor;
    SDL_Color textColor;
};

// TODO: refactor to use SDL_Color instead
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

    void render(SDL_Renderer *renderer, buttonTheme theme, TTF_Font *font);
    void handleEvent(SDL_Event *event);
};