#include "ModuleTimer.h"
#include "SDL/include/SDL.h"
#include <string>

using namespace std;

ModuleTimer::ModuleTimer()
{
}


ModuleTimer::~ModuleTimer()
{
}


bool ModuleTimer::Start()
{
	starttime = SDL_GetTicks();
	return true;
}

Uint32 ModuleTimer::getTime()
{
	Uint32 time = SDL_GetTicks() - starttime;
	return time;
}

void ModuleTimer::StartLoop()
{
	frametimer = SDL_GetTicks();
}

void ModuleTimer::EndLoop()
{
	deltatime = ((SDL_GetTicks() - frametimer) / 1000.0f);
	fpscont++;
}

float ModuleTimer::CalculateFPS()
{
	fpstimercont = fpstimercont + deltatime;
	if (fpstimercont > 1.0f)
	{
		fpstimercont = 0;
		finalfps = fpscont;
		fpscont = 0;
	}
	return finalfps;
}
