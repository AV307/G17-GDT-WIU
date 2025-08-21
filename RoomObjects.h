#pragma once

enum ObjectType {
	SWITCH1,
	SWITCH2,
	SWITCH3,
	SWITCH4,
	SWITCH5,

	STEPBUTTON1,
	STEPBUTTON2,
	STEPBUTTON3,
	STEPBUTTON4,
	STEPBUTTON5,
	
	TELEPORTER,
	TELEPORTER,
	TELEPORTER,
	TELEPORTER,
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

