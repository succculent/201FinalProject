#pragma once
#include "LootBox.h"
#include "Game.h"
#include "UltraLootBox.h"
#include "AnimatedSprite.h"
UltraLootBox::UltraLootBox(Game* game) :LootBox(game)
{
	mCost = 500;
	mName = "Ultra Box";
	mSprite = new AnimatedSprite(this, 100);
	mSprite->AddImages((GetGame()->GetTexture("Assets/UltraChest1.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/UltraChest2.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/UltraChest3.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/UltraChest4.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/UltraChest5.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/UltraChest6.png")));
	mSprite->SetTexture(GetGame()->GetTexture("Assets/UltraChest1.png"));

	this->SetSprite(mSprite);

	mCollis = new CollisionComponent(this);
	mCollis->SetSize(200, 200);

}