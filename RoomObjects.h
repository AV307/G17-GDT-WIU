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

