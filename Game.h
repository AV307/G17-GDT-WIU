#pragma once
#include "Stage.h"

class Game
{
private:
    Stage* stage;
    int currentStage;
public:
    Game();
    ~Game();

    int getCurrentStage();
};

