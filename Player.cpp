#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "Potion.h"
#include "Entity.h"
#include "Enemy.h"

#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <random>

Player::Player(){
	for (int i = 0; i < 10; i++) {
		weaponry[i] = nullptr;
		armoury[i] = nullptr;
		consumables[i] = nullptr;
		artifacts[i] = nullptr;
	}

	inventoryOpen = false;
	inventoryIndex = 0;
	menuIndex = 1;
	hasKey = false;

	equippedWeapon = nullptr;
	equippedArmour = nullptr;

	CRITRate = 25;
	CRITDMG = 1.5;
	attack = 15;
	setXPos(50);
	setYPos(90);
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
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prev_mode;
	GetConsoleMode(hInput, &prev_mode);

	DWORD new_mode = prev_mode;
	new_mode &= ~ENABLE_QUICK_EDIT_MODE;
	new_mode &= ~ENABLE_INSERT_MODE;

	SetConsoleMode(hInput, new_mode);

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

//Caleb 250601F
//KeyPressed movements for player
void Player::handleMovement(char inputVal)
{
	int xPosition = getXPos();
	int yPosition = getYPos();
	switch (inputVal) {
	case'w':
		setYPos(yPosition - 1);
		break;
	case'a':
		setXPos(xPosition - 1);
		break;
	case's':
		setYPos(yPosition + 1);
		break;
	case'd':
		setXPos(xPosition + 1);
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
		if (menuIndex < 4) {
			menuIndex++;
		}
		break;
	case'f':
		if (menuIndex == 1) {
			addWeapon("Sword", 5);
		}
		if (menuIndex == 2) {
			addArmour("Chestplate", 5);
		}
		if (menuIndex == 3) {
			addConsumable("Potion", 5, 5, 5);
		}
		if (menuIndex == 4) {
			addArtifact("Artifact");
		}
		std::cout << "hi";
		break;
	case'g':
		if (menuIndex == 1) {
			removeWeapon(inventoryIndex);
		}
		if (menuIndex == 2) {
			removeArmour(inventoryIndex);
		}
		if (menuIndex == 3) {
			removeConsumable(inventoryIndex);
		}
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

int Player::getItemsTraded()
{
	return itemsTraded;
}

int Player::resetStats()
{
	return 0;
}

int Player::setPosition(int x, int y)
{
	return 0;
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

Item** Player::getArtifacts()
{
	return artifacts;
}



void Player::addWeapon(std::string Name, int attackVal)
{
	for (int i = 0; i < 9; i++) {
		if (weaponry[i] == nullptr) {
			Weapon* weapon = new Weapon;
			weapon->setName(Name);
			weapon->setAttackVal(attackVal);
			weapon->setDefenseVal(0);
			weapon->setEquipped(false);
			weaponry[i] = weapon;
			break;
		}
	}
}

void Player::removeWeapon(int index)
{
	if (weaponry[index] != nullptr) {
		delete weaponry[index];
		weaponry[index] = nullptr;
	}
}

void Player::addArmour(std::string Name, int defenseVal)
{
	for (int i = 0; i < 9; i++) {
		if (armoury[i] == nullptr) {
			Armour* armour = new Armour;
			armour->setName(Name);
			armour->setAttackVal(0);
			armour->setDefenseVal(defenseVal);
			armour->setEquipped(false);
			armoury[i] = armour;
			break;
		}
	}
}

void Player::removeArmour(int index)
{
	if (armoury[index] != nullptr) {
		delete armoury[index];
		armoury[index] = nullptr;
	}
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



void Player::addArtifact(std::string Name)
{
	for (int i = 0; i < 10; i++) {
		if (artifacts[i] == nullptr) {
			Item* artifact = new Item;;
			artifact->setName(Name);
			artifact->setAttackVal(0);
			artifact->setDefenseVal(0);

			artifacts[i] = artifact;
			break;
		}
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
	setDefense(defense + armourDefenseBonus);
}


//Benjamin 250572M
//Shop items
void Player::addItemInventory(const std::string& name) {
	if (name == "Sword") {
		addWeapon("Sword", 10);
	}
	else if (name == "Shield") {
		addArmour("Shield", 5);
	}
	else if (name == "Potion") {
		addConsumable("Potion", 0, 0, 20); // heal 20
	}
	else if (name == "Bow") {
		addWeapon("Bow", 7);
	}
}

//Benjamin 250572M
// loops through the player's inventory. Prints the player's inventory, including weapons, armour, consumables, and artifacts
void Player::printInventory() const {
	std::cout << "\n====== INVENTORY ======\n";

	std::cout << "\nWeapons:\n";
	for (int i = 0; i < 10; i++) {
		if (weaponry[i] != nullptr) {
			std::cout << i << ". " << weaponry[i]->getName();
			if (weaponry[i] == equippedWeapon) std::cout << " (Equipped)";
			std::cout << "\n";
		}
	}

	std::cout << "\nArmour:\n";
	for (int i = 0; i < 10; i++) {
		if (armoury[i] != nullptr) {
			std::cout << i << ". " << armoury[i]->getName();
			if (armoury[i] == equippedArmour) std::cout << " (Equipped)";
			std::cout << "\n";
		}
	}

	std::cout << "\nConsumables:\n";
	for (int i = 0; i < 10; i++) {
		if (consumables[i] != nullptr) {
			std::cout << i << ". " << consumables[i]->getName() << "\n";
		}
	}

	std::cout << "\nArtifacts:\n";
	for (int i = 0; i < 10; i++) {
		if (artifacts[i] != nullptr) {
			std::cout << i << ". " << artifacts[i]->getName() << "\n";
		}
	}

	std::cout << "=======================\n";
}

//Benjamim 250572M
int Player::getEnemiesDefeated() const {
	return enemiesDefeated;
}

bool Player::hasSolvedPuzzle() const {
	return solvedPuzzle;
}

int Player::getWeaponCount() const {
	return weaponCount;
}
