#include "Dot.h"
#include <SDL.h>

Dot::Dot(float x, float y) :
    mPosX{ x }, 
    mPosY{ y }
{}

void Dot::handleEvent(const SDL_Event& e) {
    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        //Adjust the velocity
        switch (e.key.keysym.sym) {
        case SDLK_UP: mVelY -= maxVel; break;
        case SDLK_DOWN: mVelY += maxVel; break;
        case SDLK_LEFT: mVelX -= maxVel; break;
        case SDLK_RIGHT: mVelX += maxVel; break;
        }
    }
    //If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        //Adjust the velocity
        switch (e.key.keysym.sym) {
        case SDLK_UP: mVelY += maxVel; break;
        case SDLK_DOWN: mVelY -= maxVel; break;
        case SDLK_LEFT: mVelX += maxVel; break;
        case SDLK_RIGHT: mVelX -= maxVel; break;
        }
    }
}

void Dot::move(int SCREEN_WIDTH, int SCREEN_HEIGHT) {
       
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if (mPosX < 0) {
        mPosX -= mVelX;
        mPosX = 0;
    }
    else if (mPosX + dotWidth > SCREEN_WIDTH){
        mPosX -= mVelX;
        mPosX = SCREEN_WIDTH - dotWidth;
    }

    //Move the dot up or down
    mPosY += mVelY;

    if (mPosY < 0) {
        mPosY -= mVelY;
        mPosY = 0;
    }
    else if (mPosY + dotWidth > SCREEN_HEIGHT) {
        mPosY -= mVelY;
        mPosY = SCREEN_HEIGHT - dotWidth;
    }
}

void Dot::render(SDL_Renderer* gRenderer) {
    //Show the dot
    SDL_Rect dotRect = { mPosX, mPosY, dotWidth, dotHeight };
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(gRenderer, &dotRect);
}

bool Dot::checkCollision(const Dot& targetDot) {
    float pLeft{ mPosX };
    float pRight{ mPosX + dotWidth };
    float pTop{ mPosY };
    float pBottom{ mPosY + dotHeight };
    float tLeft{ targetDot.mPosX };
    float tRight{ targetDot.mPosX + targetDot.dotWidth };
    float tTop{ targetDot.mPosY };
    float tBottom{ targetDot.mPosY + targetDot.dotHeight };

    if (pRight > tLeft && pLeft < tRight && pBottom > tTop && pTop < tBottom) return true;
    return false;
}
