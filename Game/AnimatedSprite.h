#pragma once
#include "SpriteComponent.h"
#include <vector>
class AnimatedSprite : public SpriteComponent
{
public:
	AnimatedSprite(Actor *owner, int draworder);
	void AddImages(SDL_Texture* image) override;
	void Update(float deltaTime) override;

	float mAnimSpeed = 15.0;

private:
	std::vector<SDL_Texture*>mImages;
	float mAnimTimer = 0.0;
	bool animationComplete = false;
};