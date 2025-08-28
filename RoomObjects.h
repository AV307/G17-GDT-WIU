#pragma once
#include <string>

enum ObjectType {
	//main room
	SWITCH,
	KEYDOOR,
	DOOR,
	BOSSDOOR,
	STEPBUTTON,
	TELEPORTER1,
	TELEPORTER2,
	CHEST, // also treasure room
	TORCH,
	MEGATORCH,
	TOPDIRECTIONALDOOR,
	BOTTOMDIRECTIONALDOOR,
	LEFTDIRECTIONALDOOR,
	RIGHTDIRECTIONALDOOR,
	PRESSUREPLATE,
	BLOCKONPRESSUREPLATE,
	SIGN,

	MOVEABLEBLOCK, // for puzzles
	BREAKABLEWALL,

	BOSS,

	//bed room
	BED,

	//shop room
	SHOPKEEPER,

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

	// For CHEST
	std::string itemName;
	char itemType;

	// For SIGN
	std::string message = " ";
};

class RoomObjects
{
private:
	Object*** objects;


public:
	RoomObjects(bool openSide, int roomColumn, int roomWidth, int roomHeight);
	~RoomObjects();

	void addObjects(int roomWidth, int roomHeight, int currentStage, char roomType);
	void removeObject(int xCoord, int yCoord);

	ObjectType getObjectType(int xCoord, int yCoord) const;
	int getObjectId(int xCoord, int yCoord) const;
	bool getObjectToggle(int xCoord, int yCoord) const;
	std::string getObjectItemName(int xCoord, int yCoord) const;
	char getObjectItemType(int xCoord, int yCoord) const;
	std::string getObjectMessage(int xCoord, int yCoord) const;

	void setObjectToggle(int xCoord, int yCoord, bool toggle);
	void setObjectType(int xCoord, int yCoord, ObjectType type);
	void setObject(int row, int col, Object objData);
};

