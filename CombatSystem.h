#pragma once
#include "Entity.h"
#include <string>

class CombatSystem {
private:
	int turnsInBattle;
	std::string textDialogue;
protected:

public:
	CombatSystem();
	~CombatSystem(); // Destroy CombatSystem object when player is not in Combat (out of scope)

	void printCombatScreen(Entity& player, Entity& specifiedEnemy);
	void fightPVE(Entity& player, Entity& specifiedEnemy);
	void itemPVE(Entity& player, Entity& specifiedEnemy);
	void runPVE(Entity& player, Entity& specifiedEnemy);
	bool winLoseCondition(Entity& player, Entity& specifiedEnemy);

	std::string getTextDialogue();
	void setTextDialogue(std::string textUpdate);
};

