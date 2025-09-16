#pragma once

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
 
#define WINDOW_HEIGHT                   600
#define WINDOW_WIDTH                    800
#define WINDOW_FLAGS_DEFAULT            SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
#define RENDERER_FLAGS_DEFAULT          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

class windowHandler
{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running;

    public:
        windowHandler();
        ~windowHandler();

        void programLoop();
        bool getRunningState();
        void setRunningState(bool state);
        void renderStartScreen();
        void close ();
};