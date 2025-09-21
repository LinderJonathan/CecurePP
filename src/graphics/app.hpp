#pragma once

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
 
#define WINDOW_HEIGHT                   600
#define WINDOW_WIDTH                    800
#define WINDOW_FLAGS_DEFAULT            SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
#define RENDERER_FLAGS_DEFAULT          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

#define FONT_PATH_1                     "utils/graphics/fonts/BoldPixels.ttf"

class app
{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TTF_Font *font;
        bool running;

    public:
        app();
        ~app();

        void programLoop();
        bool getRunningState();
        void setRunningState(bool state);
        void renderStartScreen();
        void close();
};