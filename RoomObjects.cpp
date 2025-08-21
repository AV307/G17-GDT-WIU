#include "RoomObjects.h"

RoomObjects::RoomObjects(int roomWidth, int roomHeight)
{
    objects = new ObjectType * [roomHeight];
    for (int i = 0; i < roomHeight; i++) {
        objects[i] = new ObjectType[roomWidth];
    }

    // creates empty room with walls
    for (int i{ 0 }; i < roomHeight; i++)
    {
        for (int j{ 0 }; j < roomWidth; j++)
        {
            if (i == 0 || i == roomHeight - 1 || j == 0 || j == roomWidth - 1)
            {
                objects[i][j] = WALL; // set to wall
            }
            else
            {
                objects[i][j] = SPACE; // set to space
            }
        }
    }
}

RoomObjects::~RoomObjects()
{
}


void RoomObjects::addObjects(int currentStage, char roomType)
{
    // essentially presets for the rooms
    switch (roomType)
    {
    case 'M': // main room
        switch (currentStage)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        }
        break;
    case 'B': // bed room
        break;
    case 'S': // shop room
        break;
    case 'F': // boss room
        switch (currentStage)
        {
        case 3:
            break;
        case 5:
            break;
        }
        break;
    case 'P': // portal room
        break;
    }
}

void RoomObjects::removeObject(int xCoord, int yCoord)
{
    objects[xCoord][yCoord] = SPACE;
}

ObjectType RoomObjects::getObjectType(int xCoord, int yCoord)
{
    return objects[xCoord][yCoord];
}