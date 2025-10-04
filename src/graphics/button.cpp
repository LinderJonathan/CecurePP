#include "button.hpp"

button::button(
    int x,
    int y,
    int w,
    int h,
    int fontSize,
    const char *id,
    std::function<void()> cb,
    widgetTheme theme
) : 
    widget(x,y,w,h, id, theme),
    font(TTF_OpenFont(FONT_PATH_1, fontSize)),
    callback(cb)
    {

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
    
    SDL_Surface *surfaceLabel = TTF_RenderText_Solid(font, identifier, theme.textColor);
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
    
    if (event->type == SDL_MOUSEBUTTONDOWN && !isPressed) {
        isPressed = true;
    }
    if (event->type == SDL_MOUSEMOTION && isPressed) {
        SDL_Point p = {event->motion.x, event->motion.y};
        if (!SDL_PointInRect(&p, &rect)) {
            isPressed = false;
        }

    }
    if (event->type == SDL_MOUSEBUTTONUP && isPressed) {
        callback();
        isPressed = false;
    }
}