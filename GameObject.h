#pragma once
#include "Animation.h"
#include <vector>
class GameObject
{
public:
	GameObject();
	~GameObject();

	float posx = 0;
	float posy = 0;
	bool visible = false;
	GameObject* parent;
	std::vector<Animation> anims;

	
};

