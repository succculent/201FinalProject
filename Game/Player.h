#pragma once
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

class Player :public Actor
{
public:
	Player(Game* game);
	void ProcessInput(const Uint8* keyState);
	void Update(float deltaTime);
	int getBalance();
	int updateBalance(int coin);
	void updateClickMultiplier(int mult);
private:
	int balance = 0;
	int multiplier = 1;
	bool clicked = false;
	float lastTime = 0.0f;
};
