#pragma once
#include "Image.h"
class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};

	//The surface contained by the window
	SDL_Surface* screenSurface{};

	//Wether Window Startup was successful
	bool success;

	//Starts up SDL and creates window
public:
	Window(int, int);
	~Window();

	bool wasSuccessful() { return success; }

	void render(Image*);
};

