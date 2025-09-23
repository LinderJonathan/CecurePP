#include "button.hpp"

button::button(
    int x,
    int y,
    int w,
    int h,
    int fontSize,
    const char *lbl,
    std::function<void()> cb,
    buttonTheme theme
) : 
    widget(x,y,w,h),
    font(TTF_OpenFont(FONT_PATH_1, fontSize)),
    label(), 
    callback(cb),
    theme(theme){

}

button::~button(){

}

void button::render(SDL_Renderer *renderer) {

    // Render outline
    SDL_SetRenderDrawColor(
        renderer,
        theme.outlineColor.r,
        theme.outlineColor.g,
        theme.outlineColor.b,
        theme.outlineColor.a
    );
    SDL_RenderDrawRect(renderer, &rect);

    // Render fill
    SDL_SetRenderDrawColor(
        renderer,
        theme.bgColor.r,
        theme.bgColor.g,
        theme.bgColor.b,
        theme.bgColor.a
    );
    SDL_RenderFillRect(renderer, &rect);
    
    // Render surface from 
    SDL_Surface *surfaceLabel = TTF_RenderText_Solid(font, label, theme.textColor);
    SDL_Rect Message_rect;
    Message_rect.x = rect.x + (rect.w - surfaceLabel->w) / 2; 
    Message_rect.y = rect.y + (rect.h - surfaceLabel->h) / 2;
    Message_rect.h = surfaceLabel->h;
    Message_rect.w = surfaceLabel->w;
    SDL_Texture *textureLabel = SDL_CreateTextureFromSurface(renderer, surfaceLabel);
    
    SDL_RenderCopy(renderer, textureLabel, NULL, &Message_rect);
    SDL_RenderPresent(renderer);
}

void button::handleEvent(SDL_Event *event) {
    callback();
}