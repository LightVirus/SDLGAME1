#include "Player.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTimer.h"
#include "ModuleInput.h"
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

void Player::Update()
{
	
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if (xvel > 0)
			xvel = 0;
		xvel = xvel - 10;
		if (xvel < -10000)
			xvel = -10000;
	}
	else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{ 
		if (xvel < 0)
			xvel = 0;
		xvel = xvel + 10 ;
		if (xvel > 10000)
			xvel = 10000;
	}
	
	else
	{
		xvel = 0;
	}
	
	posx = posx + (xvel * App->timer->deltatime);
	
	//Collider
	col->rect.x = col->parent->posx - (col->rect.w / 2);
	col->rect.y = col->parent->posy;
}

void Player::OnCollisionEnter(GameObject * ColWith)
{
	LOG("COLLISION WITH PLAYER DETECTED");
}

void Player::RenderGameObj()
{
	if (MainTex != NULL)
	{
		App->renderer->Blit(MainTex, posx + xoffset, posy, &TextureRect);
	}
}