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

void CombatSystem::printCombatScreen(Entity& player, Entity& specifiedEnemy) {

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
		// if (n == 9) { // 1/2 Division Line
		//	 cout << "// +";
		//	 for (int i = 0; i < 35; i++) {
		//		 cout << " ";
		//	 }
		//	 cout << "+";
		//	 for (int i = 0; i < 35; i++) {
		//		 cout << " ";
		//	 }
		//	 cout << "+ //" << endl;
		// }
		if (n == 9) {
			cout << "// +";
			for (int i = 0; i < 7; i++) {
				cout << " ";
			}
			cout << "Player HP: " << player.getHealth();
			if (player.getHealth() < 10) { // when Player Health is 1 digits
				for (int i = 0; i < 35 - 7 - 12; i++) {
					cout << " ";
				}
			}
			else if (player.getHealth() > 9) { // when Player Health is 2 digits
				for (int i = 0; i < 35 - 7 - 13; i++) {
					cout << " ";
				}
			}
			else if (player.getHealth() > 99) { // when Player Health is 3 digits
				for (int i = 0; i < 35 - 7 - 14; i++) {
					cout << " ";
				}
			}
			else if (player.getHealth() > 999) { // when Player Health is 4 digits
				for (int i = 0; i < 35 - 7 - 15; i++) {
					cout << " ";
				}
			}
			cout << "+";
			for (int i = 0; i < 7; i++) {
				cout << " ";
			}
			cout << "Enemy HP: " << specifiedEnemy.getHealth();
			if (specifiedEnemy.getHealth() < 10) { // when Enemy Health is 1 digits
				for (int i = 0; i < 35 - 7 - 11; i++) {
					cout << " ";
				}
			}
			else if (specifiedEnemy.getHealth() > 9) { // when Enemy Health is 2 digits
				for (int i = 0; i < 35 - 7 - 12; i++) {
					cout << " ";
				}
			}
			else if (specifiedEnemy.getHealth() > 99) { // when Enemy Health is 3 digits
				for (int i = 0; i < 35 - 7 - 13; i++) {
					cout << " ";
				}
			}
			else if (specifiedEnemy.getHealth() > 999) { // when Enemy Health is 4 digits
				for (int i = 0; i < 35 - 7 - 14; i++) {
					cout << " ";
				}
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
	// cout << "// +      Player HP:                   +       Enemy HP:                   + //" << endl;  }  For Player & Enemy HP
	// cout << "// +-----------------------------------------------------------------------+ //" << endl;
}





// +----------------------------------------------------------------------------------+ //
// Function Name: fightPVE
// Description: To carry out the "Fight" action between Player and Enemy
// Parameter(s): None
// Return(s): None
// +----------------------------------------------------------------------------------+ //

void CombatSystem::fightPVE(Entity& player, Entity& specifiedEnemy) {
	//int critPlayerDeterminant = rand() % 100 + 1;
	//int critEnemyDeterminant = rand() % 100 + 1;
	//
	//if (critPlayerDeterminant > player.getCritRate()) {
	//	if (player.getHealth() > 0 && specifiedEnemy.getHealth() > 0) {
	//		specifiedEnemy.setHealth(specifiedEnemy.getHealth() - player.getAttack());                              // Enemy is attacked first by player

	//		if (critEnemyDeterminant > specifiedEnemy.getCritRate()) {
	//			player.setHealth(player.getHealth() - specifiedEnemy.getAttack());                                  // Player is then attacked by enemy
	//		}
	//		else if (critEnemyDeterminant <= specifiedEnemy.getCritRate()) {
	//			player.setHealth(player.getHealth() - (specifiedEnemy.getAttack() * specifiedEnemy.getCritDmg()));  // Player is critical hit by enemy
	//		}
	//	}
	//}
	//else if (critPlayerDeterminant <= player.getCritRate()) {
	//	if (player.getHealth() > 0 && specifiedEnemy.getHealth() > 0) {
	//		specifiedEnemy.setHealth(specifiedEnemy.getHealth() - (player.getAttack() * player.getCritDmg()));      // Enemy is critical hit first by player

	//		if (critEnemyDeterminant > specifiedEnemy.getCritRate()) {
	//			player.setHealth(player.getHealth() - specifiedEnemy.getAttack());                                  // Player is then attacked by enemy
	//		}
	//		else if (critEnemyDeterminant <= specifiedEnemy.getCritRate()) {
	//			player.setHealth(player.getHealth() - (specifiedEnemy.getAttack() * specifiedEnemy.getCritDmg()));  // Player is critical hit by enemy
	//		}
	//	}
	//}

	//if (player.getHealth() < 0) {
	//	player.setHealth(0);
	//}
	//if (specifiedEnemy.getHealth() < 0) {
	//	specifiedEnemy.setHealth(0);
	//}
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