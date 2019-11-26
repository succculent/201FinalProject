#pragma once
#include <SDL_stdinc.h>
#include "SDL.h"

class Component
{
public:
	// Constructor
	Component(class Actor* owner);
	// Destructor
	virtual ~Component();
	// Update this component by delta time
	virtual void Update(float deltaTime);
	//void AddImages(SDL_Texture* texture);
	// Process input for this component (if needed)
	virtual void ProcessInput(const Uint8* keyState);
protected:
	// Owning actor
	class Actor* mOwner;
};
