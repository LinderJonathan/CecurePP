#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "widget.hpp"
 
#define WINDOW_HEIGHT                   600
#define WINDOW_WIDTH                    800
#define WINDOW_FLAGS_DEFAULT            SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
#define RENDERER_FLAGS_DEFAULT          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC


class app
{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TTF_Font *font;
        bool running;
        std::vector<std::unique_ptr<widget>> widgets;

        // TODO: widgets should be a member of app class

    public:
        app();
        ~app();

        void programLoop();
        bool getRunningState();
        void setRunningState(bool state);
        void setActiveState(std::vector<int> activeWidgets);
        void renderStartScreen();
        void close();
};