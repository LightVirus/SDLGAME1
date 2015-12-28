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
#include "Sector.h"
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
	CambioBigEstrTEX = App->textures->Load("Game/Images/road/CambioBigEstr.png");

	music1 = App->sound->LoadMusic("Game/music.ogg");
	MainFont = App->textures->LoadFont("Game/mainfont.ttf", 24);
	Mix_VolumeMusic(50);
	App->sound->PlayMusic(music1);
	
	//Set Roads
	RectMedBig.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	RectMedBig.SetSize(RectaMedBigTEX);
	RectMedBig.AddRectToRoad(0, 0, 83, 515);
	RectMedBig.AddRectToRoad(397, 0, 83, 515);

	CambioBigEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	CambioBigEstr.SetSize(CambioBigEstrTEX);
	CambioBigEstr.AddRectToRoad(0,0,155,138);
	CambioBigEstr.AddRectToRoad(325,0,155,138);
	CambioBigEstr.AddRectToRoad(0,138,149,64);
	CambioBigEstr.AddRectToRoad(331,138,149,64);
	CambioBigEstr.AddRectToRoad(0,202,145,64);
	CambioBigEstr.AddRectToRoad(335,202,145,64);
	CambioBigEstr.AddRectToRoad(0, 266, 141, 64);
	CambioBigEstr.AddRectToRoad(339,266,141,64);
	CambioBigEstr.AddRectToRoad(0,330,137,64);
	CambioBigEstr.AddRectToRoad(343,330,137,64);
	CambioBigEstr.AddRectToRoad(0,394,131,64);
	CambioBigEstr.AddRectToRoad(349,394,131,64);
	CambioBigEstr.AddRectToRoad(0,458,123,206);
	CambioBigEstr.AddRectToRoad(357,458,123,206);
	CambioBigEstr.AddRectToRoad(0,664,116,126);
	CambioBigEstr.AddRectToRoad(364,664,116,126);
	CambioBigEstr.AddRectToRoad(0,790,110,66);
	CambioBigEstr.AddRectToRoad(370, 790, 110, 66);
	CambioBigEstr.AddRectToRoad(0,856,106,66);
	CambioBigEstr.AddRectToRoad(374,856,106,66);
	CambioBigEstr.AddRectToRoad(0,920,99,60);
	CambioBigEstr.AddRectToRoad(381,920,99,60);


	//Set Sectors
	SECTRectBig.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTRectBig.AddRoadToSector(RectMedBig);
	SECTRectBig.AddRoadToSector(RectMedBig);
	SECTRectBig.AddRoadToSector(RectMedBig);
	SECTRectBig.AddRoadToSector(RectMedBig);
	SECTRectBig.AddRoadToSector(RectMedBig);
	SECTRectBig.AddRoadToSector(RectMedBig);
	SECTRectBig.AddRoadToSector(RectMedBig);
	SECTRectBig.AddRoadToSector(RectMedBig);
	SECTRectBig.AddRoadToSector(RectMedBig);
	SECTRectBig.AddRoadToSector(RectMedBig);
	
	SECTCambioBigEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTCambioBigEstr.AddRoadToSector(RectMedBig);
	SECTCambioBigEstr.AddRoadToSector(CambioBigEstr);
	
	//Create GameObjects
	GOList.push_back(MainPlayer = new Player());
	MainPlayer->SetGameObj(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, -15, 0, true, player, false);
	SDL_Rect rectplayer1 = { 0,0,26,46 };
	SDL_Rect rectplayer2 = { 5,9,30,47 };
	MainPlayer->SetPlayer(App->collider->CreateCol(rectplayer1, player, MainPlayer), rectplayer1, rectplayer2, mainsprites);


	//DEBUG
	//SECTRectBig.CreateColOnSector();
	
	
	
	
	
	SDL_SetRenderDrawBlendMode(App->renderer->renderer, SDL_BLENDMODE_BLEND);
	return true;

	// 5 9  30 47
}

bool ModuleScene::CleanUp()
{
	for (list<GameObject*>::iterator itA = GOList.begin(); itA != GOList.end(); ++itA)
	{
		RELEASE(*itA);
	}
	GOList.clear();
	for (list<Sector>::iterator itA = SectorsList.begin(); itA != SectorsList.end();)
	{
		itA = SectorsList.erase(itA);
	}
	SectorsList.clear();
	return true;
}


update_status ModuleScene::Update()
{
	if (fristtime)
	{
		SectorsList.push_back(SECTCambioBigEstr);
		SectorsList.back().SetParent();
		SectorsList.back().posp.y = SCREEN_HEIGHT;

		for (list<Sector>::iterator itA = SectorsList.begin(); itA != SectorsList.end(); ++itA)
		{
			itA->CreateColOnSector();
		}
	}
	else
	{
		App->collider->CheckAllCol();
	}
		
	
	//Road
	for (list<Sector>::iterator itA = SectorsList.begin(); itA != SectorsList.end(); ++itA)
	{
		itA->RoadUpdate(roadvel);
	}
	
	
	// Player
	MainPlayer->Update();
	
	//Check Collision
	
	
	//RenderGO
	for (list<Sector>::iterator itA = SectorsList.begin(); itA != SectorsList.end(); ++itA)
	{
		itA->RenderGameObj();
	}
	MainPlayer->RenderGameObj();
	
	// Colliders
	if(MainPlayer->RenderCol)
		App->collider->RenderCol();

	//UI
	//App->renderer->Blit(mainui, 0, 0, NULL);

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

/*void ModuleScene::ControlToPlayer(controls cont, bool state)
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
}*/
