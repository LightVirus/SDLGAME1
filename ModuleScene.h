#pragma once
#include "Module.h"
#include "Application.h"
#include "SDL/include/SDL_mixer.h"
#include "SDL/include/SDL_image.h"
#include "SDL/include/SDL_ttf.h"
#include <vld.h>
class Application;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Start();
	update_status Update();
	void const GoSound();

private:
	
	//Textures
	SDL_Texture* img = NULL;
	TTF_Font* MainFont = NULL;

	//Music
	Mix_Music* music1 = NULL;

	//Sounds
	Mix_Chunk* effect1 = NULL;
	Mix_Chunk* effect2 = NULL;

	float x = 0.0f;
	float y = 0.0f;

	float xdir = 50.0f;
	float ydir = 50.0f;



};

