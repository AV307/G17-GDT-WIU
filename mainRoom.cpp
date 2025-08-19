#include "mainRoom.h"
#include "Game.h"

mainRoom::mainRoom(int currentStage) {
    roomHeight = 60;
    roomWidth = 60;
    roomTopLeftX = 40; // x is row
    roomTopLeftY = 20; // y is col

    // dynamically allocate mainRoomArray
    mainRoomArray = new char* [roomHeight];
    for (int i{ 0 }; i < roomHeight; i++) 
    {
        mainRoomArray[i] = new char[roomWidth];
    }

    // set empty room
    for (int i{ 0 }; i < roomHeight; i++) 
    {
        for (int j{ 0 }; j < roomWidth; j++) 
        {
            if (i == 0 || i == roomHeight - 1 || j == 0 || j == roomWidth - 1) 
            {
                mainRoomArray[i][j] = 'O'; // set to wall
            }
            else 
            {
                mainRoomArray[i][j] = ' '; // set to space
            }
        }
    }

    // more code here to determine and set specifics in the main room
    switch (currentStage) 
    {
    }
}

mainRoom::~mainRoom() {
    // deallocate mainRoomArray
    for (int i{ 0 }; i < roomHeight; i++) 
    {
        delete[] mainRoomArray[i];
    }
    delete[] mainRoomArray;
}

char** mainRoom::getMainRoomArray()
{
    return mainRoomArray;
}
