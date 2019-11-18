#pragma once
#include "MoveComponent.h"

class PaddleMove :public MoveComponent
{
public:
	PaddleMove(class Actor* owner);
	void Update(float deltaTime) override;

};