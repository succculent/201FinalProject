#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <iostream>
#include <algorithm>

Actor::Actor(Game* game)
	:mGame(game)
	,mState(EActive)
	,mPosition(Vector2::Zero)
	,mScale(1.0f)
	,mRotation(0.0f)
{
	game->AddActor(this);
	mGame = game;
	mSprite = nullptr;
	RightKey = false;
	LeftKey = false;
	// TODO
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
	delete mSprite;
	SpriteComponent* GetSprite();
	bool SetSprite(SpriteComponent* sprite);
	//delete mSprite;
	//delete mMove;
	// TODO
}

void Actor::Update(float deltaTime)
{
	if (mState == EActive)
	{
		UpdateActor(deltaTime);
	}

	
	// TODO
}

void Actor::UpdateActor(float deltaTime)
{
	//update components
	if (mSprite != NULL)
	{
		mSprite->SpriteComponent::Update(deltaTime);

	}
}

void Actor::ProcessInput(const Uint8* keyState) 
{
	//std::cout << "here" << std::endl;
	if (mState == EActive)
	{
		ActorInput(keyState);
	}
	// TODO
}

void Actor::ActorInput(const Uint8* keyState)
{
	if (mSprite != NULL)
	{
		mSprite->ProcessInput(keyState);
	}

}

void Actor::SetSprite(SpriteComponent* sprite)
{
	mSprite = sprite;
}
 
SpriteComponent* Actor::GetSprite()
{
	return mSprite;
}

Vector2 Actor::GetForward()
{
	Vector2 temp = Vector2(Math::Cos(GetRotation()), -Math::Sin(GetRotation()));
	
	Vector2 v2 = Vector2::UnitX;
	return temp * 50.0f + v2;
}




