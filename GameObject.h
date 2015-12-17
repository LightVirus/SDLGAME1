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
	float xoffset;
	float yoffset;
	bool deleteme = false;


	virtual void OnCollision(GameObject* ColWith)
	{

	}

	void SetGameObj(float x, float y, float offsetx, float offsety, bool vis, item_type item, bool del)
	{
		posx = x;
		posy = y;
		visible = vis;
		type = item;
		deleteme = del;
		xoffset = offsetx;
		yoffset = offsety;
	}

	void SetGameObj(float x, float y, float offsetx, float offsety, bool vis, item_type item, bool del, GameObject* dad)
	{
		posx = x;
		posy = y;
		visible = vis;
		type = item;
		deleteme = del;
		parent = dad;
		xoffset = offsetx;
	}


	virtual void Update()
	{
	}
	virtual void LateUpdate()
	{
	}
	virtual void RenderGameObj()
	{
	}


};