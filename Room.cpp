#include "Room.h"

Room::Room()
{
}

Room::~Room()
{
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
		roomTopLeftX = 20;
		roomTopLeftY = 20;
		break;
	case 2:
		roomTopLeftX = 20;
		roomTopLeftY = 60;
		break;
	}
}

