#include "RoomObjects.h"
#include <iostream>

// Ang Zhi En 252317H
// Constructor for roomObjects, creates empty room and creates array for objects
// Incomplete
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

    objects[roomWidth - 10][roomHeight - 14] = new Object{ TELEPORTER1, 1 ,false };
    objects[roomWidth - 10][roomWidth - 8] = new Object{ TELEPORTER2, 1 ,false };
}

RoomObjects::~RoomObjects()
{
}

// Ang Zhi En 252317H
// Add (all) objects into a room after checking what room it is
// Incomplete
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


    if (objects[yCoord][xCoord] != nullptr) 
    {
        delete objects[yCoord][xCoord];
    }
    objects[yCoord][xCoord] = new Object{type, id};
}

// Ang Zhi En 252317H
// Removes object from a coordinate
void RoomObjects::removeObject(int xCoord, int yCoord)
{
    if (objects[yCoord][xCoord] != nullptr) 
    {
        delete objects[yCoord][xCoord];
        objects[yCoord][xCoord] = nullptr;
    }
}

// Ang Zhi En 252317H
// Getter for object type at a certain coordinate
ObjectType RoomObjects::getObjectType(int xCoord, int yCoord) const
{
    Object* object{ objects[yCoord][xCoord] };
    if (object != nullptr) 
    {
        return object->type;
    }

    // might change this code later if we use SPACE instead of nullptr in roomobject constructor
    return SPACE;
}

// Ang Zhi En 252317H
// Getter for object ID at a certain coordinate
// Returns -1 if there's no ID (e.g. torch)
int RoomObjects::getObjectId(int xCoord, int yCoord) const
{
    Object* object = objects[yCoord][xCoord];
    if (object != nullptr) 
    {
        return object->id;
    }
    return -1;
}

//Jayren 250920U
//Getter for the state of the object
//Return toggle state of object, if no toggle state, return false
bool RoomObjects::getObjectToggle(int xCoord, int yCoord) const
{
    Object* obj = objects[yCoord][xCoord];
    if (obj != nullptr) {
        return obj->toggled;
    }
    return false;
}

//Jayren 250920U
//Setter for the state of the object
//Toggles state from true to false or false to true
void RoomObjects::setObjectToggle(int xCoord, int yCoord, bool toggle)
{
    Object* obj = objects[yCoord][xCoord];
    if (obj != nullptr) {
        std::cout << "Door at (" << xCoord << "," << yCoord << ") toggled to "
            << (toggle ? "OPEN" : "CLOSED") << std::endl;
        obj->toggled = toggle;
    }
}
