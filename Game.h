#pragma once
#include "Stage.h"
#include "Player.h"

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

    void doTurn();

    void restartStage(int currentStage);

	void pauseGame();

	void getHighestStage(int currentStage);

};

