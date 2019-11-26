#pragma once
#pragma once
#include "SDL.h"
#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <SDL_stdinc.h>

using namespace std;

class Player :public Actor
{
public:
	Player(Game* game);
	void ProcessInput(const Uint8* keyState);
	void Update(float deltaTime);
	int getBalance();
	int updateBalance(int coin);
	int getMultiplier() { return multiplier;};
	void setMultiplier(int m) { multiplier += m; };
	void setPassive(int s) { passivemult += s; };
	int getCPS() { return passivemult; }
	bool clicked = false;
	bool clickedFirst = true;
private:
	int balance = 50;
	int multiplier = 50;
	float lastTime = 0.0f;
	int passivemult = 0;
	int cps = 0;
	float second = 0.0f;
};
