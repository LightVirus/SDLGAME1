#pragma once
#include <windows.h>
#include <stdio.h>
#include <vld.h>
#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

enum item_type
{
	player = 1,
	car,
	mbike,
	heli,
	road,
	sector
};

struct Collider
{
	GameObject* parent;
	SDL_Rect rect;
	SDL_Color color;
	bool deleteme;
};


// Configuration -----------
#define DEBUG_ALPHA 180
#define SCREEN_WIDTH 880
#define SCREEN_HEIGHT 750
#define FULLSCREEN false
#define BORDERLESS false
#define RESIZABLE false
#define FULLSCREEN_DESKTOP false
#define VSYNC true
#define FPSLOCK false
#define FPSMAX 50.0f
#define TITLE "Spy Hunter"

