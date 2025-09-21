#include "app.hpp"
#include "widget.hpp"
#include <direct.h>   // for _getcwd on Windows


/**
 * @file    app.cpp
 * @brief   Handles main event loop window routing
 * 
 */

app::app() : window(NULL), renderer(NULL) {

    SDL_Init;
    window = SDL_CreateWindow(
        "CecurePP: Cecure Cigning",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        WINDOW_FLAGS_DEFAULT
    );
    if (!window) {
        std::cout << "Unnable to create window: " << SDL_GetError() << "\n";
        SDL_Quit();
    }

    renderer = SDL_CreateRenderer(window, -1,  RENDERER_FLAGS_DEFAULT);
    if (!renderer) {
        std::cout << "Unnable to create renderer: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    TTF_Init();
    font = TTF_OpenFont(FONT_PATH_1, 18);
    if (!font) {
        std::cout << "could not find font: " << TTF_GetError() <<  "\n";
    }
    running = true;
}

app::~app() { close(); }

void app::programLoop() {

    // TODO: figure out how to build up different windows
    
    // TODO: figure out how to iterate through widgets.

    button testButton(0, 0, BUTTON_WIDTH_CONFIG_1, BUTTON_HEIGHT_CONFIG_1, "test", nullptr, BUTTON_THEME_1);
    testButton.render(renderer, BUTTON_THEME_1, font);
    
    while (running) {
        SDL_Event event;
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        
        default:
            break;
        }
    }
}

bool app::getRunningState() { return running; }
void app::setRunningState(bool state) { running = state; }
void app::close() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}