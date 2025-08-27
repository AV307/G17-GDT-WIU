#include "mainRoom.h"
#include "Enemy.h"
#include "Game.h"

//Ang Zhi En 252317H
//Constructor for mainRoom, defines the position and sets up the room
//Incomplete
mainRoom::mainRoom(int currentStage) {

    srand(static_cast<unsigned int>(time(0)));
    roomHeight = 30;
    roomWidth = 30;
    roomTopLeftX = 60; // x is row
    roomTopLeftY = 35; // y is col

    roomObjects = new RoomObjects(false, roomTopLeftY, roomWidth, roomHeight);

    // dynamically allocate mainRoomArray
    mainRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++) 
    {
        mainRoomArray[i] = new char[roomWidth];
    }

    roomObjects->addObjects(roomWidth, roomHeight, currentStage, 'M');
    placeRoomObjects(mainRoomArray);

    for (int g = 0; g < maxEnemy; g++) {
        int randX = rand() % 27;
        int randY = rand() % 27;
        if (mainRoomArray[randX][randY] == ' ') {
            Enemy::getInstance().initEnemies(randY, randX, g);
            //mainRoomArray[randY][randX] = ' ';
        }
        else {
            g--;
        }
    }

    //const string theEnemyBank[8] = { "Undead", "Animal", "Flower", "Aquatic", "Vampire", "Humanoid", "Ascendants", "Cubed" };
    //const char theEnemyStatus[4] = { 'B', 'E', 'D', 'X' };
    //int enemyPos[maxEnemy][2];
    //for (int e = 0; e < maxEnemy-1; e++) {
    //    for (int e2 = 0; e2 <= 1; e2++) {
    //        enemyPos[e][e2] = 0;
    //    }
    //}
    //for (int r = 0; r < maxEnemy; r++) {
    //    string setEnemyType = enemyInstance.getEnemyType();
    //    char setEnemyStatus = enemyInstance.getEnemyStatus();
    //    setX = rand() % 27;
    //    setY = rand() % 27;
    //    enemy[r] = new Enemy(setEnemyType, setEnemyStatus);
    //    if (mainRoomArray[enemyInstance.getYPos()][enemyInstance.getXPos()] == ' ') {
    //        enemyPos[r][0] = enemy[r]->setEnemyXR(enemyInstance.getXPos());
    //        enemyPos[r][1] = enemy[r]->setEnemyYR(enemyInstance.getYPos());
    //        mainRoomArray[enemyInstance.getYPos()][enemyInstance.getXPos()] = setEnemyStatus;
    //    }
    //    else {
    //        delete enemy[r];
    //        enemy[r] = nullptr;
    //    }
    //}
    // more code here to determine and set specifics in the main room, based on currentStage
    switch (currentStage) 
    {
    }
}

//Ang Zhi En 252317H
//Destructor for mainRoom, deletes all created pointers
//Incomplete
mainRoom::~mainRoom() {
    // deallocate mainRoomArray
    for (int i{ 0 }; i < roomHeight; i++) 
    {
        delete[] mainRoomArray[i];
    }
    delete[] mainRoomArray;
}

//Ang Zhi En 252317H
//mainRoomArray getter
char** mainRoom::getMainRoomArray()
{
    return mainRoomArray;
}
int mainRoom::getMaxEnemy() {
    return maxEnemy;
}
int mainRoom::getX() const {
    return setX;
}
int mainRoom::getY() const {
    return setY;
}
Enemy* mainRoom::getEnemyList(int num) {
    if (num >= 0 && num < maxEnemy) {
        return enemy[num];
    }
    return nullptr;

}
char mainRoom::getSpecificMainRoomTile(int y, int x) {
    return mainRoomArray[y][x];
}