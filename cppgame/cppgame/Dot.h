#pragma once
#include <SDL.h>

//The dot that will be moving around on the screen
struct Dot {
    //The X and Y offsets of the dot
    float mPosX, mPosY;

    //The velocity of the dot
    float mVelX{}, mVelY{};

    //Maximum axis velocity of the dot
    float maxVel{ 0.1f };

    //The dimensions of the dot
    int dotWidth{ 20 };
    int dotHeight{ 20 };

    //Initializes the variables
    Dot(const float, const float);

    //Shows the dot on the screen
    void render(SDL_Renderer*);
};