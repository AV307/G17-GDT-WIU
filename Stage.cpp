#include "Stage.h"
#include "mainRoom.h"
#include "ShopRoom.h"
#include "TreasureRoom.h"
#include "BedRoom.h"
#include "BossRoom.h"
#include "PortalRoom.h"
#include "RoomObjects.h"

#include "Game.h"

#include <random>
#include <iostream>

//Ang Zhi En 252317H
//set the stageArray, fill up stage area with all the rooms that are created for the currentStage
//Incomplete
void Stage::setStageArray(int currentStage, char room1, char room2, Player* player)
{
    // initialize stageArray to spaces
    for (int i{ 0 }; i < 100; i++) {
        for (int j{ 0 }; j < 100; j++) {
            stageArray[i][j] = '-'; //debugging purposes set to '-', will be space when done
        }
    }

    // set the mainRoom into the stage
    char** mainRoomArray = static_cast<mainRoom*>(rooms[0])->getMainRoomArray();
    int mainRoomTopLeftX = rooms[0]->getRoomTopLeftX();
    int mainRoomTopLeftY = rooms[0]->getRoomTopLeftY();
    for (int i{ 0 }; i < rooms[0]->getRoomHeight(); i++)
    {
        for (int j{ 0 }; j < rooms[0]->getRoomWidth(); j++)
        {
            stageArray[mainRoomTopLeftX + i][mainRoomTopLeftY + j] = mainRoomArray[i][j];
        }
    }

    // sets whatever room is randomly generated into the stage for room1
    switch (room1)
    {
    case 'S': {
        // set shopRoom into stage
        char** shopRoomArray{ static_cast<ShopRoom*>(rooms[1])->getShopRoomArray() };
        int shopRoomTopLeftX{ rooms[1]->getRoomTopLeftX() };
        int shopRoomTopLeftY{ rooms[1]->getRoomTopLeftY() };
        for (int i{ 0 }; i < rooms[1]->getRoomHeight(); i++)
        {
            for (int j{ 0 }; j < rooms[1]->getRoomWidth(); j++)
            {
                stageArray[shopRoomTopLeftX + i][shopRoomTopLeftY + j] = shopRoomArray[i][j];
            }
        }
        break;
    }
    case 'T': {
        // set treasureRoom into stage
        char** treasureRoomArray{ static_cast<TreasureRoom*>(rooms[1])->getTreasureRoomArray() };
        int treasureRoomTopLeftX{ rooms[1]->getRoomTopLeftX() };
        int treasureRoomTopLeftY{ rooms[1]->getRoomTopLeftY() };
        for (int i{ 0 }; i < rooms[1]->getRoomHeight(); i++)
        {
            for (int j{ 0 }; j < rooms[1]->getRoomWidth(); j++)
            {
                stageArray[treasureRoomTopLeftX + i][treasureRoomTopLeftY + j] = treasureRoomArray[i][j];
            }
        }
        break;
    }
    case 'B': {
        // set bedRoom into stage
        char** bedRoomArray{ static_cast<BedRoom*>(rooms[1])->getBedRoomArray() };
        int bedRoomTopLeftX{ rooms[1]->getRoomTopLeftX() };
        int bedRoomTopLeftY{ rooms[1]->getRoomTopLeftY() };
        for (int i{ 0 }; i < rooms[1]->getRoomHeight(); i++)
        {
            for (int j{ 0 }; j < rooms[1]->getRoomWidth(); j++)
            {
                stageArray[bedRoomTopLeftX + i][bedRoomTopLeftY + j] = bedRoomArray[i][j];
            }
        }
        break;
    }
    }

    // sets whatever room is randomly generated (or the bossRoom for stage 3 and 5) into the stage for room2
    switch (room2)
    {
    case 'S': {
        // set shopRoom into stage
        char** shopRoomArray{ static_cast<ShopRoom*>(rooms[2])->getShopRoomArray() };
        int shopRoomTopLeftX{ rooms[2]->getRoomTopLeftX() };
        int shopRoomTopLeftY{ rooms[2]->getRoomTopLeftY() };
        for (int i{ 0 }; i < rooms[2]->getRoomHeight(); i++)
        {
            for (int j{ 0 }; j < rooms[2]->getRoomWidth(); j++)
            {
                stageArray[shopRoomTopLeftX + i][shopRoomTopLeftY + j] = shopRoomArray[i][j];
            }
        }
        break;
    }
    case 'T': {
        // set treasureRoom into stage
        char** treasureRoomArray{ static_cast<TreasureRoom*>(rooms[2])->getTreasureRoomArray() };
        int treasureRoomTopLeftX{ rooms[2]->getRoomTopLeftX() };
        int treasureRoomTopLeftY{ rooms[2]->getRoomTopLeftY() };
        for (int i{ 0 }; i < rooms[2]->getRoomHeight(); i++)
        {
            for (int j{ 0 }; j < rooms[2]->getRoomWidth(); j++)
            {
                stageArray[treasureRoomTopLeftX + i][treasureRoomTopLeftY + j] = treasureRoomArray[i][j];
            }
        }
        break;
    }
    case 'B': {
        // set bedRoom into stage
        char** bedRoomArray{ static_cast<BedRoom*>(rooms[2])->getBedRoomArray() };
        int bedRoomTopLeftX{ rooms[2]->getRoomTopLeftX() };
        int bedRoomTopLeftY{ rooms[2]->getRoomTopLeftY() };
        for (int i{ 0 }; i < rooms[2]->getRoomHeight(); i++)
        {
            for (int j{ 0 }; j < rooms[2]->getRoomWidth(); j++)
            {
                stageArray[bedRoomTopLeftX + i][bedRoomTopLeftY + j] = bedRoomArray[i][j];
            }
        }
        break;
    }
    case 'F': {
        // set the bossRoom into the stage
        char** bossRoomArray{ static_cast<BossRoom*>(rooms[2])->getBossRoomArray() };
        int bossRoomTopLeftX{ rooms[2]->getRoomTopLeftX() };
        int bossRoomTopLeftY{ rooms[2]->getRoomTopLeftY() };
        for (int i{ 0 }; i < rooms[2]->getRoomHeight(); i++)
        {
            for (int j{ 0 }; j < rooms[2]->getRoomWidth(); j++)
            {
                stageArray[bossRoomTopLeftX + i][bossRoomTopLeftY + j] = bossRoomArray[i][j];
            }
        }
        break;
    }
    }

    // set the portalRoom into the stage
    char** portalRoomArray = static_cast<PortalRoom*>(rooms[3])->getPortalRoomArray();
    int portalRoomTopLeftX = rooms[3]->getRoomTopLeftX();
    int portalRoomTopLeftY = rooms[3]->getRoomTopLeftY();
    for (int i{ 0 }; i < rooms[3]->getRoomHeight(); i++)
    {
        for (int j{ 0 }; j < rooms[3]->getRoomWidth(); j++)
        {
            stageArray[portalRoomTopLeftX + i][portalRoomTopLeftY + j] = portalRoomArray[i][j];
        }
    }

    int playerXPos = player->getXPos();
    int playerYPos = player->getYPos();

    stageArray[playerYPos][playerXPos] = 'P';
}

