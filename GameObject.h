#pragma once
#include "Animation.h"
#include "Globals.h"

#include <vector>

class GameObject
{
public:
	GameObject() {}
	//~GameObject() {}

	float posx = 0;
	float posy = 0;
	bool visible = false;
	GameObject* parent = NULL;
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
		deleteme = del;
	}

	void SetGameObj(float x, float y, bool vis, item_type item, bool del, GameObject* dad)
	{
		posx = x;
		posy = y;
		visible = vis;
		type = item;
		deleteme = del;
		parent = dad;
	}


	virtual bool Update()
	{
		return true;
	}
	virtual bool LateUpdate()
	{
		return true;
	}
	virtual bool RenderGameObj()
	{
		return true;
	}


};