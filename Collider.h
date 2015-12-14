#pragma once
#include "SDL/include/SDL.h"
#include "GameObject.h"
class Collider
{
public:
	Collider(){}
	~Collider(){}
	
	GameObject *parent;
	SDL_Rect rect;
	SDL_Color color;
	bool deleteme;
};

