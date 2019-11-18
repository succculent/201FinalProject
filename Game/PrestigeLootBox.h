#pragma once
#pragma once

#pragma once
#include "Game.h"
#include "LootBox.h"
#include "Item.h"
#include <unordered_map>

class PrestigeLootBox :public LootBox
{
public:
	PrestigeLootBox(Game* game);
private:
	unordered_map <string, Item*> prizes;
};