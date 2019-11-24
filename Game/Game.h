#pragma once
#include "SDL/SDL.h"
#include <vector>
#include <unordered_map>
#include "SpriteComponent.h"
#include "SDL/SDL_ttf.h"




class Actor;
class LootBox;
class Player;
// TODO
class Game {
	public:
	Game();
	bool Initialize();
	void Shutdown();
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void Loop();
	void AddActor(Actor* a);
	void RemoveActor(Actor* a);
	void LoadData();
	void UnloadData();
	void AddSprite(SpriteComponent* sprite);
	void RemoveSprite(SpriteComponent* sprite);

	SDL_Texture* GetTexture(std::string fileName);

	private:
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 768;
	SDL_Window *window;
	SDL_Renderer *renderer;


	unsigned int lastTime = 0;
	unsigned int currentTime;
	
	float deltaTime;
	int num_ticks;
	
	bool movingUp = false;
	bool movingDown = false;
	
	SDL_Color Black = { 0,0,0 };
	TTF_Font* OpenFont; 
	
	int balanceNum = 0;
	int passiveNum = 0;

	SDL_Texture* BalanceUpdate;
	SDL_Rect BalanceUpdate_rect;
	SDL_Surface* surfaceMessage1;

	SDL_Texture* PassiveUpdate;
	SDL_Rect PassiveUpdate_rect;
	SDL_Surface* surfaceMessage2;
	int * w = new int();
	int* h = new int();
	

	bool gameRunning = true;

	std::vector<Actor*> mVector;
	std::vector<LootBox*> mBox;
	std::vector<Player*> mButton;
	std::unordered_map<std::string, SDL_Texture*> sprites;
	std::vector <SpriteComponent*> mSprites;
	SDL_Texture* background;

};