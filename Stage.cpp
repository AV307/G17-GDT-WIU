#include "Stage.h"
#include "mainRoom.h"
#include "ShopRoom.h"
#include "TreasureRoom.h"
#include "BedRoom.h"
#include "BossRoom.h"

#include "Game.h"

#include <random>
#include <iostream>

//Ang Zhi En 252317H
//set the stageArray, fill up stage area with all the rooms that are created for the currentStage
//Incomplete
void Stage::setStageArray(int currentStage, char room1, char room2)
{
    // initialize stageArray to spaces
    for (int i{ 0 }; i < 100; i++) {
        for (int j{ 0 }; j < 100; j++) {
            stageArray[i][j] = '-';
        }
    }

    // set the mainRoom into the stage
    char** mainRoomArray = static_cast<mainRoom*>(rooms[0])->getMainRoomArray();
    int mainRoomTopLeftX = rooms[0]->getRoomTopLeftX();
    int mainRoomTopLeftY = rooms[0]->getRoomTopLeftY();
    for (int i = 0; i < rooms[0]->getRoomHeight(); i++)
    {
        for (int j = 0; j < rooms[0]->getRoomWidth(); j++)
        {
            stageArray[mainRoomTopLeftX + i][mainRoomTopLeftY + j] = mainRoomArray[i][j];
        }
    }

    switch (room1)
    {
    case 'S':
        // set shopRoom into stage

        break;
    case 'T':
        // set treasureRoom into stage

        break;
    case 'B':
        // set bedRoom into stage

        break;
    }
    switch (room2)
    {
    case 'S':
        break;
    case 'T':
        break;
    case 'B':
        break;
    case 'F':
        // set the bossRoom into the stage
        char** bossRoomArray = static_cast<BossRoom*>(rooms[2])->getBossRoomArray();
        int bossRoomTopLeftX = rooms[2]->getRoomTopLeftX();
        int bossRoomTopLeftY = rooms[2]->getRoomTopLeftY();
        for (int i = 0; i < rooms[2]->getRoomHeight(); i++)
        {
            for (int j = 0; j < rooms[2]->getRoomWidth(); j++)
            {
                stageArray[bossRoomTopLeftX + i][bossRoomTopLeftY + j] = bossRoomArray[i][j];
            }
        }

        break;
    }
}

//Ang Zhi En 252317H
//Constructor for Stage, uses randomiser to decide on the rooms generated for currentStage
//Incomplete
Stage::Stage(Game* game)
	: game(game), gen(rd()), dis(1, 3)
{
    int currentStage = game->getCurrentStage();

	rooms[0] = new mainRoom(currentStage);

    int randomRoom1 = dis(gen);

    char room1{};
    char room2{};
    switch (randomRoom1) 
    {
    case 0:
        rooms[1] = new ShopRoom(currentStage);
        room1 = 'S';
        break;
    case 1:
        rooms[1] = new TreasureRoom(currentStage);
        room1 = 'T';
        break;
    case 2:
        rooms[1] = new BedRoom(currentStage);
        room1 = 'B';
        break;
    }

    if (currentStage == 3 || currentStage == 5) 
    {
        rooms[2] = new BossRoom(currentStage);
        room2 = 'F';
    }
    else 
    {
        int randomRoom2 = dis(gen);
        switch (randomRoom2) 
        {
        case 0:
            rooms[2] = new ShopRoom(currentStage);
            room2 = 'S';
            break;
        case 1:
            rooms[2] = new TreasureRoom(currentStage);
            room2 = 'T';
            break;
        case 2:
            rooms[2] = new BedRoom(currentStage);
            room2 = 'B';
            break;
        }
    }

    setStageArray(currentStage, room1, room2);
}

//Ang Zhi En 252317H
//Destructor for stage, delete pointers
//Incomplete
Stage::~Stage() 
{
    for (int i{ 0 }; i <= 2; i++)
    {
        delete rooms[i];
    }
}

//Ang Zhi En 252317H
//Print out the stage, with the rooms inside
//Debugging function, will not be used (player will have fov in final game)
void Stage::printStage()
{
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            std::cout << stageArray[i][j];
        }
        std::cout << std::endl;
    }
}
