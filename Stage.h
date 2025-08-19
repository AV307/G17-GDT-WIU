#pragma once
#include "Room.h"
#include <random>

class Game;
class Stage
{
private:
    char stageArray[100][100];
    Room* rooms[3];
    Game* game;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
public:
    void setStageArray(int currentStage, char room1, char room2);

    Stage(Game* game);
    ~Stage();

    //debug
    void printStage();
};

