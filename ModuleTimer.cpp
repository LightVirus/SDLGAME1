#include "ModuleTimer.h"
#include "SDL/include/SDL.h"

ModuleTimer::ModuleTimer()
{
}


ModuleTimer::~ModuleTimer()
{
}


bool ModuleTimer::Start()
{
	starttime = SDL_GetTicks();
}

Uint32 ModuleTimer::getTime()
{
	Uint32 time = SDL_GetTicks() - starttime;
	return time;
}

void ModuleTimer::StartLoop()
{

}