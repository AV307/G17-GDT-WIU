#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "Potion.h"

#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <random>
#include <conio.h>

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
		consumables[i] = new Potion;
		consumables[i]->setDefenseVal(1);
		consumables[i]->setName("Potion");
	}

	for (int i = 0; i < 10; i++) {
		armoury[i]->setOwned(false);
		armoury[i]->setEquipped(false);

		weaponry[i]->setOwned(false);
		weaponry[i]->setEquipped(false);

		consumables[i]->setOwned(false);
		consumables[i]->setEquipped(false);
	}

	inventoryOpen = false;
	inventoryIndex = 0;
	menuIndex = 1;
	hasKey = false;
}
Player::~Player() {

}
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
	case 13:
		break;
	default:
		break;
	}
}

int Player::getInventoryIndex()
{
	return inventoryIndex;
}

int Player::getMenuIndex()
{
	return menuIndex;
}

bool Player::checkInventoryOpen()
{
	return inventoryOpen;
}

Item** Player::getWeapons()
{
	return weaponry;
}

Item** Player::getArmours()
{
	return armoury;
}

Item** Player::getConsumables()
{
	return consumables;
}
