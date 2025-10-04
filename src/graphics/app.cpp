
/**
 * @file    app.cpp
 * @brief   Handles main event loop window routing
 * 
 */

#include "app.hpp"
#include "button.hpp"
#include <vector>
#include <memory>

app::app() : window(NULL), renderer(NULL) {
    SDL_Init;
    TTF_Init();

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

    font = TTF_OpenFont(FONT_PATH_1, WIDGET_FONTSIZE_48);
    if (!font) {
        std::cout << "could not find font: " << TTF_GetError() <<  "\n";
    }

    button quitButton(0, 0, WIDGET_WIDTH_CONFIG_2, WIDGET_HEIGHT_CONFIG_2, WIDGET_FONTSIZE_36, "QUIT", [this]
                      { setRunningState(false); }, WIDGET_THEME_1);

    widgets.push_back(std::make_unique<button>(quitButton));

    running = true;
}

app::~app() { close(); }

void app::programLoop() {

    // TODO: figure out how to build up different windows

    widgets[0]->render(renderer);

    while (running) {
        int x, y;   // TODO: make these variables GLOBAL instead to save mouse position
        SDL_Event event;
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&x, &y);
            /*
            FIRST ATTEMPT: iterate over all widgets.
            * Check if mouse clicked inside their boundary.
            * It so, call widget.eventHandle
            */
            
            for (int i = 0; i < widgets.size(); i++) {
                if (
                    x > widgets[i]->rect.x && x < widgets[i]->rect.x + widgets[i]->rect.w &&
                    y > widgets[i]->rect.y && y < widgets[i]->rect.y + widgets[i]->rect.h
                ) {
                    widgets[i]->handleEvent(&event);
                }
            }
                /*
                SECOND ATTEMPT: different widgets have overlapping boundaries.
                * Check to see which is "on top"? "Top-most" wins
                */
            break;
        case SDL_MOUSEBUTTONUP:
            SDL_GetMouseState(&x, &y);
            for (int i = 0; i < widgets.size(); i++) {

                if (
                    x > widgets[i]->rect.x && x < widgets[i]->rect.x + widgets[i]->rect.w &&
                    y > widgets[i]->rect.y && y < widgets[i]->rect.y + widgets[i]->rect.h
                ) {
                    widgets[i]->handleEvent(&event);
                }
            }

            break;
        
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x, &y);
            for (int i = 0; i < widgets.size(); i++) {

                if (widgets[i]->isPressed) {
                    widgets[i]->handleEvent(&event);
                }
                if (
                    x > widgets[i]->rect.x && x < widgets[i]->rect.x + widgets[i]->rect.w &&
                    y > widgets[i]->rect.y && y < widgets[i]->rect.y + widgets[i]->rect.h
                ) {
                    widgets[i]->handleEvent(&event);
                }
            }

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