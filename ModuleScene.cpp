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


using namespace std;


ModuleScene::ModuleScene()
{
	
}


ModuleScene::~ModuleScene()
{
}


bool ModuleScene::Start()
{
	//Load Resources
	mainsprites = App->textures->Load("Game/Images/mainsprites.png");
	mainui = App->textures->Load("Game/Images/UI.png");
	music1 = App->sound->LoadMusic("Game/music.ogg");
	MainFont = App->textures->LoadFont("Game/mainfont.ttf", 24);
	Mix_VolumeMusic(50);
	App->sound->PlayMusic(music1);
	
	//Create GameObjects
	MainPlayer.SetGameObj(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 15,true, player, false);
	SDL_Rect temp = { 0,0,26,46 };
	SDL_Rect temp2 = { 5,9,30,47 };
	MainPlayer.SetPlayer(App->collider->CreateCol(temp, player, &MainPlayer),temp,temp2, mainsprites);


	
	
	SDL_SetRenderDrawBlendMode(App->renderer->renderer, SDL_BLENDMODE_BLEND);
	return true;

	// 5 9  30 47
}


update_status ModuleScene::Update()
{
	
	// Player
	MainPlayer.Update();
	
	
	App->collider->UpdateCol();
	//RenderGO
	MainPlayer.RenderGameObj();
	
	// Colliders
	App->collider->RenderCol();

	//UI
	App->renderer->Blit(mainui, 0, 0, NULL);

	// FPS
	stringstream timeText;
	timeText.str("");
	timeText << "FPS: " << App->timer->finalfps;
	SDL_Color White = { 255, 255, 255 };
	SDL_Texture* fpstexture = App->textures->Font2Texture(MainFont, timeText.str().c_str(), White);
	App->renderer->Blit(fpstexture, 6, SCREEN_HEIGHT - 25, NULL);
	SDL_DestroyTexture(fpstexture);
	
	

	return UPDATE_CONTINUE;
}

void const ModuleScene::GoSound()
{
	App->sound->PlaySoundE(effect1);
}