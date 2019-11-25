#pragma once
#include "Game.h"
#include "Actor.h"
#include <string>

using namespace std;
class Item :public Actor
{
public:
	Item(Game* game, string name, int value, string mDescription);
	void Update(float deltaTime);
	int GetCoinValue() { return coinValue; }

protected:
	string mName;
	int coinValue;
	string mDescription;
	float mTotalTime =0.0f;
};