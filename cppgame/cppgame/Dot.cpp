#include "Dot.h"
#include <SDL.h>

Dot::Dot(float x, float y)
    : mPosX{ x }, 
    mPosY{ y }
{}

void Dot::render(SDL_Renderer* gRenderer) {
    //Show the dot
    SDL_Rect dotRect = { mPosX, mPosY, dotWidth, dotHeight };
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(gRenderer, &dotRect);
}
