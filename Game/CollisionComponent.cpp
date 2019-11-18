#include "CollisionComponent.h"
#include "Actor.h"

CollisionComponent::CollisionComponent(class Actor* owner)
:Component(owner)
,mWidth(0.0f)
,mHeight(0.0f)
{

}

CollisionComponent::~CollisionComponent()
{
	
}

bool CollisionComponent::Intersect(const CollisionComponent* other)
{
	bool case1 = (GetMax().x < other->GetMin().x);
	bool case2 = (other->GetMax().x < GetMin().x);
	bool case3 = (GetMax().y < other->GetMin().y);
	bool case4 = (other->GetMax().y < GetMin().y);
	
	if ( !case1 && !case2 && !case3 && !case4 )
	{
		return true;
	}
	// TODO: Implement
	return false;
}

Vector2 CollisionComponent::GetMin() const
{
	float min_x = GetCenter().x - (mWidth) / 2.0f;
	float min_y = GetCenter().y - (mHeight) / 2.0f;
	// TODO: Implement
	return Vector2(min_x,min_y);
}

Vector2 CollisionComponent::GetMax() const
{
	float max_x = GetCenter().x + (mWidth) / 2.0f;
	float max_y = GetCenter().y + (mHeight) / 2.0f;


	// TODO: Implement
	return Vector2(max_x,max_y);
}

const Vector2& CollisionComponent::GetCenter() const
{
	return mOwner->GetPosition();
}

