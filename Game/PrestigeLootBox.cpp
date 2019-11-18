#pragma once
#include "LootBox.h"
#include "Game.h"
#include "PrestigeLootBox.h"
PrestigeLootBox::PrestigeLootBox(Game* game) :LootBox(game)
{
	mCost = 5000;
	mName = "Prestige Box";
	mSprite = new SpriteComponent(this, 100);
	mSprite->SetTexture(GetGame()->GetTexture("Assets/PrestigeChest1.png"));
	this->SetSprite(mSprite);

	mCollis = new CollisionComponent(this);
	mCollis->SetSize(200, 200);

}