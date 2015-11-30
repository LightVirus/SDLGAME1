#pragma once
#include "Module.h"
#include "Application.h"
#include "SDL/include/SDL.h"

class Application;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Start();



};

