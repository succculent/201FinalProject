#pragma once
#include "LootBox.h"
#include "Actor.h"
#include "Player.h"
#include "Time.h"
#include "SDL_mouse.h"


LootBox::LootBox(Game* game) :Actor(game)
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

	if (open && mAnimTimer < 5.0f)
	{
		opening = true;
		mAnimTimer += deltaTime;
		//std::cout << mAnimTimer << endl;
		mSprite->Update(deltaTime);
		currItem = random;
		mGame->BoxInProgress = mName;
	}

	if (mAnimTimer > 0.5f && !displayItem)
	{
		if (random == 1)
		{
			displayItem = new Item(mGame, "bread", 15, "A yummy snack, +100 coins!");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/bread.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->updateBalance(100);

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
			displayItem = new Item(mGame, "cs degree", 0, "These are pretty useful... +5 coins per click");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/csdegree.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->setMultiplier(5);
			mGame->UpdateCoinPerClick(mGame->GetPlayer()->getMultiplier());
		
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
			displayItem = new Item(mGame, "bag of chips", 0, "You eat the chips. Was this worth all the coins you spent?");
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
			displayItem = new Item(mGame, "boba", 0, "If you really think about it, you're wasting your money.");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/boba.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
		}
		else if (random == 8)
		{
			displayItem = new Item(mGame, "single ice cream cone", 500, "I scream you scream it's finals week and I'm scared. +500 coins");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/icecream.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->updateBalance(500);
		}
		else if (random == 9)
		{
			displayItem = new Item(mGame, "meme boi", 0, "This game is a meme. +69 coins per second");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/kermit.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->setPassive(69);
		}
		else if (random == 10)
		{
			displayItem = new Item(mGame, "brain", 0, "You watched rick and morty and now have 500 iq. +25 coins per click");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/brain.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->setMultiplier(25);
			mGame->UpdateCoinPerClick(mGame->GetPlayer()->getMultiplier());
		}
		else if (random == 11)
		{
			displayItem = new Item(mGame, "chicken", 42069, "Winner Winner Chicken Dinner! +42069 coins");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/chicken.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->updateBalance(42069);
		}
		else if (random == 12)
		{
			displayItem = new Item(mGame, "elon musk", 0, "Congrats you're Elon Musk!");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/elonmusk.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
		}
		else if (random == 13)
		{
			displayItem = new Item(mGame, "blue screen of death", 0, "You wrote some really bad code. Lose all your coins!");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/bsod.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->updateBalance(-mGame->GetPlayer()->getBalance());
		}
		else if (random == 14)
		{
			displayItem = new Item(mGame, "uwu", 0, "You are filled with determination! +50 coins per click");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/uwu.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->setMultiplier(50);
			mGame->UpdateCoinPerClick(mGame->GetPlayer()->getMultiplier());

		}
		else if (random == 15)
		{
			displayItem = new Item(mGame, "coin", 0, "You mined a bitcoin! haha jk.... unless... +50 coins per second");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/coin.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->setPassive(50);
		}
		else if (random == 16)
		{
			displayItem = new Item(mGame, "waifu", 0, "Rem is the best waifu and if you disagree you're objectively wrong. +10000 coins");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/rem.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->updateBalance(10000);
		}
		else if (random == 17)
		{
			displayItem = new Item(mGame, "supreme sticker", 0, "You're a hypebeast now! + 10 coins per second");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/supreme.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->setPassive(10);

		}
		else if (random == 18)
		{
			displayItem = new Item(mGame, "hydroflask", 0, "sksksksksk");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/hydroflask.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
		}
		else if (random == 19)
		{
			displayItem = new Item(mGame, "financial aid package", 0, "Jokes on you, your EFC is too high. Here's a single penny. +1 coin");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/cash.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->updateBalance(1);
		}
		else if (random == 20)
		{
			displayItem = new Item(mGame, "scandal", 0, "Lose everything you ever worked for LUL.");
			SpriteComponent* temp = new SpriteComponent(this, 150);
			temp->SetTexture(mGame->GetTexture("Assets/cash.png"));
			displayItem->SetSprite(temp);
			displayItem->SetPosition(GetPosition());
			mGame->AddActor(displayItem);
			mGame->GetPlayer()->updateBalance(-mGame->GetPlayer()->getBalance());
			mGame->GetPlayer()->setPassive(-mGame->GetPlayer()->getPassive());
			mGame->GetPlayer()->setMultiplier(-mGame->GetPlayer()->getMultiplier()+1);
		}
	}

	if (mAnimTimer > 3.0f && opening)
	{
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



	if ((SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		int playerBalance = GetGame()->GetPlayer()->getBalance();
		if (!opening && mouseSpot && playerBalance >= mCost && mGame->BoxInProgress.empty())
		{
			GetGame()->GetPlayer()->updateBalance(-mCost);
			open = true;
			GetGame()->messageactive = false;
		}
		else if (GetGame()->BoxInProgress != "" && mouseSpot && !opening)
		{
			mGame->SetMessage("Wait until previous box is open to pruchase");

		}
		else if (mouseSpot && playerBalance < mCost && !open)
		{
			mGame->SetMessage("You do not have enough coins to buy this");
		}
	}


}