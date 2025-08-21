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
                objects[i][j] = new Object{WALL, -1, false}; // set to wall
            }
            else {
                objects[i][j] = nullptr;
            }
        }
    }

    objects[roomWidth - 11][roomHeight - 14] = new Object{ DOOR, 1 ,false };
    objects[roomWidth - 11][roomWidth - 13] = new Object{ DOOR, 1 ,false };

    objects[roomWidth - 11][roomWidth - 11] = new Object{ SWITCH, 1 ,false };

    objects[roomWidth - 11][roomWidth - 9] = new Object{ DOOR, 1 ,false };
    objects[roomWidth - 11][roomWidth - 8] = new Object{ DOOR, 1 ,false };
}

RoomObjects::~RoomObjects()
{
}


void RoomObjects::addObjects(int xCoord, int yCoord, ObjectType type, int id, int currentStage, char roomType)
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
        return obj->id;
    }
    return -1;
}

bool RoomObjects::getObjectToggle(int xCoord, int yCoord) const
{
    Object* obj = objects[yCoord][xCoord];
    if (obj != nullptr) {
        return obj->toggled;
    }
    return false;
}

void RoomObjects::setObjectToggle(int xCoord, int yCoord, bool toggle)
{
    Object* obj = objects[yCoord][xCoord];
    if (obj != nullptr) {
        obj->toggled = toggle;
    }
}
