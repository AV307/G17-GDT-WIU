#include "mainRoom.h"
#include "Game.h"

mainRoom::mainRoom(int currentStage)
    : game(game)
{
    roomHeight = 60;
    roomWidth = 60;
    roomTopLeftX = 41;
    roomTopLeftY = 21;
    // set empty room
    for (int i{ 0 }; i < 60; i++) 
    {
        for (int j{ 0 }; j < 60; j++) 
        {
            if (i == 0 || i == 59 || j == 0 || j == 59) 
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

mainRoom::~mainRoom()
{
}
