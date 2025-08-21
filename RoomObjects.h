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

struct Object
{
	ObjectType type;
	int id;
};

class RoomObjects
{
private:
	Object*** objects;


public:
	RoomObjects(int roomWidth, int roomHeight);
	~RoomObjects();

	void addObjects(int xCoord, int yCoord, ObjectType type, int id);
	void removeObject(int xCoord, int yCoord);
	Object* getObject(int xCoord, int yCoord) const;
	ObjectType getObjectType(int xCoord, int yCoord) const;

	int getObjectId(int xCoord, int yCoord) const;
};

