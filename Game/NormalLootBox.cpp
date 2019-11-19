#pragma once
#include "Game.h"
#include "SpriteComponent.h"
#include "AnimatedSprite.h"
#include "NormalLootBox.h"
#include "LootBox.h"

NormalLootBox::NormalLootBox(Game* game):LootBox(game)
{
	mCost = 50;
	mName = "Normal Box";

	mSprite = new AnimatedSprite(this, 100);
	mSprite->AddImages((GetGame()->GetTexture("Assets/NormalChest1.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/NormalChest2.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/NormalChest3.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/NormalChest4.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/NormalChest5.png")));
	mSprite->AddImages((GetGame()->GetTexture("Assets/NormalChest6.png")));

	mSprite->SetTexture(GetGame()->GetTexture("Assets/NormalChest1.png"));
	this->SetSprite(mSprite);

	mCollis = new CollisionComponent(this);
	mCollis->SetSize(200, 200);

}