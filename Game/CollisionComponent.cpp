<<<<<<< HEAD
#include "CollisionComponent.h"
#include "Actor.h"
#include <iostream>

CollisionComponent::CollisionComponent(class Actor* owner)
:Component(owner)
,mWidth(0.0f)
,mHeight(0.0f)
=======
#include "CollisionComponent.h"	
#include "Actor.h"	
#include <iostream>	

CollisionComponent::CollisionComponent(class Actor* owner)
	:Component(owner)
	, mWidth(0.0f)
	, mHeight(0.0f)
>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4
{

}

CollisionComponent::~CollisionComponent()
{
<<<<<<< HEAD
	
=======

>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4
}

bool CollisionComponent::Intersect(Vector2 other)
{

	bool case1 = (GetMax().x > other.x);
	bool case2 = (other.x > GetMin().x);
	bool case3 = (GetMax().y > other.y);
	bool case4 = (other.y > GetMin().y);
<<<<<<< HEAD
	//std::cout << case1 << case2 << case3 << case4 << std::endl;
	if ( case1 && case2 && case3 && case4 )
=======
	//std::cout << case1 << case2 << case3 << case4 << std::endl;	
	if (case1 && case2 && case3 && case4)
>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4
	{
		return true;
	}
	return false;
}

Vector2 CollisionComponent::GetMin() const
{
	float min_x = GetCenter().x - (mWidth) / 2.0f;
	float min_y = GetCenter().y - (mHeight) / 2.0f;
<<<<<<< HEAD
	return Vector2(min_x,min_y);
=======
	return Vector2(min_x, min_y);
>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4
}

Vector2 CollisionComponent::GetMax() const
{
	float max_x = GetCenter().x + (mWidth) / 2.0f;
	float max_y = GetCenter().y + (mHeight) / 2.0f;


<<<<<<< HEAD
	return Vector2(max_x,max_y);
=======
	return Vector2(max_x, max_y);
>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4
}

const Vector2& CollisionComponent::GetCenter() const
{
<<<<<<< HEAD
		return mOwner->GetPosition();
}

=======
	return mOwner->GetPosition();
}
>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4
