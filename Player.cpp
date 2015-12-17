#include "Player.h"
#include "Application.h"
#include "ModuleRender.h"
#include <sstream>



Player::Player()
{
}


Player::~Player()
{
}

void Player::SetPlayer(Collider* collider, SDL_Rect cuadro, SDL_Rect cuadrotex, SDL_Texture* Tex)
{
	col = collider;
	Rect = cuadro;
	TextureRect = cuadrotex;
	MainTex = Tex;
}

bool Player::RenderGameObj()
{
	if (MainTex != NULL)
	{
		App->renderer->Blit(MainTex, posx - xoffset, posy, &TextureRect);
	}
	return true;
	
}