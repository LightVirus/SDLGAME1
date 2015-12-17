#pragma once
#include "GameObject.h"
#include "Collider.h"
#include "Application.h"
#include "ModuleRender.h"
#include "Globals.h"
#include "SDL/include/SDL.h"

class Player :
	public GameObject
{
public:
	Player();
	~Player();

	Collider* col = NULL;
	SDL_Rect TextureRect;
	SDL_Rect Rect;
	SDL_Texture* MainTex = NULL;
	
	void SetPlayer(Collider* collider, SDL_Rect cuadro, SDL_Rect cuadrotex, SDL_Texture* Tex);
	bool RenderGameObj();
};

