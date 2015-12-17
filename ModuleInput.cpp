#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "Player.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput()
{}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();
	SDL_Event event;
	keyboard = SDL_GetKeyboardState(NULL);

	while (SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
			return UPDATE_STOP;

		switch (event.key.keysym.sym)
		{
		case SDLK_d:
			if (event.key.state = (SDL_PRESSED))
				App->scene->ControlToPlayer(Crigth, true);
			else if (event.key.state = (SDL_RELEASED))
				App->scene->ControlToPlayer(Crigth, false);
			break;
		case SDLK_a:
			if (event.key.state = (SDL_PRESSED))
				App->scene->ControlToPlayer(Cleft, true);
			else if (event.key.state = (SDL_RELEASED))
				App->scene->ControlToPlayer(Cleft, false);
			break;
		default:
			break;
		}
		
		if (event.type == SDL_QUIT)
		{
			return UPDATE_STOP;
		}
	}
	
	if (keyboard[SDL_SCANCODE_ESCAPE])
	{
		return UPDATE_STOP;
	}
	
	

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}