#include "RoomObjects.h"

RoomObjects::RoomObjects(int roomWidth, int roomHeight)
{
    objects = new Object** [roomHeight];
    for (int i = 0; i < roomHeight; i++) {
        objects[i] = new Object*[roomWidth];
        for (int j = 0; j < roomWidth; j++) {
            objects[i][j] = nullptr;
        }
    }

    // creates empty room with walls
    for (int i{ 0 }; i < roomHeight; i++)
    {
        for (int j{ 0 }; j < roomWidth; j++)
        {
            if (i == 0 || i == roomHeight - 1 || j == 0 || j == roomWidth - 1)
            {
                objects[i][j] = new Object{WALL, -1}; // set to wall
            }
            else {
                objects[i][j] = nullptr;
            }
        }
    }

    objects[roomHeight-10][roomWidth-10] = new Object{SWITCH, 0};
}

RoomObjects::~RoomObjects()
{
}


void RoomObjects::addObjects(int xCoord, int yCoord, ObjectType type, int id)
{
    if (objects[yCoord][xCoord] != nullptr) {
        delete objects[yCoord][xCoord];
    }
    objects[yCoord][xCoord] = new Object{type, id};
}

void RoomObjects::removeObject(int xCoord, int yCoord)
{
    if (objects[yCoord][xCoord] != nullptr) {
        delete objects[yCoord][xCoord];
        objects[yCoord][xCoord] = nullptr;
    }
}

Object* RoomObjects::getObject(int xCoord, int yCoord) const
{
    return objects[yCoord][xCoord];
}

ObjectType RoomObjects::getObjectType(int xCoord, int yCoord) const
{
    Object* obj = objects[yCoord][xCoord];
    if (obj != nullptr) {
        return obj->type;
    }
    return SPACE;
}

int RoomObjects::getObjectId(int xCoord, int yCoord) const
{
    Object* obj = objects[yCoord][xCoord];
    if (obj != nullptr) {
        return obj->type;
    }
    return -1;
}
