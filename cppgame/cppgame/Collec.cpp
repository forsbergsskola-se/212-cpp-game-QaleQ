#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include "Dot.h"
#include "Observer.h"
#include <stdlib.h>

//Screen dimension constants
const int SCREEN_WIDTH{ 640 };
const int SCREEN_HEIGHT{ 480 };

//The window we'll be rendering to
SDL_Window* gWindow{};

//The window renderer
SDL_Renderer* gRenderer{};

int SCORE{};

int main() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    //Create window
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!gWindow) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!gRenderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
        
    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);

    //Initialize the player
    Dot player{ 0, 0 };

    Dot target{ 300, 300 };

    //Event handler
    SDL_Event e;

    //While application is running
    while (true) {
        //Handle events on queue
        if (SDL_PollEvent(&e)) {
            //User requests quit
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) { break; }

            //Handle input for the dot
            player.handleEvent(e);
        }

        //Check if target is reached
        if (Observer::checkCollision(player, target)) {
            ++SCORE;

            //Move target 
            target.mPosX = rand() % (SCREEN_WIDTH - target.dotWidth);
            target.mPosY = rand() % (SCREEN_HEIGHT - target.dotHeight);

            player.dotHeight *= 1.15;
            player.dotWidth *= 1.15;

            if (player.dotHeight > SCREEN_HEIGHT || player.dotWidth > SCREEN_WIDTH) break;
        }

        //Move the dot
        player.move(SCREEN_WIDTH, SCREEN_HEIGHT);

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(gRenderer);

        //Render objects
        player.render(gRenderer);
        target.render(gRenderer);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();

    return 0;
}