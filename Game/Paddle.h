#pragma once
#include "Actor.h"
#include "PaddleMove.h"

class Paddle : public Actor
{
public:
	Paddle(class Game* game);
	void ActorInput(const Uint8* keyState)override;

private:
	SpriteComponent* pSprite;
	PaddleMove* pMove;

	
};