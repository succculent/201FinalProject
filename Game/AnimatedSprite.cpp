#include "AnimatedSprite.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include <iostream>

AnimatedSprite::AnimatedSprite(Actor * owner, int draworder):SpriteComponent(owner, draworder)
{

}

void AnimatedSprite::AddImages(SDL_Texture * image)
{
	mImages.push_back(image);
}

void AnimatedSprite::Update(float deltaTime)
{
	mAnimTimer += mAnimSpeed * deltaTime;
	int temp = (int)mAnimTimer;
	
	if (temp > mImages.size()-1 && mAnimTimer/mAnimSpeed < 5.0f)
	{
		temp = mImages.size() - 1;
	}
	else if (mAnimTimer/mAnimSpeed >5.0f)
	{
		mAnimTimer = 0.0f;
		temp = 0;
	}

	SetTexture(mImages[temp]);

	

}
