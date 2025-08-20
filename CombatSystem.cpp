#include "CombatSystem.h"
#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;

CombatSystem::CombatSystem() {
	turnsInBattle = 0;
}

CombatSystem::~CombatSystem() {

}

std::string CombatSystem::getTextDialogue() {
	return textDialogue;
}

void CombatSystem::setTextDialogue(std::string textUpdate) {
	textDialogue = textUpdate;
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
			if (player.getHealth() < 10) {                              // when Player Health is 1 digits
				for (int i = 0; i < 35 - 7 - 12; i++) {
					cout << " ";
				}
			}
			else if (player.getHealth() > 9) {                          // when Player Health is 2 digits
				for (int i = 0; i < 35 - 7 - 13; i++) {
					cout << " ";
				}
			}
			else if (player.getHealth() > 99) {                         // when Player Health is 3 digits
				for (int i = 0; i < 35 - 7 - 14; i++) {
					cout << " ";
				}
			}
			else if (player.getHealth() > 999) {                        // when Player Health is 4 digits
				for (int i = 0; i < 35 - 7 - 15; i++) {
					cout << " ";
				}
			}
			cout << "+";
			for (int i = 0; i < 7; i++) {
				cout << " ";
			}
			cout << "Enemy HP: " << specifiedEnemy.getHealth();
			if (specifiedEnemy.getHealth() < 10) {                      // when Enemy Health is 1 digits
				for (int i = 0; i < 35 - 7 - 11; i++) {
					cout << " ";
				}
			}
			else if (specifiedEnemy.getHealth() > 9) {                  // when Enemy Health is 2 digits
				for (int i = 0; i < 35 - 7 - 12; i++) {
					cout << " ";
				}
			}
			else if (specifiedEnemy.getHealth() > 99) {                 // when Enemy Health is 3 digits
				for (int i = 0; i < 35 - 7 - 13; i++) {
					cout << " ";
				}
			}
			else if (specifiedEnemy.getHealth() > 999) {                // when Enemy Health is 4 digits
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

	int critPlayerDeterminant = rand() % 100 + 1;
	int critEnemyDeterminant = rand() % 100 + 1;

	// Damage Equation
	// Final Damage = (Base Attack * Crit Dmg) - Base Defence
	// Crit Damage ignores Defence
	// Example:
	// (200 - 50) * 2      |      (ATK - DEF) * CRITDMG   =   300 Final Damage       |       Critical took place after ATK reduced by DEF
	// (200 * 2) - 50      |      (ATK * CRITDMG) - DEF   =   350 Final Damage       |       DEF took place after Critical
	// (200 * 2) * 0.5     |      (ATK * CRITDMG) * DEF   =   200 Final Damage       |
	// (200 * 0.5) * 2     |      (ATK * DEF) * CRITDMG   =   200 Final Damage       |

	// Damage Calculations
	int playerDamage = player.getAttack() - specifiedEnemy.getDefense();                                                                                  // If Player Doesn't Crit
	int playerCritDamage = player.getAttack() * player.getCRITDMG() - specifiedEnemy.getDefense();                                                        // If Player Does Crit
	int enemyDamage = specifiedEnemy.getAttack() - player.getDefense();                                                                                   // If Enemy Doesn't Crit
	int enemyCritDamage = specifiedEnemy.getAttack() * specifiedEnemy.getCRITDMG() - player.getDefense();                                                 // If Enemy Does Crit

	if (playerDamage < 0) {
		playerDamage = 0;
	}
	if (playerCritDamage < 0) {
		playerCritDamage = 0;
	}
	if (enemyDamage < 0) {
		enemyDamage = 0;
	}
	if (enemyCritDamage < 0) {
		enemyCritDamage = 0;
	}
	
	// "Fight" Logic
	if (critPlayerDeterminant > player.getCRITRate()) {
		if (player.getHealth() > 0 && specifiedEnemy.getHealth() > 0) {
			specifiedEnemy.setHealth(specifiedEnemy.getHealth() - (playerDamage));                                                                        // If DEF <= ATK, Entity Final Damage is given value

			if (critEnemyDeterminant > specifiedEnemy.getCRITRate()) {
				player.setHealth(player.getHealth() - (enemyDamage));                                                                                     // If DEF <= ATK, Entity Final Damage is given value
			}
			else if (critEnemyDeterminant <= specifiedEnemy.getCRITRate()) {
				player.setHealth(player.getHealth() - (enemyCritDamage));                                                                                 // If DEF <= ATK, Entity Final Damage is given value
			}
			turnsInBattle++;
		}
	}
	else if (critPlayerDeterminant <= player.getCRITRate()) {
		if (player.getHealth() > 0 && specifiedEnemy.getHealth() > 0) {
			specifiedEnemy.setHealth(specifiedEnemy.getHealth() - (playerCritDamage));                                                                    // If DEF <= ATK, Entity Final Damage is given value

			if (critEnemyDeterminant > specifiedEnemy.getCRITRate()) {
				player.setHealth(player.getHealth() - (enemyDamage));                                                                                     // If DEF <= ATK, Entity Final Damage is given value
			}
			else if (critEnemyDeterminant <= specifiedEnemy.getCRITRate()) {
				player.setHealth(player.getHealth() - (enemyCritDamage));                                                                                 // If DEF <= ATK, Entity Final Damage is given value
			}
			turnsInBattle++;
		}
	}

	// Damage Numbers Display (Text Dialogue)
	if (critPlayerDeterminant > player.getCRITRate() && critEnemyDeterminant > specifiedEnemy.getCRITRate()) {                                            // If Player And Enemy DON'T Crit
		setTextDialogue("You dealt " + to_string(playerDamage) + " DMG, received " + to_string(enemyDamage) + " DMG");
	}
	else if (critPlayerDeterminant <= player.getCRITRate() && critEnemyDeterminant > specifiedEnemy.getCRITRate()) {                                      // If Player Crits BUT Enemy doesn't
		setTextDialogue("You dealt " + to_string(playerCritDamage) + " DMG (Critical!), received " + to_string(enemyDamage) + " DMG");
	}
	else if (critPlayerDeterminant > player.getCRITRate() && critEnemyDeterminant <= specifiedEnemy.getCRITRate()) {                                      // If Enemy Crits BUT Player doesn't
		setTextDialogue("You dealt " + to_string(playerDamage) + " DMG, received " + to_string(enemyCritDamage) + " DMG (Critical!)");
	}
	else if (critPlayerDeterminant <= player.getCRITRate() && critEnemyDeterminant <= specifiedEnemy.getCRITRate()) {                                     // If Player And Enemy BOTH Crit
		setTextDialogue("You dealt " + to_string(playerCritDamage) + " DMG (Critical!), received " + to_string(enemyCritDamage) + " DMG (Critical!)");
	}

	// Error Check To Ensure No Negative HP Values
	if (player.getHealth() < 0) {
		player.setHealth(0);
	}
	if (specifiedEnemy.getHealth() < 0) {
		specifiedEnemy.setHealth(0);
	}
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