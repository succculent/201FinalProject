//
//  Game.cpp
//  Game-mac
//
//  Created by Sanjay Madhav on 5/31/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "Game.h"
#include "SDL/SDL.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <SDL/SDL_image.h>
#include "Actor.h"
#include "Random.h"
//#include "Background.h"
#include "SDL/SDL_mixer.h"

using namespace std;

Game::Game()
{

};
bool Game::Initialize()
{
	Random::Init();
	//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);


	lastTime = SDL_GetTicks();
	currentTime = SDL_GetTicks();
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
	
		SDL_Log("Unable to initialize SDL %s", SDL_GetError());
		//if it fails to initialize quit
		return 0;
	}
	
		
	window = SDL_CreateWindow("My Virtual Item Requisition Upgrade Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	int flags = IMG_INIT_PNG;
	int initted = IMG_Init(flags);

	if ((initted&flags) != flags)
	{
		printf("Failed to initialize required png and jpg support!");
		return 0;
	}
	if (window == nullptr || renderer == nullptr)
	{
	
		cout << "oof" << endl;
		return 0;
	}

	
	

	LoadData();

	return 1;
}

void Game::Shutdown()
{
	IMG_Quit();
	UnloadData();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::Loop()
{
	while (gameRunning)
	{
		//process input
		ProcessInput();
		//update game
		UpdateGame();
		//generate outp7ut
		GenerateOutput();

		// infinite loop
	}
	

}

void Game::ProcessInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			gameRunning = false;
		}
		
	}

	const Uint8 *state = SDL_GetKeyboardState(NULL);

	std::vector <Actor*> mVectorTemp = mVector;

	for (int i = 0; i < mVectorTemp.size(); i++)
	{
		mVectorTemp[i]->ProcessInput(state);
	}

	if (state[SDL_SCANCODE_ESCAPE])
	{
		gameRunning = false;
	}
}

void Game::UpdateGame()
{
	currentTime = SDL_GetTicks();

	while (currentTime - lastTime < 16)
	{
		currentTime = SDL_GetTicks();
	}
	
	
	deltaTime = ((float)currentTime-(float)lastTime) / 1000.0f;
	
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	
	//std::cout << deltaTime << std::endl;

	
	lastTime = currentTime;
	//std::cout << deltaTime << std::endl; prints out frames etc. 

	std::vector <Actor*> temp = mVector;
	std::vector <Actor*> dead;

	for (int i = 0; i < temp.size(); i++)
	{
		temp[i]->Update(deltaTime);

		if (temp[i]->GetState() == Actor::State::EDead)
		{
			dead.push_back(temp[i]);
		}
	}

	for (int j = 0; j < dead.size(); j++)
	{
		RemoveActor(dead[j]);

	}


	
}

void Game::GenerateOutput()
{

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
	SDL_RenderClear(renderer);


	for (int i = 0; i < mSprites.size(); i++)
	{
		mSprites[i]->Draw(renderer);
	}
	SDL_RenderPresent(renderer);

}

void Game::AddActor(Actor* a)
{
	mVector.push_back(a);
}
void Game::RemoveActor(Actor* a)
{
	mVector.erase(find(mVector.begin(),mVector.end(), a));

}



void Game::LoadData()
{
	Actor* Background = new Actor(this);
	SpriteComponent* back = new SpriteComponent(Background, 1);
	back->SetTexture(GetTexture("Assets/Background.png"));
	Background->SetSprite(back);
	Background->SetPosition(Vector2(512, 385));
	AddActor(Background);

	Actor* Logo = new Actor(this);
	SpriteComponent* logoSprite = new SpriteComponent(Logo, 2);
	logoSprite->SetTexture(GetTexture("Assets/logo_v1.png"));
	Logo->SetSprite(logoSprite);
	Logo->SetPosition(Vector2(512, 60));
	Logo->SetScale(0.3f);
	AddActor(Logo);
}

void Game::UnloadData()
{
	while (!mVector.empty())
	{
		mVector.pop_back();
	}

}

SDL_Texture* Game::GetTexture(std::string fileName)
{
	if (sprites.find(fileName) != sprites.end())
	{
		return sprites.find(fileName)->second;
	}
	else
	{

		SDL_Surface *image;
		image = IMG_Load(fileName.c_str());

		if (image == NULL)
		{
			printf("Texture not found");
			return 0;
		}

		background = SDL_CreateTextureFromSurface(renderer, image);
		sprites.insert({fileName, background});
		return background;
	}
}

void Game::AddSprite(SpriteComponent* sprite)
{
	mSprites.push_back(sprite);

	std::sort(mSprites.begin(), mSprites.end(), [](SpriteComponent* a, SpriteComponent* b)
	{return a->GetDrawOrder() < b->GetDrawOrder();});
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
	mSprites.erase(find(mSprites.begin(), mSprites.end(), sprite));
}
