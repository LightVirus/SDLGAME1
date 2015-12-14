#pragma once
#include "Animation.h"
#include "Globals.h"
#include <vector>
class ModuleCollider;

class GameObject
{
public:
	GameObject() {}
	~GameObject() {}

	float posx = 0;
	float posy = 0;
	bool visible = false;
	GameObject* parent;
	item_type type;
	bool deleteme = false;
	
	virtual void OnCollision(GameObject* ColWith)
	{

	}

	void SetGameObj(float x, float y, bool vis, item_type item, bool del)
	{
		posx = x;
		posy = y;
		visible = vis;
		type = item;
		
	}

	void SetGameObj(float x, float y, bool vis, item_type item, bool del,GameObject* dad)
	{
		posx = x;
		posy = y;
		visible = vis;
		type = item;
		deleteme = del;
		parent = dad;
	}

	virtual void Update()
	{

	}
	virtual void LateUpdate()
	{

	}


	
};

