#include "Paddle.h"

#include "Game.h"

Paddle::Paddle(class Game* game) : Actor(game)
{
	pSprite = new SpriteComponent(this, 100);
	pSprite->SetTexture(GetGame()->GetTexture("Assets/Paddle.png"));

	pMove = new PaddleMove(this);
	SetPosition(Vector2(512, 750));
	SetSprite(pSprite);
	setMove(pMove);
	mPaddle = pMove;

	mCollis = new CollisionComponent(this);
	mCollis->SetSize(104, 24);

}

void Paddle::ActorInput(const Uint8* keyState)
{
	if (keyState[SDL_SCANCODE_LEFT])
	{
		
			pMove->SetForwardSpeed(-50.0f);
			RightKey = true;
		

	}

	if (keyState[SDL_SCANCODE_RIGHT])
	{
			pMove->SetForwardSpeed(50.0f);
			LeftKey = true;
	
	}
}
