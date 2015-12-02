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

	bool Start();
	void StartLoop();
	void EndLoop();
private:

	Uint32 starttime = 0;
	Uint32 deltatime = 0;
	int fps = 0;



};

