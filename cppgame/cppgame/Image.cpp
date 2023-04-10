#include "Image.h"
#include <cstdio>
#include <SDL.h>

bool Image::loadMedia(const char* path)
{
	//Load splash image
	gHelloWorld = SDL_LoadBMP(path);
	if (!gHelloWorld)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return false;
	}

	return true;
}

Image::~Image() {
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = nullptr;
}
