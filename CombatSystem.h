#pragma once
#include "Entity.h"
#include <string>

class CombatSystem {
private:
	std::string textDialogue;

public:
	CombatSystem();
	~CombatSystem();

	void printCombatScreen(Entity& player, Entity& specifiedEnemy);
	void printItemPVECategoryScreen();
	void printItemPVEWeaponsScreen(Entity& player);
	void printItemPVEArmoursScreen(Entity& player);
	void printItemPVEConsumablesScreen(Entity& player);

	void fightPVE(Entity& player, Entity& specifiedEnemy);
	void itemPVE(Entity& player, Entity& specifiedEnemy);
	void runPVE(Entity& player, Entity& specifiedEnemy);
	bool winLoseCondition(Entity& player, Entity& specifiedEnemy);

	std::string getTextDialogue();
	void setTextDialogue(std::string textUpdate);
};

