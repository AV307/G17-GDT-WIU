#pragma once
class Entity
{
protected:
	int health;
	int attack;
	int defense;
	int level, EXP;
	char identity = 'E';
public:
	Entity();
	virtual ~Entity();

};

