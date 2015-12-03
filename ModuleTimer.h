#pragma once
#include "Module.h"
#include "SDL/include/SDL.h"
class ModuleTimer :
	public Module
{
public:
	ModuleTimer();
	~ModuleTimer();

	Uint32 getTime();
	float deltatime = 0.0f;
	bool Start();
	void StartLoop();
	void EndLoop();
	float CalculateFPS();
	int finalfps = 0;

private:
	float fpstimercont = 0;
	Uint32 starttime = 0;
	int fpscont = 0;
	Uint32 frametimer = 0;



};

