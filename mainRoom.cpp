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

    const string theEnemyBank[8] = { "Undead", "Animal", "Flower", "Aquatic", "Vampire", "Humanoid", "Ascendants", "Cubed" };
    const char theEnemyStatus[4] = { 'B', 'E', 'D', 'X' };
    for (int r = 0; r < maxEnemy; r++) {
        string setEnemyType = theEnemyBank[(rand() % 8)];
        char setEnemyStatus = theEnemyStatus[(rand() % 3)];
        setX = rand() % 27;
        setY = rand() % 27;
        if (mainRoomArray[setY][setX] == ' ') {
            enemy[r] = new Enemy(setEnemyType, setEnemyStatus);
            enemy[r]->setEnemyXR(setX);
            enemy[r]->setEnemyYR(setY);
            mainRoomArray[setY][setX] = setEnemyStatus;
        }
        else {
            delete enemy[r];
            enemy[r] = nullptr;
        }
    }
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
Enemy** mainRoom::getEnemyList() {
    return enemy;
}
