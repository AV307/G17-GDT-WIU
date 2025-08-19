#include "Stage.h"
#include "mainRoom.h"
#include "ShopRoom.h"
#include "TreasureRoom.h"
#include "BedRoom.h"
#include "BossRoom.h"

#include "Game.h"

#include <random>
#include <iostream>

void Stage::setStageArray(int currentStage)
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

   if (currentStage == 3 || currentStage == 5)
    {
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
    }
}

Stage::Stage(Game* game)
	: game(game), gen(rd()), dis(1, 3)
{
    int currentStage = game->getCurrentStage();

	rooms[0] = new mainRoom(currentStage);

    int randomRoom1 = dis(gen);
    switch (randomRoom1) 
    {
    case 0:
        rooms[1] = new ShopRoom(currentStage);
        break;
    case 1:
        rooms[1] = new TreasureRoom(currentStage);
        break;
    case 2:
        rooms[1] = new BedRoom(currentStage);
        break;
    }

    if (currentStage == 3 || currentStage == 5) 
    {
        rooms[2] = new BossRoom(currentStage);
    }
    else 
    {
        int randomRoom2 = dis(gen);
        switch (randomRoom2) 
        {
        case 0:
            rooms[2] = new ShopRoom(currentStage);
            break;
        case 1:
            rooms[2] = new TreasureRoom(currentStage);
            break;
        case 2:
            rooms[2] = new BedRoom(currentStage);
            break;
        }
    }

    setStageArray(currentStage);
}

Stage::~Stage() 
{
    for (int i{ 0 }; i <= 2; i++)
    {
        delete rooms[i];
    }
}

void Stage::printStage()
{
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            std::cout << stageArray[i][j];
        }
        std::cout << std::endl;
    }
}
