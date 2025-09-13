#pragma once

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>

// TODO: defines for width, height and so on for the windows
 
#define WINDOW_HEIGHT                   600
#define WINDOW_WIDTH                    800
#define WINDOW_FLAGS_DEFAULT            SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
#define RENDERER_FLAGS_DEFAULT          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

// TODO: dimension defines for buttons
class windowHandler
{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running;

    public:
        windowHandler();
        ~windowHandler();

        bool getRunningState();
        void setRunningState(bool state);
        void renderStartScreen();
        void close ();

};