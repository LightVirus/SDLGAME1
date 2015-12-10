#pragma once
#include "Module.h"
class ModuleParticle :
	public Module
{
public:
	ModuleParticle();
	~ModuleParticle();

	struct particle
	{
		float posx;
		float posy;

	};
};

