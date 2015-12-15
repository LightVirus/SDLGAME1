#include "Player.h"
#include "Application.h"
#include "ModuleRender.h"



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
	int posxreal = posx + (TextureRect.x / 2);
	if (MainTex != NULL)
	{
		App->renderer->Blit(MainTex, posxreal, posy, &TextureRect);
	}
	return true;
	
}