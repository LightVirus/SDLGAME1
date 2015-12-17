#pragma once
#include "Module.h"
#include "Application.h"
#include "GameObject.h"
#include "Player.h"
#include "Road.h"
#include "SDL/include/SDL_mixer.h"
#include "SDL/include/SDL_image.h"
#include "SDL/include/SDL_ttf.h"
#include <list>

class Application;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();
	bool fristtime;
	bool Start();
	update_status Update();
	void const GoSound();
	void ControlToPlayer(controls cont, bool state);
private:
	
	//Textures
	SDL_Texture* mainsprites = NULL;
	SDL_Texture* RectaMedBigTEX = NULL;
	SDL_Texture* mainui = NULL;
	TTF_Font* MainFont = NULL;

	//Music
	Mix_Music* music1 = NULL;

	//Sounds
	Mix_Chunk* effect1 = NULL;
	Mix_Chunk* effect2 = NULL;

	//Road
	Road RectMedBig;
	
	//GameObjects
	list<GameObject*> GOList;
	Player* MainPlayer;


	float x = 0.0f;
	float y = 0.0f;

	float xdir = 50.0f;
	float ydir = 50.0f;

	

};

