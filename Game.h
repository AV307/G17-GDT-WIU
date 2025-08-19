#pragma once
#include "Stage.h"

class Game
{
private:
    Stage* stages[5];
    int currentStage;
public:
    Game();
    ~Game();
};

