#pragma once
#include <list>
#include "Globals.h"
#include "Module.h"
#include "Application.h"

struct Mix_Music;
class Application;

class ModuleSound : public Module
{
public:
	ModuleSound();
	~ModuleSound();

	bool Init();
	bool CleanUp();
	Mix_Music* const LoadMusic(const char* path);
	bool LoadSoundE();


private:
	std::list<Mix_Music*> musicas;
};

