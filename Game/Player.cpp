#include "Player.h"
#include "Game.h"
#include "Time.h"
using namespace std;
Player::Player(Game* game):Actor(game)
{
	SpriteComponent * ButtonSprite = new SpriteComponent(this, 3);
	ButtonSprite->SetTexture(game->GetTexture("Assets/workbutton.png"));
	SetSprite(ButtonSprite);
	SetPosition(Vector2(512, 600));
	
	mCollis = new CollisionComponent(this);
	mCollis->SetSize(256, 50);
	game->UpdateCoinPerClick(1);
}

void Player::ProcessInput(const Uint8* keyState)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	bool mouseSpot = mCollis->Intersect(Vector2(x, y));

	if ((SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		if (mouseSpot && clicked && clickedFirst )
		{
			updateBalance(multiplier);
			//cout << updateBalance(multiplier) << endl;
			clickedFirst = false;
			clicked = false;
			
		}
	}
	

	
}

void Player::Update(float deltaTime)
{
	second += deltaTime;
	if (second > 1.0f)
	{
		balance += passivemult;
		second = 0.0f;
	}
	//cout << cps << endl;
}

int Player::updateBalance(int coin)
{
	balance += coin;
	return balance;
}

int Player::getBalance()
{
	return balance;
}


