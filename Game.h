#pragma once
#include "Stage.h"
#include "Player.h"
#include "CombatSystem.h"

class Game
{
private:
    Stage* stage;
    int currentStage;
	int highestStage;
    Player* plr;

public:
    Game();
    ~Game();

    int getCurrentStage();

    void restartStage(int currentStage);

	void pauseGame();

	void getHighestStage(int currentStage);

    void doTurn(CombatSystem combatsystem);
};

