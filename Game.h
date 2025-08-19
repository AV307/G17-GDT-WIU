#pragma once
#include "Stage.h"
#include "Player.h"

class Game
{
private:
    Stage* stage;
    int currentStage;
    Player plr;
public:
    Game();
    ~Game();

    int getCurrentStage();
    void updateGame();
};

