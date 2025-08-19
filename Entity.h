#pragma once
class Entity
{
protected:
	int health;
	int attack;
	int defense;
	char identity = 'E';
public:
	Entity();
	virtual ~Entity();

};

