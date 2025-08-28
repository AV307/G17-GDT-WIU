#pragma once
#include "Stage.h"
#include "Player.h"
#include "CombatSystem.h"
#include "ShopRoom.h"

class Game
{
private:
    int currentStage;
	int highestStage;
    Player* plr;

public:
    Game();
    ~Game();

    Stage* stage;
    Entity* currentEnemies;
	Entity* getCurrentEnemy();
    int getCurrentStage();

    void printStartMenu();
    void printBriefingMenu();

    void restartStage(int currentStage);
    void advanceStage();

	void pauseGame();

	void getHighestStage(int currentStage);

    void doTurn(CombatSystem combatsystem);
};

