#include "widget.hpp"

button::button(
    int x,
    int y,
    int width,
    int height,
    const char *lbl,
    std::function<void()> cb,
    buttonTheme theme
) : 
    label(lbl), 
    callback(cb),
    rect{x, y, width, height},
    theme(theme){

}

button::~button(){

}

void button::render(SDL_Renderer *renderer, buttonTheme theme, TTF_Font *font) {

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
    
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate 
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect
    // TODO: check stack overflow page
    SDL_Surface *surfaceLabel = TTF_RenderText_Solid(font, label, theme.textColor);
    SDL_Texture *textureLabel = SDL_CreateTextureFromSurface(renderer, surfaceLabel);
    SDL_RenderCopy(renderer, textureLabel, NULL, &rect);
    SDL_RenderPresent(renderer);
}

void handleEvent() {}