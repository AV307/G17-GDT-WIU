#pragma once
class Room
{
protected:
	int roomHeight;
	int roomWidth;
	int roomTopLeftX;
	int roomTopLeftY;
public:
	Room();
	~Room();

	int getRoomTopLeftX();
	int getRoomTopLeftY();
};

