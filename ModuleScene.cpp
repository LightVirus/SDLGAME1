#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "SDL/include/SDL.h"

ModuleScene::ModuleScene()
{
}


ModuleScene::~ModuleScene()
{
}


bool ModuleScene::Start()
{
	SDL_Texture* img = App->textures->Load("sprites.png");
	return true;
}


update_status ModuleScene::Update()
{
	SDL_Texture* img = App->textures->Load("sprites.png");
	App->renderer->Blit(img, 0, 0, NULL);
	return UPDATE_CONTINUE;
}