#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "Potion.h"

#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <random>

Player::Player(){
	for (int i = 0; i < 10; i++) {
		weaponry[i] = new Weapon;
		weaponry[i]->setAttackVal(1);
		weaponry[i]->setName("Weapon");
	}

	for (int i = 0; i < 10; i++) {
		armoury[i] = new Armour;
		armoury[i]->setDefenseVal(1);
		armoury[i]->setName("Armour");
	}

	for (int i = 0; i < 10; i++) {
		consumables[i] = nullptr;
	}

	for (int i = 0; i < 10; i++) {
		armoury[i]->setOwned(true);
		armoury[i]->setEquipped(false);

		weaponry[i]->setOwned(true);
		weaponry[i]->setEquipped(false);
	}

	inventoryOpen = false;
	inventoryIndex = 0;
	menuIndex = 1;
	hasKey = false;

	equippedWeapon = nullptr;
	equippedArmour = nullptr;

	CRITRate = 25;
	CRITDMG = 50;
	strength = 0;
	attack = 15;
}

Player::~Player() {
	for (int i = 0; i < 10; i++) {
		delete armoury[i];
		delete weaponry[i];
		delete consumables[i];
	}

	delete equippedWeapon;
	delete equippedArmour;
}

//Jayren 250920U
//Checks for player input and gets input key. Determines whether to handle inventory movement or player movement
void Player::doAction() {
	char input = _getch();

	if (input == 'e') {
		if (inventoryOpen == false) {
			inventoryOpen = true;
		}
		else {
			inventoryOpen = false;
		}
	}

	if (inventoryOpen == true) {
		handleInventory(input);
	}
	else {
		handleMovement(input);
	}
}

void Player::checkCollision() {

}

void Player::checkConsumption() {

}

void Player::handleMovement(char inputVal)
{
	switch (inputVal) {
	case'w':
		break;
	case'a':
		break;
	case's':
		break;
	case'd':
		break;
	default:
		break;
	}
}

//Jayren 250920U
//Keybinds for selecting items and switching between menus, adding and removing potions (temporary), equipping gear as well.
void Player::handleInventory(char inputVal)
{
	switch (inputVal) {
	case'w':
		if (inventoryIndex > 0) {
			inventoryIndex--;
		}
		break;
	case'a':
		if (menuIndex > 1) {
			menuIndex--;
		}
		break;
	case's':
		if (inventoryIndex < 9) {
			inventoryIndex++;
		}
		break;
	case'd':
		if (menuIndex < 3) {
			menuIndex++;
		}
		break;
	case'f':
		addConsumable("Attack Potion", 5, 0, 0);
		break;
	case'g':
		removeConsumable(inventoryIndex);
		break;
	case 13:
		if (menuIndex == 1) {
			if (equippedWeapon != nullptr) {
				equippedWeapon->setEquipped(false);
			}
			equippedWeapon = weaponry[inventoryIndex];
			equippedWeapon->setEquipped(true);
		}
		else if (menuIndex == 2) {
			if (equippedArmour != nullptr) {
				equippedArmour->setEquipped(false);
			}
			equippedArmour = armoury[inventoryIndex];
			equippedArmour->setEquipped(true);
		}
		break;	
	default:
		break;
	}
}

//Jayren 250920U
//Returns the inventoryIndex to get selected item
int Player::getInventoryIndex()
{
	return inventoryIndex;
}

//Jayren 250920U
//Returns the menuIndex to get selected menu screen
int Player::getMenuIndex()
{
	return menuIndex;
}

//Jayren 250920U
//returns inventoryOpen to check if inventory is Open or closed
bool Player::checkInventoryOpen()
{
	return inventoryOpen;
}

//Jayren 250920U
//returns hasKey to check if the player has found a key
bool Player::checkKey()
{
	return hasKey;
}

//Jayren 250920U
//returns the array of weapons
Item** Player::getWeapons()
{
	return weaponry;
}

//Jayren 250920U
//returns the array of armours
Item** Player::getArmours()
{
	return armoury;
}

//Jayren 250920U
//returns the array of consumables
Item** Player::getConsumables()
{
	return consumables;
}

//Jayren 250920U
//adds a consumable to the consumable array
void Player::addConsumable(std::string Name, int attackVal, int defenseVal, int healVal)
{
	for (int i = 0; i < 10; i++) {
		if (consumables[i] == nullptr) {
			Potion* consumable = new Potion;
			consumable->setAttackVal(attackVal);
			consumable->setDefenseVal(defenseVal);
			consumable->setHealVal(healVal);
			consumable->setName(Name);

			consumables[i] = consumable;
			break;
		}
	}
}

//Jayren 250920U
//removes a consumable from the consumables array
void Player::removeConsumable(int index)
{
	if (consumables[index] != nullptr) {
		delete consumables[index];
		consumables[index] = nullptr;
	}
}

//Jayren 250920U
//updates player's damage and defence stats based on equipped gear
void Player::updateStats()
{
	int weaponAttackBonus = 0;
	(equippedWeapon != nullptr) ? weaponAttackBonus = equippedWeapon->getAttackVal() : 0;
	setDamage(attack + weaponAttackBonus);

	int armourDefenseBonus = 0;
	(equippedArmour != nullptr) ? armourDefenseBonus = equippedArmour->getDefenseVal() : 0;
	setDefence(defence + armourDefenseBonus);
}
