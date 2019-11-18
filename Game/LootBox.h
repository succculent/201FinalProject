#pragma once
#include "SDL/SDL.h"
#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class LootBox : public Actor
{

private:
	int cost;
	int numInventory;
	string name;
	
};
