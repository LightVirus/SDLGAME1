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
	int lasttime = 0;
	int finalfps = 0;
	int fpstimercont = 0;

	bool Start();
	void StartLoop();
	void EndLoop();
	float CalculateFPS();
	void const FPSMax();

private:
	
	Uint32 starttime = 0;
	int fpscont = 0;
	Uint32 frametimer = 0;



};

