#pragma once
#include "Dot.h"
#include <vector>

struct Player : public Dot
{
	Player(const float a, const float b) : Dot(a, b) { };

	//public std::vector<IPositionObserver> positionObservers;
	
	//Check collision with target
	bool checkCollision(const Dot&);

};

