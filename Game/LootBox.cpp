#pragma once
#include "LootBox.h"
#include "Actor.h"
#include "Player.h"
#include <SDL/SDL_stdinc.h>


LootBox::LootBox(Game* game):Actor(game)
{

}
void LootBox::Update(float deltaTime)
{
	if (open && mAnimTimer < 5.0f)
	{
		opening = true;
		mAnimTimer += deltaTime;
		//std::cout << mAnimTimer << endl;
		mSprite->Update(deltaTime);
	}
	
	if (mAnimTimer > 5.0f)
	{
		opening = false;
		open = false;
		mAnimTimer = 0.0f;
	}
}
void LootBox::ProcessInput(const Uint8* keyState)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	bool mouseSpot = mCollis->Intersect(Vector2(x, y));

	
	
	if((SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		int playerBalance = GetGame()->GetPlayer()->getBalance();
		if (!opening && mouseSpot && playerBalance>=mCost)
		{
			GetGame()->GetPlayer()->updateBalance(-mCost);
			open = true;
		}
	}
	

}