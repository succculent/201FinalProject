#pragma once
#include "LootBox.h"
#include "Game.h"
#include "UltraLootBox.h"
UltraLootBox::UltraLootBox(Game* game) :LootBox(game)
{
	mCost = 500;
	mName = "Ultra Box";
	mSprite = new SpriteComponent(this, 100);
	mSprite->SetTexture(GetGame()->GetTexture("Assets/UltraChest1.png"));
	this->SetSprite(mSprite);

	mCollis = new CollisionComponent(this);
	mCollis->SetSize(200, 200);

}