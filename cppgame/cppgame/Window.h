#pragma once
#include "Image.h"
class Window
{
	//The window we'll be rendering to
	SDL_Window* gWindow{};

	//The surface contained by the window
	SDL_Surface* gScreenSurface{};

	//Wether Window Startup was successful
	bool success;

	//Starts up SDL and creates window
public:
	Window(int, int);
	~Window();

	bool wasSuccessful() { return success; }

	void render(Image& image);
};

