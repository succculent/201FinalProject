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
#include "NormalLootBox.h"
#include "UltraLootBox.h"
#include "PrestigeLootBox.h"
#include "Player.h"
//#include "Background.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <sstream>



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
	if (TTF_Init() != 0)
	{
		SDL_Log("Couldn't initialize TTF lib: ", TTF_GetError());
		return 1;

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

	
	OpenFont = TTF_OpenFont("Assets/Minecraft.ttf", 20);

	if (!OpenFont) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
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
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	while (SDL_PollEvent(&event))
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		if (event.type == SDL_QUIT)
		{
			gameRunning = false;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && mButton->GetCollisionComp()->Intersect(Vector2(x, y)));
		{
			mButton->clicked = true;
		}
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			mButton->clickedFirst = true;
		}


		
	}


	std::vector <Actor*> mVectorTemp = mVector;

	for (int i = 0; i < mVectorTemp.size(); i++)
	{
		mVectorTemp[i]->ProcessInput(state);
	}

	for (int i = 0; i < mBox.size(); i++)
	{
		mBox[i]->ProcessInput(state);
	}

	mButton->ProcessInput(state);
	
	

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

	for (int i = 0; i < mBox.size(); i++)
	{
		mBox[i]->Update(deltaTime);
	}


	mButton->Update(deltaTime);
	

	for (int j = 0; j < dead.size(); j++)
	{
		RemoveActor(dead[j]);

	}

	stringstream strs;
	strs << mButton->getBalance();
	string temp_str = strs.str();
	char* char_type = (char*)temp_str.c_str();


	surfaceMessage1 = TTF_RenderText_Solid(OpenFont, char_type, Black);
	TTF_SizeText(OpenFont, char_type, w, h);
	BalanceUpdate = SDL_CreateTextureFromSurface(renderer, surfaceMessage1);
	
	BalanceUpdate_rect.x = 205;
	BalanceUpdate_rect.y = 68;
	BalanceUpdate_rect.w = *w;
	BalanceUpdate_rect.h = *h;
}

void Game::GenerateOutput()
{

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
	SDL_RenderClear(renderer);

	for (int i = 0; i < mSprites.size(); i++)
	{
		mSprites[i]->Draw(renderer);
	}
	SDL_RenderCopy(renderer, BalanceUpdate, NULL, &BalanceUpdate_rect);
	SDL_RenderCopy(renderer, PassiveUpdate, NULL, &PassiveUpdate_rect);


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

	// loot box sprites: https://bayat.itch.io/platform-game-assets?download
	NormalLootBox* Box1 = new NormalLootBox(this);
	Box1->SetPosition(Vector2(175, 250));
	//AddActor(Box1);
	mBox.push_back(Box1);

	UltraLootBox* Box2 = new UltraLootBox(this);
	Box2->SetPosition(Vector2(512, 250));
	AddActor(Box2);
	mBox.push_back(Box2);

	PrestigeLootBox* Box3 = new PrestigeLootBox(this);
	Box3->SetPosition(Vector2(849, 250));
	AddActor(Box3);
	mBox.push_back(Box3);
	
	Actor* Box1Text = new Actor(this);
	SpriteComponent * Box1TextSprite = new SpriteComponent(Box1Text, 3);
	Box1TextSprite->SetTexture(GetTexture("Assets/normalboxtext.png"));
	Box1Text->SetSprite(Box1TextSprite);
	Box1Text->SetPosition(Vector2(175, 430));
	AddActor(Box1Text);

	Actor* Box2Text = new Actor(this);
	SpriteComponent * Box2TextSprite = new SpriteComponent(Box2Text, 3);
	Box2TextSprite->SetTexture(GetTexture("Assets/ultraboxtext.png"));
	Box2Text->SetSprite(Box2TextSprite);
	Box2Text->SetPosition(Vector2(512, 430));
	AddActor(Box2Text);

	Actor* Box3Text = new Actor(this);
	SpriteComponent * Box3TextSprite = new SpriteComponent(Box3Text, 3);
	Box3TextSprite->SetTexture(GetTexture("Assets/prestigeboxtext.png"));
	Box3Text->SetSprite(Box3TextSprite);
	Box3Text->SetPosition(Vector2(849, 430));
	AddActor(Box3Text);

	Actor* Balance = new Actor(this);
	SpriteComponent * BalanceSprite = new SpriteComponent(Balance, 3);
	BalanceSprite->SetTexture(GetTexture("Assets/balance.png"));
	Balance->SetSprite(BalanceSprite);
	Balance->SetPosition(Vector2(125, 75));
	Balance->SetScale(0.5f);
	AddActor(Balance);

	Actor* Passive = new Actor(this);
	SpriteComponent * PassiveSprite = new SpriteComponent(Passive, 3);
	PassiveSprite->SetTexture(GetTexture("Assets/coinpersecond.png"));
	Passive->SetSprite(PassiveSprite);
	Passive->SetPosition(Vector2(800, 75));
	Passive->SetScale(0.5f);
	AddActor(Passive);


	mButton = new Player(this);
	AddActor(mButton);

	stringstream strs;
	strs << balanceNum;
	string temp_str = strs.str();
	char* char_type = (char*)temp_str.c_str();

	surfaceMessage1 = TTF_RenderText_Solid(OpenFont, char_type, Black);
	TTF_SizeText(OpenFont, char_type, w, h);
	BalanceUpdate = SDL_CreateTextureFromSurface(renderer, surfaceMessage1);

	BalanceUpdate_rect.x = 205;
	BalanceUpdate_rect.y = 68;
	BalanceUpdate_rect.w = *w;
	BalanceUpdate_rect.h = *h;
	
	strs.str(std::string());
	strs << passiveNum;
	temp_str = "";
	temp_str = strs.str();
	char_type = (char*)temp_str.c_str();
	
	surfaceMessage2 = TTF_RenderText_Solid(OpenFont, char_type, Black);
	TTF_SizeText(OpenFont, char_type, w, h);
	PassiveUpdate = SDL_CreateTextureFromSurface(renderer, surfaceMessage2);

	PassiveUpdate_rect.x = 900;
	PassiveUpdate_rect.y = 68;
	PassiveUpdate_rect.w = *w;
	PassiveUpdate_rect.h = *h;

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
