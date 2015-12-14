#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleSound.h"
#include "ModuleTimer.h"
#include "ModuleCollider.h"
#include "GameObject.h"
#include "Player.h"
#include <string>
#include <sstream>
#include "SDL/include/SDL.h"
#include "SDL/include/SDL_mixer.h"
#include "SDL/include/SDL_image.h"
#include <vld.h>

using namespace std;


ModuleScene::ModuleScene()
{
}


ModuleScene::~ModuleScene()
{
}


bool ModuleScene::Start()
{
	mainsprites = App->textures->Load("Game/Images/mainsprites.png");
	music1 = App->sound->LoadMusic("Game/music.ogg");
	//effect1 = App->sound->LoadSoundE("Game/effect.ogg");
	MainFont = App->textures->LoadFont("Game/mainfont.ttf", 24);
	Mix_VolumeMusic(50);
	App->sound->PlayMusic(music1);
	return true;

	// 5 9  30 47
}


update_status ModuleScene::Update()
{
	if ((x + 256) > SCREEN_WIDTH || x < 0)
	{
		//x = SCREEN_WIDTH - 256;
		xdir = xdir * -1;
	}
	if ((y + 256) > SCREEN_HEIGHT || y < 0)
	{
		//y = SCREEN_WIDTH - 256;
		ydir = ydir * -1;
	}
	
	x = x + (xdir*App->timer->deltatime);
	y = y + (ydir*App->timer->deltatime);

	App->renderer->Blit(img, x, y, NULL);
	
	
	stringstream timeText;
	timeText.str("");
	timeText << "FPS: " << App->timer->finalfps;
	SDL_Color White = { 255, 255, 255 };
	SDL_Texture* fpstexture = App->textures->Font2Texture(MainFont, timeText.str().c_str(), White);
	App->renderer->Blit(fpstexture, 6, 455, NULL);
	SDL_DestroyTexture(fpstexture);
	
	

	return UPDATE_CONTINUE;
}

void const ModuleScene::GoSound()
{
	App->sound->PlaySoundE(effect1);
}