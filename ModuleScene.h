#pragma once
#include "Module.h"
#include "Application.h"


class Application;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	update_status Update();



};

