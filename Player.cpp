#include "Player.h"
#include "Application.h"
#include "ModuleRender.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::SetPlayer(Collider* collider, SDL_Rect cuadro, SDL_Texture* Tex)
{
	col = collider;
	rect = cuadro;
	MainTex = Tex;
}
void Player::RenderGameObj()
{
	int posxreal = posx + (rect.x / 2);
	if (MainTex != NULL)
	{
		App->renderer->Blit(MainTex, posxreal, posy, &rect);
	}
	
}