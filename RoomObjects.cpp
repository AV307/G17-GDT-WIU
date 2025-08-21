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
}

void RoomObjects::removeObject(int xCoord, int yCoord)
{
    objects[xCoord][yCoord] = SPACE;
}

ObjectType RoomObjects::getObjectType(int xCoord, int yCoord)
{
    return objects[xCoord][yCoord];
}