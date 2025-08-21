#pragma once

enum ObjectType {
	SWITCH,
	STEPBUTTON,
	TELEPORTER,
	CHEST,
	LOCKEDDOOR,
	TORCH,
	ONEDIRECTIONALDOOR,
	PRESSUREPLATE,

	WALL, // for walls 'O'
	SPACE, // for blank spaces
};


class RoomObjects
{
private:
	ObjectType** objects;


public:
	RoomObjects(int roomWidth, int roomHeight);
	~RoomObjects();

	void addObjects(int currentStage, char roomType);
	void removeObject(int xCoord, int yCoord);
	ObjectType getObjectType(int xCoord, int yCoord);
};

