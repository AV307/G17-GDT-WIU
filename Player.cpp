#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "Potion.h"
#include "Entity.h"
#include "Enemy.h"
#include "mainRoom.h"
#include "Stage.h"

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
	shopOpen = false;
	inventoryIndex = 0;
	menuIndex = 1;

	hasKey = false;
	hasHammer = false;

	equippedWeapon = nullptr;
	equippedArmour = nullptr;
	currentEnemy = new Enemy("Undead", 'B');
	isInCombat = false;
	isRunning = false; // remove later
	combatIsWon = false;

	currentWeapon = nullptr;

	statPoints = 10;

	CRITRate = 25;
	CRITDMG = 1.5;
	attack = 15;

	action = "Move";

	setXPos(50);
	setYPos(25);
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
		if (!inventoryOpen) {
			inventoryOpen = true;
		}
		else {
			inventoryOpen = false;
		}
	}
	if (input == '6') {
		if (shopOpen) {
			shopOpen = false;
		}
		else {
			shopOpen = false;
		}
	}
	if (input == '/') {
		if (skillTreeOpen == false) {
			skillTreeOpen = true;
		}
		else {
			skillTreeOpen = false;
		}
	}

	if (inventoryOpen) {
		handleInventory(input);
	}
	//else if (shopOpen) {
	//	/*printShopInventory();*/
	//}
	else {
		handleMovement(input);
		for (int m = 0; m < mainRoom::maxEnemy; m++) {
			if (Enemy::getInstance().enemy[m] != nullptr) {
				if (Enemy::getInstance().enemy[m]->isEnemyThere(this, m)) {
					std::cout << Enemy::getInstance().enemy[m]->isEnemyThere(this, m);
					currentEnemy = Enemy::getInstance().enemy[m];
					isInCombat = true;
				}
				else {
					isInCombat = false;
				}
			}
			else if (Enemy::getInstance().enemy[m] == nullptr) {
				std::cout << "YOUWYREOUR" << std::endl;
			}
		}
		//checkCollision(mainRoom::getEnemyList(), rooms[0]);
		//Enemy** enemyList = room->getEnemyList();           
		//int maxEnemy = room->getMaxEnemy();                 
	}
}

bool Player::getIsInCombat() {
	return isInCombat;
}
void Player::setIsInCombat(bool isInCombat) {
	this->isInCombat = isInCombat;
}
bool Player::getRun() {
	return isRunning;
}
void Player::setRun(bool isRunning) {
	this->isRunning = isRunning;
}
bool Player::getCombatIsWon() {
	return combatIsWon;
}
void Player::setCombatIsWon(bool combatIsWon) {
	this->combatIsWon = combatIsWon;
}
Entity* Player::getCurrentEnemy() {
	return currentEnemy;
}
void Player::setCurrentEnemy(Entity* enemy) {
	currentEnemy = enemy;
}
bool Player::getJustLeftCombat() {
	return justLeftCombat;
}
void Player::setJustLeftCombat(bool justLeftCombat) {
	this->justLeftCombat = justLeftCombat;
}

// +----------------------------------------------------------------------------------------------+ //
// Function Name: checkCollision
// Description: Checks collision between Player And Enemy, between Player and other Game Objects
// Parameter(s): The player and the specific enemy that is (if) involved
// Return(s): None
// Function Writer(s): Ethan
// +----------------------------------------------------------------------------------------------+ //

void Player::checkCollision(Entity& specifiedEnemy) {
	if (this->getJustLeftCombat() == false) {
		if (this->getXPos() == specifiedEnemy.getXPos() && this->getYPos() == specifiedEnemy.getYPos()) {
			this->setIsInCombat(true);
			this->setCurrentEnemy(&specifiedEnemy);
		}
	}
	if (this->getJustLeftCombat()) {
		if (this->getXPos() != specifiedEnemy.getXPos() || this->getYPos() != specifiedEnemy.getYPos()) {
			this->setJustLeftCombat(false);
		}
	}
}

Weapon* Player::getCurrentWeapon() {
	return currentWeapon;
}
void Player::setCurrentWeapon(Weapon* weapon) {
	currentWeapon = weapon;
}
Armour* Player::getCurrentArmour() {
	return currentArmour;
}
void Player::setCurrentArmour(Armour* armour) {
	currentArmour = armour;
}

// Skill Tree Related
bool Player::checkSkillTreeOpen() {
	return skillTreeOpen;
}
void Player::setSkillTreeOpen(bool skillTreeOpen) {
	this->skillTreeOpen = skillTreeOpen;
}
int Player::getStatPoints() {
	return statPoints;
}
void Player::setStatPoints(int statPoints) {
	this->statPoints = statPoints;
}

