#pragma once
#include "SDL/SDL.h"
#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <SDL/SDL_stdinc.h>

using namespace std;

class LootBox:public Actor
{
public:
	LootBox(Game* game);
	void ProcessInput(const Uint8* keyState);
	void Update(float deltaTime);
protected:
	int mCost;
	int mInventory;
	string mName;
	bool opening = false;
	bool open = false;
	int currentFrame = 0;
	float mAnimTimer = 0.0f;
};
