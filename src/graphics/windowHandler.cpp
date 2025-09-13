#include "windowHandler.hpp"

/**
 * @file    windowHandler.cpp
 * @brief   Handles main event loop window routing
 * 
 */

windowHandler::windowHandler() : window(NULL), renderer(NULL) {
    SDL_Init;

    // TODO: handle SDL_Createwindow return NULL case
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
bool windowHandler::getRunningState() { return running; }
void windowHandler::setRunningState(bool state) { running = state; }

void windowHandler::renderStartScreen() {

    const SDL_Rect quitButton = {200, 200, 200, 200};

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &quitButton);
    SDL_RenderFillRect(renderer, &quitButton);
    SDL_RenderPresent(renderer);
}

void windowHandler::close() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}