void Player::checkConsumption() {
	
}

//Jayren 250920U
//Determines what actions are made from the player input
void Player::handleMovement(char inputVal)
{
	int xPosition = getXPos();
	int yPosition = getYPos();
	action = "Move";
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
	case' ':
		action = "Interact";
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
			addWeapon("Sword", 5, 0, 0);
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
				//equippedWeapon = weaponry[inventoryIndex];
				//equippedWeapon->setEquipped(true);
			}
			if (armoury[inventoryIndex] != nullptr) {
				equippedWeapon = weaponry[inventoryIndex];
				equippedWeapon->setEquipped(true);
			}
		}
		else if (menuIndex == 2) {
			if (equippedArmour != nullptr) {
				equippedArmour->setEquipped(false);
				//equippedArmour = armoury[inventoryIndex];
				//equippedArmour->setEquipped(true);
			}
			if (armoury[inventoryIndex] != nullptr) {
				equippedArmour = armoury[inventoryIndex];
				equippedArmour->setEquipped(true);
			}
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

//bool Player::checkShopOpen() const
//{
//	return shopOpen;
//}
//Jayren 250920U
//returns hasKey to check if the player has found a key
bool Player::checkHasKey() const
{
	return hasKey;
}

std::string Player::getAction()
{
	return action;
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

void Player::setShopOpen(bool val)
{
	shopOpen = val;
	inventoryOpen = false;
}

bool Player::checkShopOpen() const
{
	return shopOpen;
}

//Benjamin 250572M
//Added critRate and critDamage as default parameters
void Player::addWeapon(const std::string& Name, int attackVal, int critRate = 0, int critDamage = 0)
{
	for (int i = 0; i < 10; i++) {
		if (weaponry[i] == nullptr) {
			Weapon* weapon = new Weapon(Name, attackVal, critRate, critDamage);
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
// checks if the player has a specific weapon in their inventory
bool Player::hasWeapon(const std::string& weaponName) const {
	for (int i = 0; i < 10; i++) {
		if (weaponry[i] != nullptr && weaponry[i]->getName() == weaponName) {
			return true;
		}
	}
	return false;
}

void Player::addItemInventory(Item* item) {
	if (item == nullptr) return;

	std::string itemName = item->getName();  // get the actual name of the Item object

	if (itemName == "Sword") {
		addWeapon("Sword", 10);
	}
	else if (itemName == "Shield") {
		addArmour("Shield", 5);
	}
	else if (itemName == "Chestplate") {
		addArmour("Chestplate", 10);
	}
	else if (itemName == "Artifact") {
		addArtifact("Artifact");
	}
	else if (itemName == "Key") {
		addArtifact("Key");
		setKey(true);
	}
	else if (itemName == "Hammer") {
		addArtifact("Hammer");
		setHammer(true);
	}
	else if (itemName == "Elixir") {
		addConsumable("Elixir", 0, 0, 50); //heal 50
	}
	else if (itemName == "Super Potion") {
		addConsumable("Super Potion", 0, 0, 100); // heal 100
	}
	else if (itemName == "Potion") {
		addConsumable("Potion", 0, 0, 20); // heal 20
	}
	else if (itemName == "Bow") {
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

void Player::setKey(bool val)
{
	hasKey = val;
}

void Player::setHammer(bool val)
{
	hasHammer = val;
}

bool Player::checkHasHammer() const
{
	return hasHammer;
}

//Benjamin 250572M
//Checks if the player has a key in their inventory
bool Player::checkKey() const {
	for (int i = 0; i < 10; i++) {
		if (artifacts[i] != nullptr && artifacts[i]->getName() == "Key") {
			return true;
		}
	}
	return false;
}


//Benjamin 250572M
int Player::getEnemiesDefeated() const {
	return enemiesDefeated;
}

bool Player::hasSolvedPuzzle() const {
	return solvedPuzzle;
}

int Player::getWeaponCount() const {
	return weaponCount;
}

//string Player::printShopInventory() const{
//	std::cout << "\n--------------------------------------------------------------------------------------------------\n";
//	std::cout << "\n--------------------------------------------------------------------------------------------------\n";
//	std::cout << "\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n";
//	for (int r = 0; r < 15; r++) {
//		std::cout << "||                                                                                                ||\n";
//	}                                                            
//	std::cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
//	std::cout << "\n==================================================================================================\n";
//	std::cout << "\n= --------------------- ------------------------ ------------------------ ---------------------- =\n";
//	std::cout << "\n= |      Armour       | |        Weapon        | |        Potion        | |      Artifact      | =\n";
//	std::cout << "\n= --------------------- ------------------------ ------------------------ ---------------------- =\n";
//	std::cout << "\n==================================================================================================\n";
//    std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
//}