#include "ModuleCollider.h"
#include <list>



ModuleCollider::ModuleCollider()
{
}


ModuleCollider::~ModuleCollider()
{
}

void ModuleCollider::CheckAllCol()
{
	for (list<Collider>::iterator itA = Colliders.begin(); itA != Colliders.end(); ++itA)
	{
		for (list<Collider>::iterator itB = Colliders.begin(); itB != Colliders.end(); ++itB)
		{
			if (itA != itB && !itA->deleteme && !itB->deleteme)
			{
				if (Collision(itA->rect, itB->rect))
				{
					itA->parent->OnCollision(itB->parent);
				}
			}
		}
	}
}

Collider* ModuleCollider::CreateCol(SDL_Rect box, item_type type, GameObject * parent)
{
	Collider col;
	Colliders.push_back(col);
	Collider* pointer = Colliders[Colliders.end];
	pointer->parent = parent;
	pointer->rect = box;
	pointer->color.a = DEBUG_ALPHA;
	switch (type)
	{
	case player:
		pointer->color.r = 0;
		pointer->color.g = 128;
		pointer->color.b = 255;
		break;
	case car:
		pointer->color.r = 204;
		pointer->color.g = 0;
		pointer->color.b = 0;
		break;
	case mbike:
		pointer->color.r = 0;
		pointer->color.g = 204;
		pointer->color.b = 0;
		break;
	case heli:
		pointer->color.r = 255;
		pointer->color.g = 51;
		pointer->color.b = 255;
		break;
	case road:
		pointer->color.r = 128;
		pointer->color.g = 128;
		pointer->color.b = 128;
		break;
	case sector:
		break;
	default:
		break;
	}
	return pointer;
}


void ModuleCollider::DelCol(Collider * col)
{
}

void ModuleCollider::DelMarkedCol()
{
}

void ModuleCollider::RenderCol()
{
}

bool ModuleCollider::Collision(SDL_Rect a, SDL_Rect b)
{
	
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}