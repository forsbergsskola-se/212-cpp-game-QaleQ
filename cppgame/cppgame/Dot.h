#pragma once
#include <SDL.h>

//The dot that will be moving around on the screen
class Dot {
    //The X and Y offsets of the dot
    float mPosX, mPosY;

    //The velocity of the dot
    float mVelX, mVelY;

    //Maximum axis velocity of the dot
    float maxVel;
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;

    //Initializes the variables
    Dot(float, float);

    //Takes key presses and adjusts the dot's velocity
    void handleEvent(SDL_Event& e);

    //Moves the dot
    void move(int, int);

    //Shows the dot on the screen
    void render(SDL_Renderer*);
};