#pragma once
#include <list>
#include "Globals.h"
#include "Application.h"
#include "Player.h"
#include "ModuleScene.h"
#include "Road.h"
#include "ModuleTimer.h"
class Sector : public GameObject
{
public:

	Sector(){}
	~Sector(){}

	float posy = 0.0f;
	std::list<Road> roads;
	bool deleteme = false;

	void AddRoadToSector(Road road)
	{
		int final = SectorEnd();
		roads.push_back(road);
		Road* roadp = &roads.back();
		roadp->posp.y = final;
	}
	
	int SectorEnd()
	{
		int suma = 0;
		for (list<Road>::iterator it = roads.begin(); it != roads.end(); ++it)
		{
			suma = suma + it->ysize;
		}
		return suma;
	}

	void Update()
	{
		posy = posy + (App->scene->MainPlayer->roadvel * App->timer->deltatime);
		if ((posy - SectorEnd()) > SECTOR_END)
		{
			deleteme = true;
		}
		for (list<Road>::iterator it = roads.begin(); it != roads.end(); ++it)
		{
			it->Update();
		}
	}

	void RenderGameObj()
	{
		for (list<Road>::iterator it = roads.begin(); it != roads.end(); ++it)
		{
			App->renderer->Blit(it->texture, it->posp.x, it->posp.y, NULL);
		}
	}



};

