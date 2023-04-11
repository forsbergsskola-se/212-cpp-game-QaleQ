#pragma once
#include <SDL.h>

class Image
{
	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld{};

	//Wether Window Startup was successful
	bool success;
public:
	Image(const char*);
	~Image();
	bool wasSuccessful() { return success; }
	SDL_Surface* getResource() { return gHelloWorld; };
};

