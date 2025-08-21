#include "RoomObjects.h"

#pragma once
class Room
{
protected:
	int roomHeight;
	int roomWidth;
	int roomTopLeftX;
	int roomTopLeftY;

	RoomObjects* roomObjects;
public:
	Room();
	~Room();

	void placeRoomObjects(char** roomArray);

	int getRoomTopLeftX();
	int getRoomTopLeftY();

	int getRoomWidth();
	int getRoomHeight();

	void setRoomLocation(int roomNumber);
	RoomObjects* getRoomObjects();
};

