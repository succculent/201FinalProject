<<<<<<< HEAD
#pragma once
#include "Component.h"
#include "Math.h"
=======
#pragma once	
#include "Component.h"	
#include "Math.h"	
>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4

class CollisionComponent : public Component
{
public:
	CollisionComponent(class Actor* owner);
	~CollisionComponent();

<<<<<<< HEAD
	// Set width/height of this box
=======
	// Set width/height of this box	
>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4
	void SetSize(float width, float height)
	{
		mWidth = width;
		mHeight = height;
	}

<<<<<<< HEAD
	// Returns true if this box intersects with other
	bool Intersect(Vector2 other);

	// Get min and max points of box
	Vector2 GetMin() const;
	Vector2 GetMax() const;

	// Get width, height, center of box
=======
	// Returns true if this box intersects with other	
	bool Intersect(Vector2 other);

	// Get min and max points of box	
	Vector2 GetMin() const;
	Vector2 GetMax() const;

	// Get width, height, center of box	
>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4
	const Vector2& GetCenter() const;
	float GetWidth() const { return mWidth; }
	float GetHeight() const { return mHeight; }
private:
	float mWidth;
	float mHeight;
<<<<<<< HEAD
};

=======
}; 
>>>>>>> 4c1b866075d8f0d7c2556e1f4b6502966e25beb4
