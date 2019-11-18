#include "MoveComponent.h"
#include "Actor.h"

#include <iostream>

MoveComponent::MoveComponent(class Actor* owner)
:Component(owner)
,mAngularSpeed(0.0f)
,mForwardSpeed(0.0f)
{
	
}

void MoveComponent::Update(float deltaTime)
{
	if (mAngularSpeed)
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);

		mAngularSpeed = 0;
	}

	if (mForwardSpeed)
	{
		Vector2 pos = mOwner->GetPosition();
		pos += mOwner->GetForward() * mForwardSpeed * deltaTime * 0.5;
		mOwner->SetPosition(pos);

		mForwardSpeed = 0;
	}
	

}
