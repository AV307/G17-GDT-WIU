#pragma once

enum ObjectType {
	//main room
	SWITCH,
	DOOR,
	STEPBUTTON,
	TELEPORTER1,
	TELEPORTER2,
	CHEST, // also treasure room
	KEYDOOR,
	TORCH,
	TOPDIRECTIONALDOOR,
	BOTTOMDIRECTIONALDOOR,
	LEFTDIRECTIONALDOOR,
	RIGHTDIRECTIONALDOOR,
	PRESSUREPLATE,
	BLOCKONPRESSUREPLATE,

	MOVEABLEBLOCK, // for puzzles

	//bed room
	BED,

	//shop room

	//portal room
	PORTAL,

	// general
	WALL, // for walls 'O'
	SPACE, // for blank spaces
};

struct Object
{
	ObjectType type;
	int id;
	bool toggled;
};

class RoomObjects
{
private:
	Object*** objects;


public:
	RoomObjects(int roomWidth, int roomHeight);
	~RoomObjects();

	void addObjects(int roomWidth, int roomHeight, int currentStage, char roomType);
	void removeObject(int xCoord, int yCoord);

	ObjectType getObjectType(int xCoord, int yCoord) const;

	int getObjectId(int xCoord, int yCoord) const;

	bool getObjectToggle(int xCoord, int yCoord) const;
	void setObjectToggle(int xCoord, int yCoord, bool toggle);
	void setObjectType(int xCoord, int yCoord, ObjectType type);
};

