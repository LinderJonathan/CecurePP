#include "windowHandler.hpp"

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
    // TODO: handle SDL_Createrenderer return NULL case

    renderer = SDL_CreateRenderer(window, -1,  RENDERER_FLAGS_DEFAULT);
}

windowHandler::~windowHandler() {
    close();
}

void windowHandler::drawWindow() {
    
}

void windowHandler::close() {
    // TODO: de-allocate some window structs???
    SDL_DestroyWindow(window);
}