#pragma once
#include <vector>
#include <SDL/SDL_stdinc.h>
#include "Math.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"
#include "Game.h"
class Actor
{
public:
	enum State
	{
		EActive,
		EPaused,
		EDead
	};
	
	Actor(class Game* game);
	virtual ~Actor();


	SpriteComponent* GetSprite();
	void SetSprite(SpriteComponent* sprite);

	// Update function called from Game (not overridable)
	void Update(float deltaTime);
	// Any actor-specific update code (overridable)
	virtual void UpdateActor(float deltaTime);
	// ProcessInput function called from Game (not overridable)
	void ProcessInput(const Uint8* keyState);
	// Any actor-specific update code (overridable)
	virtual void ActorInput(const Uint8* keyState);
	
	// Getters/setters
	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }
	CollisionComponent* GetCollisionComp() { return mCollis; }
	Vector2 GetForward();
	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }
	Game* GetGame() { return mGame; }
	bool UpKey;
	bool DownKey;
	bool RightKey;
	bool LeftKey;

	

protected:
	Game* mGame;
	// Actor's state
	State mState;
	// Transform
	Vector2 mPosition;
	float mScale;
	float mRotation;
	SpriteComponent* mSprite;
	CollisionComponent* mCollis;
};
