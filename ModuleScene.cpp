#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

ModuleScene::ModuleScene()
{
}


ModuleScene::~ModuleScene()
{
}


bool ModuleScene::Start()
{
	SDL_Texture* img = App->textures->Load("sprites.png");
	SDL_Rect cuad;
	SDL_Rect* cuadrado = &cuad;
	cuadrado->w = 256;
	cuadrado->h = 256;
	App->renderer->Blit(img, 0, 0, cuadrado);
	return true;
}