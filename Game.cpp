#include "Game.h"

Game::Game() {
    for (int i = 0; i < 5; i++) {
        stages[i] = new Stage();
    }

    currentStage = 0;
}

Game::~Game() {
    for (int i = 0; i < 5; i++) {
        delete stages[i];
    }
}
