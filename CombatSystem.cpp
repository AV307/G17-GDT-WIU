#include "CombatSystem.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "Entity.h"

using namespace std;

CombatSystem::CombatSystem() {
	turnsInBattle = 0;
}

CombatSystem::~CombatSystem() {

}

// +----------------------------------------------------------------------------------+ //
// Function Name: printCombatScreen
// Description: Used to print the combat screen when player enters combat with an enemy
// Parameter(s): None
// Return(s): None
// +----------------------------------------------------------------------------------+ //

void CombatSystem::printCombatScreen() {
	string csBorderT1 = "// +----------------------------------------------+ //";
	string csBorderT2 = "// +---------------------+  +---------------------+ //";

	cout << csBorderT1 << endl;
	cout << csBorderT2 << endl;
	cout << "// +      Fight 'F'      +  +      Item 'I'       + //" << endl;
	cout << csBorderT2 << endl;
	cout << csBorderT1 << endl;
	cout << "// +                   Run 'R'                    + //" << endl;
	cout << csBorderT1 << endl;
	cout << csBorderT1 << endl;

	// Hard-Code Combat Screen Design
	// cout << "// +-----------------------------------------------------------------------+ //" << endl;
	// cout << "// +---------------------+  +---------------------+  +---------------------+ //" << endl;
	// cout << "// +      Fight 'F'      +  +       Item 'I'      +  +       Run 'R'       + //" << endl;
	// cout << "// +---------------------+  +---------------------+  +---------------------+ //" << endl;
	// cout << "// +-----------------------------------------------------------------------+ //" << endl;
}





// +----------------------------------------------------------------------------------+ //
// Function Name: fightPVE
// Description: To carry out the "Fight" action between Player and Enemy
// Parameter(s): None
// Return(s): None
// +----------------------------------------------------------------------------------+ //

void CombatSystem::fightPVE(Entity& player, Entity& specifiedEnemy) {

}





// +----------------------------------------------------------------------------------+ //
// Function Name: itemPVE
// Description: To carry out the "Item" action between Player and Enemy
// Parameter(s): None
// Return(s): None
// +----------------------------------------------------------------------------------+ //

void CombatSystem::itemPVE(Entity& player, Entity& specifiedEnemy) {

}





// +----------------------------------------------------------------------------------+ //
// Function Name: runPVE
// Description: To carry out the "Run" action between Player and Enemy
// Parameter(s): None
// Return(s): None
// +----------------------------------------------------------------------------------+ //

void CombatSystem::runPVE(Entity& player, Entity& specifiedEnemy) {

}