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
	lasttime = SDL_GetTicks() - frametimer;
	fpscont++;
}

float ModuleTimer::CalculateFPS()
{
	fpstimercont = fpstimercont + lasttime;
	if (fpstimercont > 1000)
	{
		
		fpstimercont = fpstimercont - 1000;
		finalfps = fpscont;
		fpscont = 0;
	}
	return finalfps;
}

void const ModuleTimer::FPSMax()
{
	float time = SDL_GetTicks() - frametimer;
	if (time < (1000 / FPSMAX))
	{
		SDL_Delay((1000 / FPSMAX) - time);
	}
}
