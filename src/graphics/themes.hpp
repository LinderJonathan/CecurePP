#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define FONT_PATH_1                             "utils/graphics/fonts/BoldPixels.ttf"


#define WIDGET_HEIGHT_CONFIG_1                  50
#define WIDGET_WIDTH_CONFIG_1                   100
#define WIDGET_HEIGHT_CONFIG_2                  100
#define WIDGET_WIDTH_CONFIG_2                   200  

#define WIDGET_BACKGROUND_COLOR_R_THEME_1       255
#define WIDGET_BACKGROUND_COLOR_G_THEME_1       52    
#define WIDGET_BACKGROUND_COLOR_B_THEME_1       3    
#define WIDGET_BACKGROUND_COLOR_ALPHA_THEME_1   255    
#define WIDGET_OUTLINE_COLOR_R_THEME_1          0
#define WIDGET_OUTLINE_COLOR_G_THEME_1          0
#define WIDGET_OUTLINE_COLOR_B_THEME_1          0
#define WIDGET_OUTLINE_COLOR_ALPHA_THEME_1      255
#define WIDGET_TEXT_COLOR_R_THEME_1             0
#define WIDGET_TEXT_COLOR_G_THEME_1             0
#define WIDGET_TEXT_COLOR_B_THEME_1             0
#define WIDGET_TEXT_COLOR_ALPHA_THEME_1         255

#define WIDGET_FONTSIZE_12                      12
#define WIDGET_FONTSIZE_16                      16
#define WIDGET_FONTSIZE_18                      18
#define WIDGET_FONTSIZE_24                      24
#define WIDGET_FONTSIZE_36                      36
#define WIDGET_FONTSIZE_48                      48

struct widgetTheme {
    SDL_Color bgColor;
    SDL_Color outlineColor;
    SDL_Color textColor;
};

inline widgetTheme WIDGET_THEME_1 = {
    {
        WIDGET_BACKGROUND_COLOR_R_THEME_1,
        WIDGET_BACKGROUND_COLOR_G_THEME_1,
        WIDGET_BACKGROUND_COLOR_B_THEME_1,
        WIDGET_BACKGROUND_COLOR_ALPHA_THEME_1
    },
    {
        WIDGET_OUTLINE_COLOR_R_THEME_1,
        WIDGET_OUTLINE_COLOR_G_THEME_1,
        WIDGET_OUTLINE_COLOR_B_THEME_1,
        WIDGET_OUTLINE_COLOR_ALPHA_THEME_1
    },
    {
        WIDGET_TEXT_COLOR_R_THEME_1,
        WIDGET_TEXT_COLOR_G_THEME_1,
        WIDGET_TEXT_COLOR_B_THEME_1,
        WIDGET_TEXT_COLOR_ALPHA_THEME_1
    }
};