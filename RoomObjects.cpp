#include "RoomObjects.h"

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
            else 
            {
                objects[i][j] = nullptr;
            }
        }
    }
}

RoomObjects::~RoomObjects()
{
}

// Ang Zhi En 252317H
// Add (all) objects into a room after checking what room it is
// Incomplete
void RoomObjects::addObjects(int roomWidth, int roomHeight, int currentStage, char roomType)
{
    // essentially presets for the rooms
    switch (roomType)
    {
    case 'M': // main room
        switch (currentStage)
        {
        case 1:
            objects[10][10] = new Object{ DOOR, 1 ,false };
            objects[11][11] = new Object{ DOOR, 1 ,false };

            objects[12][12] = new Object{ SWITCH, 1 ,false };
            objects[13][12] = new Object{ PRESSUREPLATE, 2 ,false };
            objects[15][12] = new Object{ MOVEABLEBLOCK, 2 ,false };

            objects[15][11] = new Object{ DOOR, 2 ,false };
            objects[16][10] = new Object{ DOOR, 2 ,false };

            objects[13][13] = new Object{ DOOR, 1 ,false };
            objects[14][14] = new Object{ DOOR, 1 ,false };

            objects[15][15] = new Object{ TELEPORTER1, 1 ,false };
            objects[16][16] = new Object{ TELEPORTER2, 1 ,false };
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
    case 'T': // treasure room
        break;
    }


    /*if (objects[yCoord][xCoord] != nullptr) 
    {
        delete objects[yCoord][xCoord];
    }
    objects[yCoord][xCoord] = new Object{type, id};*/
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
ObjectType RoomObjects::getObjectType(int column, int row) const
{
    Object* object{ objects[row][column] };
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
int RoomObjects::getObjectId(int column, int row) const
{
    Object* object = objects[row][column];
    if (object != nullptr) 
    {
        return object->id;
    }
    return -1;
}

//Jayren 250920U
//Getter for the state of the object
//Return toggle state of object, if no toggle state, return false
bool RoomObjects::getObjectToggle(int column, int row) const
{
    Object* obj = objects[row][column];
    if (obj != nullptr) {
        return obj->toggled;
    }
    return false;
}

//Jayren 250920U
//Setter for the state of the object
//Toggles state from true to false or false to true
void RoomObjects::setObjectToggle(int column, int row, bool toggle)
{
    Object* obj = objects[row][column];
    if (obj != nullptr) {
        obj->toggled = toggle;
    }
}
