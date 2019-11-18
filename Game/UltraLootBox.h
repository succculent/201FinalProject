#pragma once

#pragma once
#include "Game.h"
#include "LootBox.h"
#include "Item.h"
#include <unordered_map>

class UltraLootBox :public LootBox
{
public:
	UltraLootBox(Game* game);
private:
	unordered_map <string, Item*> prizes;
};