//Ang Zhi En 252317H
//Constructor for Stage, uses randomiser to decide on the rooms generated for currentStage
//Incomplete
Stage::Stage(Game* game, Player* player)
	: gen(rd()), dis(1, 3)
{
    int currentStage{ game->getCurrentStage() };

	rooms[0] = new mainRoom(currentStage);

    int randomRoom1{ dis(gen) };

    char room1{};
    char room2{};
    switch (randomRoom1)
    {
    case 1:
        rooms[1] = new ShopRoom(currentStage, 1);
        room1 = 'S';
        break;
    case 2:
        rooms[1] = new TreasureRoom(currentStage, 1);
        room1 = 'T';
        break;
    case 3:
        rooms[1] = new BedRoom(currentStage, 1);
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
        case 1:
            rooms[2] = new ShopRoom(currentStage, 2);
            room2 = 'S';
            break;
        case 2:
            rooms[2] = new TreasureRoom(currentStage, 2);
            room2 = 'T';
            break;
        case 3:
            rooms[2] = new BedRoom(currentStage, 2);
            room2 = 'B';
            break;
        }
    }

    rooms[3] = new PortalRoom(currentStage, 3);

    previousTile = ' ';

    setStageArray(currentStage, room1, room2, player);
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

void Stage::updateStageArray(Player* player)
{
    int playerXPos = player->getXPos();
    int playerYPos = player->getYPos();

    stageArray[playerYPos][playerXPos] = previousTile;

    player->doAction();

    RoomObjects* objects = rooms[0]->getRoomObjects();
    ObjectType type = SPACE;
    bool toggled = false;

    int roomX = player->getXPos() - rooms[0]->getRoomTopLeftY();
    int roomY = player->getYPos() - rooms[0]->getRoomTopLeftX();

    if (player->getYPos() >= rooms[0]->getRoomTopLeftX() && 
        player->getYPos() < rooms[0]->getRoomTopLeftX() + rooms[0]->getRoomWidth() &&
        player->getXPos() >= rooms[0]->getRoomTopLeftY() && 
        player->getXPos() < rooms[0]->getRoomTopLeftY() + rooms[0]->getRoomHeight()) 
    {
        type = objects->getObjectType(roomX, roomY);
        toggled = objects->getObjectToggle(roomX, roomY);
    }

    int offsetsX[4] = { -1,1,0,0 };
    int offsetsY[4] = { 0,0,-1,1 };

    {
        bool blocked = false;

        if (type == WALL || (type == DOOR && toggled == false) || type == SWITCH || type == CHEST || stageArray[player->getYPos()][player->getXPos()] == '#') {
            blocked = true;
        }

        if (blocked == false) {
            playerXPos = player->getXPos();
            playerYPos = player->getYPos();
        }
    }

    {
        if (player->getAction() == "Interact") {
            for (int i = 0; i < 3; i++) {
                int xPos = playerXPos + offsetsX[i];
                int yPos = playerYPos + offsetsY[i];

                switch (type) {

                case SWITCH:
                    int switchID = objects->getObjectId(xPos - rooms[0]->getRoomTopLeftY(), yPos - rooms[0]->getRoomTopLeftX());
                    for (int y = 0; y < rooms[0]->getRoomHeight(); y++) {
                        for (int x = 0; x < rooms[0]->getRoomWidth(); x++) {
                            if (objects->getObjectType(x, y) == DOOR &&
                                objects->getObjectId(x, y) == switchID)
                            {
                                bool doorToggle = objects->getObjectToggle(x, y);
                                objects->setObjectToggle(x, y, !doorToggle);
                            }
                        }
                    }
                    break;
                case CHEST:
                    break;
                }
            }
        }
    }

    player->setXPos(playerXPos);
    player->setYPos(playerYPos);

    previousTile = stageArray[playerYPos][playerXPos];

    stageArray[playerYPos][playerXPos] = 'P';
}

//bool Stage::checkCollision(int xPos, int yPos, int currentRoom)
//{
//    RoomObjects* objects = rooms[currentRoom]->getRoomObjects();
//    if (objects->getObjectType(xPos - rooms[currentRoom]->getRoomWidth(), yPos- rooms[currentRoom]->getRoomHeight()) != WALL) {
//        return true;
//    }
//    return false;
//}

//Ang Zhi En 252317H
//Print out the stage, with the rooms inside
//Debugging function, will not be used (player will have fov in final game)
void Stage::printStage()
{
    for (int i{ 0 }; i < 100; i++) {
        for (int j{ 0 }; j < 100; j++) {
            std::cout << stageArray[i][j];
        }
        std::cout << std::endl;
    }
}

