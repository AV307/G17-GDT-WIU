#pragma once
#include "Room.h"
#include "Player.h"
#include "RoomObjects.h"

#include <random>

class Game;
class Stage
{
private:
    char stageArray[100][100];
    Room* rooms[4];
    Game* game;

    char previousTile;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
public:
    void setStageArray(int currentStage, char room1, char room2, Player* player);

    Stage(Game* game, Player* player);
    ~Stage();

    void updateStageArray(Player* player);
    //bool checkCollision(int xPos, int yPos, int currentRoom);

    //debug
    void printStage();
};

