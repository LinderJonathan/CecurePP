#include <iostream>
#include <string>
#include <vector>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "hasher.hpp"
#include "keyHandler.hpp"
#include "signHandler.hpp"
#include "fileUtils.hpp"
#include "graphics/windowHandler.hpp"


int main(int argc, char* argv[]) {

    windowHandler wh;
    wh.programLoop(); 

    return 0;
}