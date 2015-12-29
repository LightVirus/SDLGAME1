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
	bool CleanUp();
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
	SDL_Texture* RectaMedEstrTEX = NULL;
	SDL_Texture* CambioBigEstrTEX = NULL;
	SDL_Texture* RectaDerEstrTEX = NULL;
	SDL_Texture* RectaIzqEstrTEX = NULL;
	SDL_Texture* CurvaDerMedEstrTEX = NULL;
	SDL_Texture* CurvaIzqMedEstrTEX = NULL;
	SDL_Texture* mainui = NULL;
	TTF_Font* MainFont = NULL;

	//Music
	Mix_Music* music1 = NULL;

	//Sounds
	Mix_Chunk* effect1 = NULL;
	Mix_Chunk* effect2 = NULL;

	//Road
	Road RectaMedBig;
	Road RectaMedEstr;
	Road CambioBigEstr;
	Road RectaDerEstr;
	Road RectaIzqEstr;
	Road CurvaDerMedEstr;
	Road CurvaIzqMedEstr;

	//Sector
	Sector SECTRectaBig;
	Sector SECTCambioBigEstr;
	
	//GameObjects
	list<GameObject*> GOList;
	


	float x = 0.0f;
	float y = 0.0f;

	float xdir = 50.0f;
	float ydir = 50.0f;

	

};

