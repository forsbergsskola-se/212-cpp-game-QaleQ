#include <SDL.h>
#include <stdio.h>
#include "Dot.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

int main(int argc, char* args[]) {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL) {
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            }
            else {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize the dot
                Dot dot;

                //Main loop flag
                bool quit = false;

                //Event handler
                SDL_Event e;

                //While application is running
                while (!quit) {
                    //Handle events on queue
                    while (SDL_PollEvent(&e) != 0) {
                        //User requests quit
                        if (e.type == SDL_QUIT) {
                            quit = true;
                        }

                        //Handle input for the dot
                        dot.handleEvent(e);
                    }

                    //Move the dot
                    dot.move(SCREEN_WIDTH, SCREEN_HEIGHT);

                    //Clear screen
                    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
                    SDL_RenderClear(gRenderer);

                    //Render objects
                    dot.render(gRenderer);

                    //Update screen
                    SDL_RenderPresent(gRenderer);
                }
            }
        }
    }

    //Free resources and close SDL
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();

    return 0;
}