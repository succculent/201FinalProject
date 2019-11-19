#pragma once
#include "LootBox.h"
#include "Game.h"
#include "PrestigeLootBox.h"
#include "AnimatedSprite.h"
PrestigeLootBox::PrestigeLootBox(Game* game) :LootBox(game)
{
	mCost = 5000;
	mName = "Prestige Box";

	mSprite = new AnimatedSprite(this, 100);
	mSprite->AddImages((GetGame()->GetTexture("Assets/PrestigeChest1.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/PrestigeChest2.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/PrestigeChest3.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/PrestigeChest4.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/PrestigeChest5.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/PrestigeChest6.png")));

	mSprite->SetTexture(GetGame()->GetTexture("Assets/PrestigeChest1.png"));
	this->SetSprite(mSprite);

	mCollis = new CollisionComponent(this);
	mCollis->SetSize(200, 200);

}