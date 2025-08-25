#include "CombatSystem.h"

#include <iostream>
#include <string>
#include <conio.h>

#include "Entity.h"
#include "Stage.h"
#include "Item.h"
#include "Potion.h"

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

// +----------------------------------------------------------------------------------------------+ //
// Function Name: printCombatScreen
// Description: Used to print the combat screen when player enters combat with an enemy
// Parameter(s): The player and the specific enemy that is entering the battle, directly referenced
// Return(s): None
// Function Writer(s): Ethan
// +----------------------------------------------------------------------------------------------+ //

void CombatSystem::printCombatScreen(Entity& player, Entity& specifiedEnemy) {

	for (int n = 1; n < 11; n++) {
		if (n == 1) { // Enemy Design Line
			for (int i = 0; i < 10; i++) { // Going By Line
				cout << "//";
				if (specifiedEnemy.getEntityType() == "Undead") {
					for (int j = 0; j < 34; j++) {
						cout << ' ';
					}
					if (i < 3) {
						for (int l = 0; l < 7; l++) {
							cout << ' ';
						}
					}
					if (i == 3) {
						cout << R"(.-"""-.)";
					}
					if (i == 4) {
						cout << R"(/ 0  0\)";
					}
					if (i == 5) {
						cout << R"(|  w  |)";
					}
					if (i == 6) {
						cout << R"(|.___.|)";
					}
					if (i == 7) {
						cout << R"(  \-/  )";
					}
					if (i > 7) {
						for (int l = 0; l < 7; l++) {
							cout << ' ';
						}
					}
					for (int j = 0; j < 34; j++) {
						cout << ' ';
					}
				}
			    else if (specifiedEnemy.getEntityType() == "Animal") {
					for (int j = 0; j < 28; j++) {
						cout << ' ';
					}
					if (i == 0 || i == 9) {
						for (int l = 0; l < 19; l++) {
							cout << ' ';
						}
					}
					if (i == 1) {
						cout << R"(          .--.     )";
					}
					if (i == 2) {
						cout << R"(      / 6_6 \      )";
					}
					if (i == 3) {
						cout << R"(      \_ v _/      )";
					}
					if (i == 4) {
						cout << R"(      /     \     /)";
					}
					if (i == 5) {
						cout << R"(     //|/.\|\\   / )";
					}
					if (i == 6) {
						cout << R"(    ||  \_/  ||_/  )";
					}
					if (i == 7) {
						cout << R"(     \\     //     )";
					}
					if (i == 8) {
						cout << R"(      `-----`      )";
					}
					for (int j = 0; j < 28; j++) {
						cout << ' ';
					}
				}
				else if (specifiedEnemy.getEntityType() == "Flower") {
					for (int j = 0; j < 27; j++) {
						cout << ' ';
					}
					if (i == 0 || i == 4) {
						cout << R"(       ((@@@))       )";
					}
					if (i == 1 || i == 3) {
						cout << R"(     ((@@@@@@@))     )";
					}
					if (i == 2) {
						cout << R"(    ((@@@@@@@@@))    )";
					}
					if (i > 4) {
						cout << R"(         \|/         )";
					}
				}
				else if (specifiedEnemy.getEntityType() == "Aquatic") {
					for (int j = 0; j < 28; j++) {
						cout << ' ';
					}
					if (i < 3 || i > 7) {
						for (int l = 0; l < 19; l++) {
							cout << ' ';
						}
					}
					if (i == 3) {
						cout << R"(      __/""-._     )";
					}
					if (i == 4) {
						cout << R"(     /     o  '""-.)";
					}
					if (i == 5) {
						cout << R"(><(((('>        )  )";
					}
					if (i == 6) {
						cout << R"(     \__      _.'  )";
					}
					if (i == 7) {
						cout << R"(        """--"     )";
					}
				}
				else if (specifiedEnemy.getEntityType() == "Vampire") {
					for (int j = 0; j < 26; j++) {
						cout << ' ';
					}
					if (i < 2 || i > 7) {
						for (int l = 0; l < 23; l++) {
							cout << ' ';
						}
					}
					if (i == 2) {
						cout << R"(  \--\           \--\  )";
					}
					if (i == 3) {
						cout << R"(   \  \ --------- \  \ )";
					}
					if (i == 4) {
						cout << R"(  Y \    o  v  v  o   \)";
					}
					if (i == 5) {
						cout << R"( / o| _______________ |)";
					}
					if (i == 6) {
						cout << R"(/__/                  |)";
					}
					if (i == 7) {
						cout << R"(Y Y \__mm_________mm__/)";
					}
					for (int j = 0; j < 26; j++) {
						cout << ' ';
					}
				}
				else if (specifiedEnemy.getEntityType() == "Humanoid") {
					for (int j = 0; j < 20; j++) {
						cout << ' ';
					}
					if (i == 0) {
						cout << R"(    _____________________________    )";
					}
					if (i == 1) {
						cout << R"(   |                             |   )";
					}
					if (i == 2) {
						cout << R"(   |UUUUUUUUUUUUUUUUUUUUUUUUUUUUU|   )";
					}
					if (i == 3) {
						cout << R"( __|          o   ---   o        |__ )";
					}
					if (i == 4) {
						cout << R"(|  |_____________________________|  |)";
					}
					if (i == 5) {
						cout << R"(|_X|                             |X_|)";
					}
					if (i == 6) {
						cout << R"(   |_____________|-|_____________|   )";
					}
					for (int j = 0; j < 20; j++) {
						cout << ' ';
					}
				}
				else if (specifiedEnemy.getEntityType() == "Ascendants") {
					for (int j = 0; j < 25; j++) {
						cout << ' ';
					}
					if (i == 0) {
						cout << R"(     /|\     )";
					}
					if (i == 1) {
						cout << R"(    / | \    )";
					}
					if (i == 2) {
						cout << R"(   /_ | _\   )";
					}
					if (i == 3) {
						cout << R"(  /-| 0 |-\  )";
					}
					if (i == 4) {
						cout << R"( /_| ___ |_\ )";
					}
					if (i == 5) {
						cout << R"(/_/ \ _ / \_\)";
					}
					for (int j = 0; j < 25; j++) {
						cout << ' ';
					}
				}
				else if (specifiedEnemy.getEntityType() == "Cubed") {
					for (int j = 0; j < 27; j++) {
						cout << ' ';
					}
					if (i == 0) {
						cout << R"(_____________________)";
					}
					if (i == 1) {
						cout << R"(|\_________________\|)";
					}
					if (i == 2) {
						cout << R"(||                 ||)";
					}
					if (i == 3) {
						cout << R"(||                 ||)";
					}
					if (i == 4) {
						cout << R"(||                 ||)";
					}
					if (i == 5) {
						cout << R"(||   o    >    o   ||)";
					}
					if (i == 6) {
						cout << R"(||_________________||)";
					}
					for (int j = 0; j < 27; j++) {
						cout << ' ';
					}
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
				if (i == 0 || i == 2) {
					cout << "//";
					for (int j = 0; j < 75; j++) {
						cout << ' ';
					}
					cout << "//" << endl;
				}
				if (i == 1) {
					cout << getTextDialogue();
				}
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





// +----------------------------------------------------------------------------------------------+ //
// Function Name: fightPVE
// Description: To carry out the "Fight" action between Player and Enemy
// Parameter(s): The player and the specific enemy that is entering the battle, directly referenced
// Return(s): None
// Function Writer(s): Ethan
// +----------------------------------------------------------------------------------------------+ //

void CombatSystem::fightPVE(Entity& player, Entity& specifiedEnemy) {

	int critPlayerDeterminant = rand() % 100 + 1;
	int critEnemyDeterminant = rand() % 100 + 1;

	// Damage Equation
	// Final Damage = Attack * (100 - EnemyDefense)/100
	// Crit Damage =  (100 + CRIT DMG)% * Normal Damage
	// Example:
	// (200 - 50) * 2      |      (ATK - DEF) * CRITDMG   =   300 Final Damage       |       Critical took place after ATK reduced by DEF
	// (200 * 2) - 50      |      (ATK * CRITDMG) - DEF   =   350 Final Damage       |       DEF took place after Critical
	// (200 * 2) * 0.5     |      (ATK * CRITDMG) * DEF   =   200 Final Damage       |
	// (200 * 0.5) * 2     |      (ATK * DEF) * CRITDMG   =   200 Final Damage       |

	// Damage Calculations
	int playerDamage = player.getAttack() - specifiedEnemy.getDefense();                                                                                // If Player Doesn't Crit
	int playerCritDamage = player.getAttack() * player.getCRITDMG() - specifiedEnemy.getDefense();                                                            // If Player Does Crit
	int enemyDamage = specifiedEnemy.getAttack() - player.getDefense();                                                                                       // If Enemy Doesn't Crit
	int enemyCritDamage = specifiedEnemy.getAttack() * specifiedEnemy.getCRITDMG() - player.getDefense();                                                     // If Enemy Does Crit

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
			specifiedEnemy.setHealth(specifiedEnemy.getHealth() - (playerDamage));                                                                            // If DEF <= ATK, Entity Final Damage is given value

			if (static_cast<Enemy&>(specifiedEnemy).getSleepState() == false) {
				if (specifiedEnemy.getHealth() > 0) {
					if (critEnemyDeterminant > specifiedEnemy.getCRITRate()) {
						player.setHealth(player.getHealth() - (enemyDamage));                                                                                     // If DEF <= ATK, Entity Final Damage is given value
					}
					else if (critEnemyDeterminant <= specifiedEnemy.getCRITRate()) {
						player.setHealth(player.getHealth() - (enemyCritDamage));                                                                                 // If DEF <= ATK, Entity Final Damage is given value
					}
				}
			}
			else {
				static_cast<Enemy&>(specifiedEnemy).setSleepState(false);
				enemyDamage = 0;
				enemyCritDamage = 0;
			}
			turnsInBattle++;
		}
	}
	else if (critPlayerDeterminant <= player.getCRITRate()) {
		if (player.getHealth() > 0 && specifiedEnemy.getHealth() > 0) {
			specifiedEnemy.setHealth(specifiedEnemy.getHealth() - (playerCritDamage));                                                                        // If DEF <= ATK, Entity Final Damage is given value

			if (static_cast<Enemy&>(specifiedEnemy).getSleepState() == false) {
				if (specifiedEnemy.getHealth() > 0) {
					if (critEnemyDeterminant > specifiedEnemy.getCRITRate()) {
						player.setHealth(player.getHealth() - (enemyDamage));                                                                                     // If DEF <= ATK, Entity Final Damage is given value
					}
					else if (critEnemyDeterminant <= specifiedEnemy.getCRITRate()) {
						player.setHealth(player.getHealth() - (enemyCritDamage));                                                                                 // If DEF <= ATK, Entity Final Damage is given value
					}
				}
			}
			else {
				static_cast<Enemy&>(specifiedEnemy).setSleepState(false);
				enemyDamage = 0;
				enemyCritDamage = 0;
			}
			turnsInBattle++;
		}
	}

	// Damage Numbers Display (Text Dialogue)
	if (critPlayerDeterminant > player.getCRITRate() && critEnemyDeterminant > specifiedEnemy.getCRITRate()) {                                                // If Player And Enemy DON'T Crit
		setTextDialogue("You dealt " + to_string(playerDamage) + " DMG, received " + to_string(enemyDamage) + " DMG");
	}
	else if (critPlayerDeterminant <= player.getCRITRate() && critEnemyDeterminant > specifiedEnemy.getCRITRate()) {                                          // If Player Crits BUT Enemy doesn't
		setTextDialogue("You dealt " + to_string(playerCritDamage) + " DMG (Critical!), received " + to_string(enemyDamage) + " DMG");
	}
	else if (critPlayerDeterminant > player.getCRITRate() && critEnemyDeterminant <= specifiedEnemy.getCRITRate()) {                                          // If Enemy Crits BUT Player doesn't
		setTextDialogue("You dealt " + to_string(playerDamage) + " DMG, received " + to_string(enemyCritDamage) + " DMG (Critical!)");
	}
	else if (critPlayerDeterminant <= player.getCRITRate() && critEnemyDeterminant <= specifiedEnemy.getCRITRate()) {                                         // If Player And Enemy BOTH Crit
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





// +----------------------------------------------------------------------------------------------+ //
// Function Name: itemPVE
// Description: To carry out the "Item" action between Player and Enemy
// Parameter(s): The player and the specific enemy that is entering the battle, directly referenced
// Return(s): None
// Function Writer(s): Ethan
// +----------------------------------------------------------------------------------------------+ //

void CombatSystem::itemPVE(Entity& player, Entity& specifiedEnemy) {
	bool openInventory = static_cast<Player&>(player).checkInventoryOpen();

	Item** inventoryMenuArray = nullptr;

	switch (static_cast<Player&>(player).getMenuIndex()) {
	case 1:
		inventoryMenuArray = static_cast<Player&>(player).getWeapons();
		break;
	case 2:
		inventoryMenuArray = static_cast<Player&>(player).getArmours();
		break;
	case 3:
		inventoryMenuArray = static_cast<Player&>(player).getConsumables();
		break;
	case 4:
		inventoryMenuArray = static_cast<Player&>(player).getArtifacts();
		break;
	default:
		inventoryMenuArray = static_cast<Player&>(player).getWeapons();
		break;
	}

	int index = static_cast<Player&>(player).getInventoryIndex();
	Item* chosen = inventoryMenuArray[index];

	if (chosen == nullptr) {
		return;
	}

	std::string itemName = chosen->getName();
	
	if (itemName == "Sword" || itemName == "Mace" || itemName == "Scythe" || itemName == "Warhammer") {
		Weapon* newWeapon = static_cast<Weapon*>(chosen);

		if (static_cast<Player&>(player).getCurrentWeapon() != nullptr) {
			player.setAttack(player.getAttack() - static_cast<Player&>(player).getCurrentWeapon()->getAttackVal());
		}

		if (itemName == "Sword") {
			player.setAttack(player.getAttack() + static_cast<Weapon*>(chosen)->getAttackVal());
			setTextDialogue("Switched to " + itemName + " (+" + to_string(static_cast<Weapon*>(chosen)->getAttackVal()) + " ATK)");
		}
		else if (itemName == "Mace") {
			player.setAttack(player.getAttack() + static_cast<Weapon*>(chosen)->getAttackVal());
			setTextDialogue("Switched to " + itemName + " (+" + to_string(static_cast<Weapon*>(chosen)->getAttackVal()) + " ATK)");
		}
		else if (itemName == "Scythe") {
			player.setAttack(player.getAttack() + static_cast<Weapon*>(chosen)->getAttackVal());
			setTextDialogue("Switched to " + itemName + " (+" + to_string(static_cast<Weapon*>(chosen)->getAttackVal()) + " ATK)");
		}
		else if (itemName == "Warhammer") {
			player.setAttack(player.getAttack() + static_cast<Weapon*>(chosen)->getAttackVal());
			setTextDialogue("Switched to " + itemName + " (+" + to_string(static_cast<Weapon*>(chosen)->getAttackVal()) + " ATK)");
		}
	}

	if (itemName == "Heal Potion") {
		player.setHealth(player.getHealth() + static_cast<Potion*>(chosen)->getHeal());
		setTextDialogue("Used " + itemName + " (+" + to_string(static_cast<Potion*>(chosen)->getHeal()) + " HP)");
		chosen->consume();
	}
	else if (itemName == "Strength Potion") {
		player.setAttack(player.getAttack() + static_cast<Potion*>(chosen)->getAttackVal());
		setTextDialogue("Used " + itemName + " (+" + to_string(static_cast<Potion*>(chosen)->getAttackVal()) + " ATK)");
		chosen->consume();
	}
	else if (itemName == "Weakening Potion") {
		specifiedEnemy.setAttack(specifiedEnemy.getAttack() - static_cast<Potion*>(chosen)->getAttackVal());
		setTextDialogue("Used " + itemName + " (-" + to_string(static_cast<Potion*>(chosen)->getAttackVal()) + " Enemy ATK)");
		chosen->consume();
	}
	else if (itemName == "Sleep Potion") {
		static_cast<Enemy&>(specifiedEnemy).setSleepState(true);
		setTextDialogue("Used " + itemName + ". Enemy is asleep for the next turn");
		chosen->consume();
	}
}





// +----------------------------------------------------------------------------------------------+ //
// Function Name: runPVE
// Description: To carry out the "Run" action between Player and Enemy
// Parameter(s): The player and the specific enemy that is entering the battle, directly referenced
// Return(s): None
// Function Writer(s): Ethan
// +----------------------------------------------------------------------------------------------+ //

void CombatSystem::runPVE(Entity& player, Entity& specifiedEnemy) {
	setTextDialogue("You're attempting to run, but you won't go unnoticed. Press Y/N to confirm");                       // Alerts player of their current action, also telling them there are consequences
	char confirm = _getch();                                                                                             // Receive player's confirmation on whether to run or not
	int consDeterminant = rand() % 4;                                                                                    // 3 random consequences may happen + 1 off chance


	switch (confirm) {
	case 'y':                                                                                                            // If player carries on anyway
		if (consDeterminant == 0) {                                                                                      // 1st consequence
			player.setHealth(player.getHealth() * 3 / 4);                                                                // Lose 25% of current HP
			static_cast<Player&>(player).setIsInCombat(false);                                                           // Player exits combat after changes are made
			static_cast<Player&>(player).setJustLeftCombat(true);                                                        // Player gains invulnerability from entering the fight again
			static_cast<Player&>(player).setCombatIsWon(false);                                                          // Reset player's win state (precautionary)
		}
		else if (consDeterminant == 1) {                                                                                 // 2nd consequence
			player.setXP(player.getXP() * 3 / 4);                                                                        // Lose 25% of current XP
			static_cast<Player&>(player).setIsInCombat(false);                                                           // Player exits combat after changes are made
			static_cast<Player&>(player).setJustLeftCombat(true);                                                        // Player gains invulnerability from entering the fight again
			static_cast<Player&>(player).setCombatIsWon(false);                                                          // Reset player's win state (precautionary)
		}
		else if (consDeterminant == 2) {                                                                                 // 3rd consequence
			player.setGold(player.getGold() - 50);                                                                       // Lose 50 Gold
			static_cast<Player&>(player).setIsInCombat(false);                                                           // Player exits combat after changes are made
			static_cast<Player&>(player).setJustLeftCombat(true);                                                        // Player gains invulnerability from entering the fight again
			static_cast<Player&>(player).setCombatIsWon(false);                                                          // Reset player's win state (precautionary)
		}
		else {                                                                                                           // Off chance
			setTextDialogue("Uh oh, you failed to run, the enemy stopped you before you could. Press Y to continue");    // Player fails to run, getting "dragged" back to fight
			int carryOn = _getch();                                                                                       // To receive player input as a move to next dialogue function
			switch (carryOn) {
			case 'y':
				int retaliateDeterminant = rand() % 2;
				if (retaliateDeterminant == 0) {
					setTextDialogue("You struggled, pushing the enemy away from you, sending them against the wall!");
					player.setHealth(player.getHealth() * 9 / 10);                                                       // Player loses 10% of current HP from struggling
					specifiedEnemy.setHealth(specifiedEnemy.getHealth() - player.getAttack() * 7 / 10);                  // Enemies receives 70% of Player's ATK
					static_cast<Player&>(player).setIsInCombat(true);                                                    // Player stays in combat
				}
				else {
					setTextDialogue("The enemy grabbed you by the next, sending you against the wall");
					player.setHealth(player.getHealth() * 8 / 10);                                                       // Player loses 20% of current HP from colliding
					static_cast<Player&>(player).setIsInCombat(true);                                                    // Player stays in combat
				}
			}
		}
	case 'n':                                                                                                            // If player backs out from running
		setTextDialogue("You snapped out of it, kept your head in the game");                                            // Let's them stay in the game
	}
}





// +----------------------------------------------------------------------------------------------+ //
// Function Name: winLoseOutcome
// Description: To carry out what happens if the battle ends
// Parameter(s): The player and the specific enemy that is entering the battle, directly referenced
// Return(s): A boolean of true or false
// Function Writer(s): Ethan
// +----------------------------------------------------------------------------------------------+ //
bool CombatSystem::winLoseCondition(Entity& player, Entity& specifiedEnemy) {
	if (player.getHealth() == 0 && specifiedEnemy.getHealth() == 0) {                                              // If Enemy HP is 0 BUT Player HP is 0
		return true;                                                                                               // Boolean returns isPlayerAlive to be false, exit game
	}
	else if (player.getHealth() == 0) {                                                                            // If Player HP is 0;
		return true;                                                                                               // Boolean returns isPlayerAlive to be false, exit game
	}
	else if (specifiedEnemy.getHealth() == 0 && player.getHealth() > 0) {                                          // If Enemy HP is 0 but Player is Alive
		player.setGold(player.getGold() + specifiedEnemy.getGold());
		player.setXP(player.getXP() + specifiedEnemy.getXP());

		while (player.getXP() > player.getThresholdXP()) {
			player.setXP(player.getXP() - player.getThresholdXP());
			player.setLvl(player.getLvl() + 1);
		}
		static_cast<Player&>(player).setCombatIsWon(true);
	}
	return false;
}