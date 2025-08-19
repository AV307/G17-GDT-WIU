#pragma once
#include "Entity.h"

class CombatSystem {
private:
	int turnsInBattle;
protected:

public:
	CombatSystem();
	~CombatSystem(); // Destroy CombatSystem object when player is not in Combat (out of scope)

	void printCombatScreen(Entity& player, Entity& specifiedEnemy);
	void fightPVE(Entity& player, Entity& specifiedEnemy);
	void itemPVE(Entity& player, Entity& specifiedEnemy);
	void runPVE(Entity& player, Entity& specifiedEnemy);
};

