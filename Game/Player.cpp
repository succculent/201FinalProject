#include "Player.h"
#include "Game.h"
using namespace std;
Player::Player(Game* game):Actor(game)
{
	SpriteComponent * ButtonSprite = new SpriteComponent(this, 3);
	ButtonSprite->SetTexture(game->GetTexture("Assets/workbutton.png"));
	SetSprite(ButtonSprite);
	SetPosition(Vector2(512, 550));
	
	mCollis = new CollisionComponent(this);
	mCollis->SetSize(256, 50);
}

void Player::ProcessInput(const Uint8* keyState)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	bool mouseSpot = mCollis->Intersect(Vector2(x, y));

	if ((SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		if (mouseSpot && !clicked)
		{
			cout << updateBalance(multiplier) << endl;
			clicked = true;
		}
	}
	
}

void Player::Update(float deltaTime)
{
	if (clicked)
	{
		if (lastTime > 0.1f)
		{
			lastTime = 0;
			clicked = false;
			
		}
		else
		{
			lastTime += deltaTime;
		}
	}
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

void Player::updateClickMultiplier(int mult)
{
	multiplier = mult;
}

