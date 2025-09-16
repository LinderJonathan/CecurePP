#include "widget.hpp"

button::button(
        int x,
        int y,
        int width,
        int height,
        const std::string &lbl,
        std::function<void()> cb) : 
        label(lbl), 
        callback(cb),
        rect{x, y, width, height}{
            // TODO: initialize color as well
        }

button::~button(){}

void button::render(SDL_Renderer *renderer, buttonTheme theme) {

    // Render outline
    SDL_SetRenderDrawColor(
        renderer,
        theme.outlineColor.r,
        theme.outlineColor.g,
        theme.outlineColor.b,
        theme.outlineColor.alpha
    );
    SDL_RenderDrawRect(renderer, &rect);

    // Render fill
    SDL_SetRenderDrawColor(
        renderer,
        theme.bgColor.r,
        theme.bgColor.g,
        theme.bgColor.b,
        theme.bgColor.alpha
    );
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);

    // Render text 
    SDL_SetRenderDrawColor(
        renderer,
        theme.textColor.r,
        theme.textColor.g,
        theme.textColor.b,
        theme.bgColor.alpha
    )
}

void handleEvent() {}