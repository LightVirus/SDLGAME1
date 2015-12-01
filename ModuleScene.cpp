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


update_status ModuleScene::Update()
{
	SDL_Texture* img = App->textures->Load("sprites.png");
	SDL_Rect cuadrado;
	cuadrado.w = 256;
	cuadrado.h = 256;
	App->renderer->Blit(img, 0, 0, &cuadrado);
	return UPDATE_CONTINUE;
}