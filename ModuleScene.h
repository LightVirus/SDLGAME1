#pragma once
#include "Module.h"
#include "Application.h"


class Application;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Start();
	update_status Update();




};

