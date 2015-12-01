#include "ModuleSound.h"
#include "Globals.h"
#include "Application.h"
#include "Module.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/lib/x86/SDL2_mixer.lib" )

ModuleSound::ModuleSound()
{
}


ModuleSound::~ModuleSound()
{
}


bool ModuleSound::Init()
{
	LOG("Init SDL Audio event system");
	bool ret = true;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		LOG("SDL_AUDIO could not initialize! SDL_Error: %s\n", Mix_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleSound::CleanUp()
{
	LOG("Freeing music");

	for (std::list<Mix_Music*>::iterator it = musicas.begin(); it != musicas.end(); ++it)
		Mix_FreeMusic(*it);

	musicas.clear();
	return true;
}


Mix_Music* const ModuleSound::LoadMusic(const char* path)
{
	Mix_Music *musica = NULL;
	musica = Mix_LoadMUS(path);
	if (musica == NULL)
	{
		printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

