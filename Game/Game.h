#pragma once
#include "SDL.h"
#include <vector>
#include <unordered_map>
#include "SpriteComponent.h"
#include "SDL_ttf.h"
#include <string>
using namespace std;




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
	string BoxInProgress = "";
	bool Box1inProgress = false;
	bool Box2inProgress = false;
	bool Box3inProgress = false;
	void ItemMessage(string itemName, string desc);
	void RemoveItemMessage();
	Player* GetPlayer()
	{
		return mButton;
	}
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

	SDL_Texture* GameMessage;
	SDL_Rect GameMessage_rect;
	SDL_Surface* surfaceMessage3;
	int * w = new int();
	int* h = new int();
	

	bool gameRunning = true;

	std::vector<Actor*> mVector;
	std::vector<LootBox*> mBox;
	Player* mButton;
	std::unordered_map<std::string, SDL_Texture*> sprites;
	std::vector <SpriteComponent*> mSprites;
	SDL_Texture* background;

};