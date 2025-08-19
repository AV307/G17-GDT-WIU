#include "Stage.h"
#include "mainRoom.h"
#include "ShopRoom.h"
#include "TreasureRoom.h"
#include "BedRoom.h"
#include "BossRoom.h"

#include "Game.h"

#include <random>

void Stage::setStageArray(int currentStage)
{
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

    }
    else
    {

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
        rooms[1] = new ShopRoom;
        break;
    case 1:
        rooms[1] = new TreasureRoom;
        break;
    case 2:
        rooms[1] = new BedRoom;
        break;
    }

    if (currentStage == 3 || currentStage == 5) 
    {
        rooms[2] = new BossRoom;
    }
    else 
    {
        int randomRoom2 = dis(gen);
        switch (randomRoom2) 
        {
        case 0:
            rooms[1] = new ShopRoom;
            break;
        case 1:
            rooms[1] = new TreasureRoom;
            break;
        case 2:
            rooms[1] = new BedRoom;
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