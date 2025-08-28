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

    bool bossDefeated;

    char previousTile;
    std::string signMessage;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
public:
	int roomX, roomY;
    void setStageArray(int currentStage, char room1, char room2, Player* player);

	Stage();
    Stage(Game* game, Player* player);
    ~Stage();
    void updateStageArray(Player* player, Game* game);
    //bool checkCollision(int xPos, int yPos, int currentRoom);

	void printStageWithFOV(Player* player, int currentStage);
    bool playerNearInteractable(Player* player);
    //debug
    void printStage();
    Enemy enemyInstance;
    int getRoomX() { return roomX; };
    int getRoomY() { return roomY; };

    void setBossDefeated(bool val);
};

class EnemyManager {
public:
    Enemy* enemies[mainRoom::maxEnemy];
    Enemy** getEnemyPos() { return enemies; }
};
