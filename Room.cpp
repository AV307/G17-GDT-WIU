#include "Room.h"
#include "RoomObjects.h"

Room::Room()
{
	// literally nothing to put here
}

Room::~Room()
{
}

//Jayren Choi 250920U
//Place the objects into the room
void Room::placeRoomObjects(char** roomArray)
{
	for (int x = 0; x < roomWidth; x++) {
		for (int y = 0; y < roomHeight; y++) {
			ObjectType objectType = roomObjects->getObjectType(x, y);
			switch (objectType) {
			case SPACE:
				roomArray[y][x] = ' ';
				break;
			case WALL:
				roomArray[y][x] = '#';
				break;
			case SWITCH:
				roomArray[y][x] = 'L';
				break;
			case DOOR:
				roomArray[y][x] = '+';
				break;
			case TELEPORTER1:
				roomArray[y][x] = 'T';
				break;
			case TELEPORTER2:
				roomArray[y][x] = 'T';
				break;
			case PRESSUREPLATE:
				roomArray[y][x] = 'B';
				break;
			case MOVEABLEBLOCK:
				roomArray[y][x] = 'M';
				break;
			case BLOCKONPRESSUREPLATE:
				roomArray[y][x] = 'm';
				break;
			case BREAKABLEWALL:
				roomArray[y][x] = 'W';
				break;
			case KEYDOOR:
				roomArray[y][x] = 'D';
				break;
			case CHEST:
				roomArray[y][x] = 'C';
				break;
			case TOPDIRECTIONALDOOR:
				roomArray[y][x] = '^';
				break;
			case BOTTOMDIRECTIONALDOOR:
				roomArray[y][x] = 'v';
				break;
			case LEFTDIRECTIONALDOOR:
				roomArray[y][x] = '<';
				break;
			case RIGHTDIRECTIONALDOOR:
				roomArray[y][x] = '>';
				break;
			case TORCH:
				roomArray[y][x] = '!';
				break;
			case MEGATORCH:
				roomArray[y][x] = '?';
				break;
			case PORTAL:
				roomArray[y][x] = 'O';
				break;
			case BOSSDOOR:
				roomArray[y][x] = 'X';
				break;
			case SIGN:
				roomArray[y][x] = 'S';
				break;
			case SHOPKEEPER:
				roomArray[y][x] = '$';
				break;
			case BED:
				roomArray[y][x] = 'H';
				break;
			case BOSS:
				roomArray[y][x] = '@';
				break;
			default:
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
void Room::setRoomLocation(int roomNumber)
{
	switch (roomNumber)
	{
	case 1:
		roomTopLeftX = 30;
		roomTopLeftY = 10;
		break;
	case 2:
		roomTopLeftX = 30;
		roomTopLeftY = 70;
		break;
	}
}

//Ang Zhi En 252317H
//Getter for roomObjects
RoomObjects* Room::getRoomObjects()
{
	return roomObjects;
}

