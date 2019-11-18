#include "PaddleMove.h"
#include "Actor.h"

PaddleMove::PaddleMove(class Actor* owner) :MoveComponent(owner)
{

}

void PaddleMove::Update(float deltaTime)
{
	MoveComponent::Update(deltaTime);

	if (mOwner->GetPosition().x > 935)
	{
		mOwner->SetPosition(Vector2(935, mOwner->GetPosition().y));
	}

	if (mOwner->GetPosition().x < 90)
	{
		mOwner->SetPosition(Vector2(90, mOwner->GetPosition().y));
	}

	
}
