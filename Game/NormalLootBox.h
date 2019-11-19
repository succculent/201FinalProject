#pragma once
#include "Game.h"
#include "LootBox.h"
#include "Item.h"
#include <unordered_map>
#include "AnimatedSprite.h"

class NormalLootBox :public LootBox
{
public:
	NormalLootBox(Game* game);
private:
	unordered_map <string,Item*> prizes;
};