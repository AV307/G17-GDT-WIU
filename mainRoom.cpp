#include "mainRoom.h"
#include "Enemy.h"
#include "Game.h"

//Ang Zhi En 252317H
//Constructor for mainRoom, defines the position and sets up the room
//Incomplete
mainRoom::mainRoom(int currentStage) {


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
    // more code here to determine and set specifics in the main room, based on curentStage
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
