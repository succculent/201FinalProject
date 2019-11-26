#pragma once
#include "SDL.h"
#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include "Item.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <SDL_stdinc.h>

using namespace std;

class LootBox:public Actor
{
public:
	LootBox(Game* game);
	void ProcessInput(const Uint8* keyState);
	void Update(float deltaTime);
protected:
	int random = -1;
	int mCost;
	int mInventory;
	string mName;
	bool opening = false;
	bool open = false;
	int currentFrame = 0;
	float mAnimTimer = 0.0f;
	int maxRandom = 0;
	int currItem = -1;
	Item* displayItem;
};
