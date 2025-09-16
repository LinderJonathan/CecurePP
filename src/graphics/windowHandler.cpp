#include "windowHandler.hpp"
#include "widget.hpp"

/**
 * @file    windowHandler.cpp
 * @brief   Handles main event loop window routing
 * 
 */

windowHandler::windowHandler() : window(NULL), renderer(NULL) {
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
    running = true;
}

windowHandler::~windowHandler() { close(); }

void windowHandler::programLoop() {

    // TODO: figure out how to build up different windows
    
    // TODO: figure out how to iterate through widgets.

    button testButton(0, 0, BUTTON_WIDTH_CONFIG_1, BUTTON_HEIGHT_CONFIG_1, "Test", NULL);
    testButton.render(renderer, BUTTON_THEME_1);
    
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

bool windowHandler::getRunningState() { return running; }
void windowHandler::setRunningState(bool state) { running = state; }
void windowHandler::close() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}