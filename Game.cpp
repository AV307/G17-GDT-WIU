#include "Game.h"

Game::Game() {
    for (int i = 0; i < 5; i++) {
        stages[i] = new Stage();
    }
}

Game::~Game() {
    for (int i = 0; i < 5; i++) {
        delete stages[i];
    }
}
