#include "Game.h"

Game::Game() {
    currentStage = 0;
    stage = new Stage(this);
}

Game::~Game() {
    delete stage;
}

int Game::getCurrentStage()
{
    return currentStage;
}