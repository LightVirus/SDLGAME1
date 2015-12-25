#pragma once
#include "Module.h"
#include "Application.h"
#include "GameObject.h"
#include "Player.h"
#include "Road.h"
#include "Sector.h"
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
	float roadvel = 100.0f;
	//void ControlToPlayer(controls cont, bool state);

	Player* MainPlayer;
private:
	list<Sector> SectorsList;
	
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

	//Sector
	Sector SECTRectBig;
	
	//GameObjects
	list<GameObject*> GOList;
	


	float x = 0.0f;
	float y = 0.0f;

	float xdir = 50.0f;
	float ydir = 50.0f;

	

};

