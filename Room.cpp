#include "Room.h"

Room::Room()
{
	// literally nothing to put here
}

Room::~Room()
{
}

void Room::placeRoomObjects(char** roomArray)
{
	for (int x = 0; x < roomWidth; x++) {
		for (int y = 0; y < roomHeight; y++) {
			ObjectType objectType = roomObjects->getObjectType(x, y);
			switch (objectType) {
			case SPACE:
				roomArray[x][y] = ' ';
				break;
			case WALL:
				roomArray[x][y] = '#';
				break;
			}
		}
	}
}

//Ang Zhi En 252317H
//Getters for room related data
int Room::getRoomTopLeftX()
{
	return roomTopLeftX;
}

int Room::getRoomTopLeftY()
{
	return roomTopLeftY;
}

int Room::getRoomHeight()
{
	return roomHeight;
}

int Room::getRoomWidth()
{
	return roomWidth;
}

//Ang Zhi En 252317H
//Setter for location of the room in the stage based on whether it is room 1 or 2
//Incomplete
void Room::setRoomLocation(int roomNumber)
{
	switch (roomNumber)
	{
	case 1:
		roomTopLeftX = 10;
		roomTopLeftY = 20;
		break;
	case 2:
		roomTopLeftX = 10;
		roomTopLeftY = 60;
		break;
	}
}

RoomObjects* Room::getRoomObjects()
{
	return roomObjects;
}

