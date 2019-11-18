#pragma once
#include "LootBox.h"
#include "Game.h"
#include "NormalLootBox.h"
NormalLootBox::NormalLootBox(Game* game):LootBox(game)
{
	mCost = 50;
	mName = "Normal Box";
	mSprite = new SpriteComponent(this, 100);
	mSprite->SetTexture(GetGame()->GetTexture("Assets/NormalChest1.png"));
	this->SetSprite(mSprite);

	mCollis = new CollisionComponent(this);
	mCollis->SetSize(200, 200);

}