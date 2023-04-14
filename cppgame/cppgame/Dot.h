#pragma once
#include <SDL.h>

//The dot that will be moving around on the screen
struct Dot {
    //The X and Y offsets of the dot
    float mPosX, mPosY;

    //The velocity of the dot
    float mVelX, mVelY;

    //Maximum axis velocity of the dot
    float maxVel;

    //The dimensions of the dot
    int dotWidth = 20;
    int dotHeight = 20;

    //Initializes the variables
    Dot(const float, const float);

    //Takes key presses and adjusts the dot's velocity
    void handleEvent(const SDL_Event& e);

    //Moves the dot
    void move(const int, const int);

    //Shows the dot on the screen
    void render(SDL_Renderer*);
};