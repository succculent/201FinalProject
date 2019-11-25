#include "Item.h"

Item::Item(Game* game, string name, int value, string description):Actor(game)
{
	mName = name;
	coinValue = value;
	mDescription = "You won a " + name + "! " + description;

}

void Item::Update(float deltaTime)
{
	if (mTotalTime > 3.0f)
	{
		mState = EDead;
		return;
	}

	mTotalTime += deltaTime;
	
}