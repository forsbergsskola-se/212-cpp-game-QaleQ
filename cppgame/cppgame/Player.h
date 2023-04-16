#pragma once
#include "Dot.h"
#include <vector>

struct Player : public Dot
{
	Player(const float a, const float b) : Dot(a, b) { };

	//public std::vector<IPositionObserver> positionObservers;

	//Takes key presses and adjusts the player's velocity
	void handleEvent(const SDL_Event& e);
	
	//Check collision with target
	bool checkCollision(const Dot&);

	//Moves the dot
	void move(const int, const int);
};
