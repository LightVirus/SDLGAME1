#pragma once
#include "Module.h"
#include "Application.h"
#include "SDL/include/SDL_mixer.h"
#include "SDL/include/SDL_image.h"

class Application;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Start();
	update_status Update();

private:
	
	//Textures
	SDL_Texture* img = NULL;

	//Music
	Mix_Music* music1 = NULL;

	//Sounds
	Mix_Chunk* effect1 = NULL;
	Mix_Chunk* effect2 = NULL;

	int x = 0;
	int y = 0;

	int xdir = 1;
	int ydir = 1;



};

