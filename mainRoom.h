#pragma once
#include "Room.h"
#include "Enemy.h"

class Game;
class mainRoom :
    public Room
{
private:

public:
    char** mainRoomArray;
    int setX, setY;
    mainRoom(int currentStage);
    ~mainRoom();
    char** getMainRoomArray();
    const static int maxEnemy = 50;
    Enemy* enemy[maxEnemy];
    int getMaxEnemy();
    int getX() const;
    int getY() const;
    Enemy** getEnemyList();

};

