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
#include "Road.h"
#include <string>
#include <sstream>
#include <list>
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
	RectaMedBigTEX = App->textures->Load("Game/Images/road/RectaMedBig.png");

	music1 = App->sound->LoadMusic("Game/music.ogg");
	MainFont = App->textures->LoadFont("Game/mainfont.ttf", 24);
	Mix_VolumeMusic(50);
	App->sound->PlayMusic(music1);
	
	//Set Roads
	RectMedBig.SetGameObj(ROAD_X, ROAD_Y, 240, 0, true, road, false); //Cambiar a cordenadas 0,0
	RectMedBig.texture = RectaMedBigTEX;
	RectMedBig.AddRectToRoad(0, 0, 83, 515);
	RectMedBig.AddRectToRoad(397, 0, 83, 515);
	
	
	//Create GameObjects
	GOList.push_back(MainPlayer = new Player());
	MainPlayer->SetGameObj(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, -15, 0, true, player, false);
	SDL_Rect rectplayer1 = { 0,0,26,46 };
	SDL_Rect rectplayer2 = { 5,9,30,47 };
	MainPlayer->SetPlayer(App->collider->CreateCol(rectplayer1, player, MainPlayer), rectplayer1, rectplayer2, mainsprites);


	//DEBUG
	RectMedBig.CreateColForRoad();
	
	
	
	
	
	SDL_SetRenderDrawBlendMode(App->renderer->renderer, SDL_BLENDMODE_BLEND);
	return true;

	// 5 9  30 47
}


update_status ModuleScene::Update()
{
	if(!fristtime)
		App->collider->CheckAllCol();
	
	//Road
	RectMedBig.Update();
	
	
	// Player
	MainPlayer->Update();
	
	//Check Collision
	
	
	//RenderGO
	App->renderer->Blit(RectaMedBigTEX, ROAD_X, ROAD_Y, NULL);
	MainPlayer->RenderGameObj();
	
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
	timeText.clear();
	
	if (fristtime)
		fristtime = false;
	return UPDATE_CONTINUE;
}

void const ModuleScene::GoSound()
{
	App->sound->PlaySoundE(effect1);
}

void ModuleScene::ControlToPlayer(controls cont, bool state)
{
	switch (cont)
	{
	case Cnoone:
		break;
	case Crigth:
	{
		MainPlayer->derecha = state;
		break;
	}
		
	case Cleft:
	{
		MainPlayer->izquierda = state;
		break;
	}
		
	}
}
