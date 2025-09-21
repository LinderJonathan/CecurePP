#include <iostream>
#include <string>
#include <vector>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "hasher.hpp"
#include "keyHandler.hpp"
#include "signHandler.hpp"
#include "fileUtils.hpp"
#include "graphics/app.hpp"


int main(int argc, char* argv[]) {

    app app;   // MUST BE INITIALIZED BEFORE ANY CALLS TO SDL APIs
    app.programLoop(); 

    return 0;
}