#pragma once

enum ObjectType {
	//main room
	SWITCH,
	STEPBUTTON,
	TELEPORTER,
	CHEST, // also treasure room
	LOCKEDDOOR,
	TORCH,
	ONEDIRECTIONALDOOR,
	PRESSUREPLATE,

	//bed room
	BED,

	//shop room

	//portal room
	PORTAL,

	// general
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

