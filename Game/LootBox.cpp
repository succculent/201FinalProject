#pragma once
#include "LootBox.h"
#include "Actor.h"
#include "Player.h"
#include "Time.h"

#include <SDL/SDL_stdinc.h>


LootBox::LootBox(Game* game):Actor(game)
{

}
void LootBox::Update(float deltaTime)
{
	if (mGame->BoxInProgress.compare(mName) != 0)
	{
		if (mGame->BoxInProgress.empty())
		{
			
		}
		else
		{
			return;
		}
	}
	srand(time(NULL));
	
	if (random == -1)
	{
		random = rand() % maxRandom + 1;
	}

	if (open && mAnimTimer < 5.0f )
	{
		opening = true;
		mAnimTimer += deltaTime;
		//std::cout << mAnimTimer << endl;
		mSprite->Update(deltaTime);
		currItem = random;
		mGame->BoxInProgress = mName;
	}
	
	if (mAnimTimer > 0.5f && !displayItem  )
	{
		if (random == 1)
		{
			displayItem = new Item(mGame, "bread", 15, "A yummy snack, +15 coins!");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/bread.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
		}
		else if (random == 2)
		{
			displayItem = new Item(mGame, "clown nose", 0, "Sometimes we all just need a clown nose.");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/clownnose.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
		}
		else if (random == 3)
		{
			displayItem = new Item(mGame, "cs degree",0, "These are pretty useful... +25 coins per click");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/csdegree.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->setMultiplier(25);

		}
		else if (random == 4)
		{
			displayItem = new Item(mGame, "laptop", 0, "Write yourself a click bot! +5 coins per second");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/laptop.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->setPassive(5);
		}
		else if (random == 5)
		{
			displayItem = new Item(mGame, "chips", 0, "You eat the chips. Was this worth 50 coins?");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/chips.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
		}
		else if (random == 6)
		{
			displayItem = new Item(mGame, "trash", 0, "congrats!");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/trash.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
		}
		else if (random == 7)
		{
			displayItem = new Item(mGame, "boba", 0, "If you really think about it, you're wasting your money");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/boba.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
		}
		else if (random == 8)
		{
			displayItem = new Item(mGame, "boba", 0, "If you really think about it, you're wasting your money");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/boba.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
		}
	}
	
	if (mAnimTimer > 5.0f && opening)
	{
		//mGame->GetPlayer()->updateBalance(15);
		opening = false;
		open = false;
		mAnimTimer = 0.0f;
		mGame->RemoveSprite(displayItem->GetSprite());
		displayItem = NULL;
		mGame->Box1inProgress = false;
		random = -1;
		mGame->RemoveItemMessage();
		mGame->BoxInProgress = "";

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
		if (!opening && mouseSpot && playerBalance>=mCost && mGame->BoxInProgress.empty())
		{
			GetGame()->GetPlayer()->updateBalance(-mCost);
			open = true;
		}
	}
	

}