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
	RectaMedEstrTEX = App->textures->Load("Game/Images/road/RectaMedEstr.png");
	RectaDerEstrTEX = App->textures->Load("Game/Images/road/RectaDerEstr.png");
	RectaIzqEstrTEX = App->textures->Load("Game/Images/road/RectaIzqEstr.png");
	CurvaDerMedEstrTEX = App->textures->Load("Game/Images/road/CurvaDerMedEstr.png");
	CurvaIzqMedEstrTEX = App->textures->Load("Game/Images/road/CurvaIzqMedEstr.png");
	
	music1 = App->sound->LoadMusic("Game/music.ogg");
	MainFont = App->textures->LoadFont("Game/mainfont.ttf", 24);
	Mix_VolumeMusic(50);
	App->sound->PlayMusic(music1);
	
	//Set Roads
	RectaMedBig.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	RectaMedBig.SetSize(RectaMedBigTEX);
	RectaMedBig.AddRectToRoad(0, 0, 83, 515);
	RectaMedBig.AddRectToRoad(397, 0, 83, 515);

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

	RectaMedEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	RectaMedEstr.SetSize(RectaMedEstrTEX);
	RectaMedEstr.AddRectToRoad(0, 0, 152, 515);
	RectaMedEstr.AddRectToRoad(328, 0, 152, 515);

	RectaDerEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	RectaDerEstr.SetSize(RectaDerEstrTEX);
	RectaDerEstr.AddRectToRoad(0, 0, 248, 515);
	RectaDerEstr.AddRectToRoad(424, 0, 56, 515);

	RectaIzqEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	RectaIzqEstr.SetSize(RectaIzqEstrTEX);
	RectaIzqEstr.AddRectToRoad(0, 0, 55, 515);
	RectaIzqEstr.AddRectToRoad(232,0,248,515);

	CurvaDerMedEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	CurvaDerMedEstr.SetSize(CurvaDerMedEstrTEX);
	CurvaDerMedEstr.AddRectToRoad(0, 0, 160, 100);
	CurvaDerMedEstr.AddRectToRoad(0, 100, 180, 100);
	CurvaDerMedEstr.AddRectToRoad(0, 200, 200, 100);
	CurvaDerMedEstr.AddRectToRoad(0, 300, 220, 100);
	CurvaDerMedEstr.AddRectToRoad(0, 400, 240, 110);
	CurvaDerMedEstr.AddRectToRoad(330, 0, 150, 100);
	CurvaDerMedEstr.AddRectToRoad(350, 100, 130, 100);
	CurvaDerMedEstr.AddRectToRoad(370, 200, 110, 100);
	CurvaDerMedEstr.AddRectToRoad(390, 300, 90, 100);
	CurvaDerMedEstr.AddRectToRoad(410, 400, 70, 110);

	CurvaIzqMedEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	CurvaIzqMedEstr.SetSize(CurvaIzqMedEstrTEX);
	CurvaIzqMedEstr.AddRectToRoad(0, 0, 150, 100);
	CurvaIzqMedEstr.AddRectToRoad(0, 100, 130, 100);
	CurvaIzqMedEstr.AddRectToRoad(0, 200, 110, 100);
	CurvaIzqMedEstr.AddRectToRoad(0, 300, 90, 100);
	CurvaIzqMedEstr.AddRectToRoad(0, 400, 70, 110);
	CurvaIzqMedEstr.AddRectToRoad(320, 0, 160, 100);
	CurvaIzqMedEstr.AddRectToRoad(300, 100, 180, 100);
	CurvaIzqMedEstr.AddRectToRoad(280, 200, 200, 100);
	CurvaIzqMedEstr.AddRectToRoad(260, 300, 220, 100);
	CurvaIzqMedEstr.AddRectToRoad(240, 400, 240, 110);


	//Set Sectors
	SECTRectaBig.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	SECTRectaBig.AddRoadToSector(RectaMedBig);
	
	SECTCambioBigEstr.SetGameObj(ROAD_X, 0, 0, 0, true, road, false);
	SECTCambioBigEstr.AddRoadToSector(RectaMedBig);
	SECTCambioBigEstr.AddRoadToSector(RectaMedBig);
	SECTCambioBigEstr.AddRoadToSector(RectaMedBig);
	SECTCambioBigEstr.AddRoadToSector(RectaMedBig);
	SECTCambioBigEstr.AddRoadToSector(CambioBigEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);
	SECTCambioBigEstr.AddRoadToSector(RectaMedEstr);
	
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
