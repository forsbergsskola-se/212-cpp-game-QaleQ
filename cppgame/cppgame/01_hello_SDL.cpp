#include <SDL.h>
#include <stdio.h>
#include "Dot.h"
#include "Observer.h"
#include <stdlib.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

int SCORE = 0;
const int MAX_SCORE = 5;

int main(int argc, char* args[]) {
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
            //Increment score and terminate game loop if MAX_SCORE is reached
            if (++SCORE == MAX_SCORE) break;

            //Move target 
            target.mPosX = rand() % (SCREEN_WIDTH - target.DOT_WIDTH);
            target.mPosY = rand() % (SCREEN_HEIGHT - target.DOT_HEIGHT);
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