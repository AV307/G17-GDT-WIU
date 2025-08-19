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

	for (int n = 1; n < 11; n++) {
		if (n == 1) { // Enemy Design Line
			for (int i = 0; i < 5; i++) {
				cout << "//";
				for (int j = 0; j < 75; j++) {
					cout << ' ';
				}
				cout << "//" << endl;
			}
		}
		if (n == 2 || n == 4 || n == 8 || n == 10) { // Full Lines
			cout << "// +";
			for (int i = 0; i < 71; i++) {
				cout << "-";
			}
			cout << "+ //" << endl;
		}
		if (n == 3) { // Text Dialogue Line
			for (int i = 0; i < 3; i++) {
				cout << "//";
				for (int j = 0; j < 75; j++) {
					cout << ' ';
				}
				cout << "//" << endl;
			}
		}
		if (n == 5 || n == 7) { // 1/3 Division Lines
			cout << "// +";
			for (int i = 0; i < 21; i++) {
				cout << "-";
			}
			for (int i = 0; i < 2; i++) {
				cout << "+  +";
				for (int j = 0; j < 21; j++) {
					cout << "-";
				}
			}
			cout << "+ //" << endl;
		}
		if (n == 6) { // Combat Option Line
			cout << "// +      Fight 'F'      +  +       Item 'I'      +  +       Run 'R'       + //" << endl;
		}
		if (n == 9) { // 1/2 Division Line
			cout << "// +";
			for (int i = 0; i < 35; i++) {
				cout << " ";
			}
			cout << "+";
			for (int i = 0; i < 35; i++) {
				cout << " ";
			}
			cout << "+ //" << endl;
		}
	}


	

	// Hard-Code Combat Screen Design
	// cout << "//                                                                           //" << endl;  \
	// cout << "//                                                                           //" << endl;   |
	// cout << "//                                                                           //" << endl;    }  For Enemy Design
	// cout << "//                                                                           //" << endl;   |
	// cout << "//                                                                           //" << endl;  /
	// cout << "// +-----------------------------------------------------------------------+ //" << endl;
	// cout << "//                                                                           //" << endl;  \
	// cout << "//                                                                           //" << endl;   }  For Text Dialogue
	// cout << "//                                                                           //" << endl;  /
	// cout << "// +-----------------------------------------------------------------------+ //" << endl;
	// cout << "// +---------------------+  +---------------------+  +---------------------+ //" << endl;
	// cout << "// +      Fight 'F'      +  +       Item 'I'      +  +       Run 'R'       + //" << endl;
	// cout << "// +---------------------+  +---------------------+  +---------------------+ //" << endl;
	// cout << "// +-----------------------------------------------------------------------+ //" << endl;
	// cout << "// +                                   +                                   + //" << endl;  }  For Player & Enemy HP
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