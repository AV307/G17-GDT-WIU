#pragma once
#include "Room.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "RoomObjects.h"

#include <random>

class Game;
class Stage
{
private:
    char stageArray[100][100];
    Room* rooms[5];
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

	void printStageWithFOV(Player* player);
    //debug
    void printStage();
};

