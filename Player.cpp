#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"

#include <conio.h>
#include <iostream>

Player::Player() {
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
		armoury[i]->setOwned(false);
		armoury[i]->setEquipped(false);

		weaponry[i]->setOwned(false);
		weaponry[i]->setEquipped(false);
	}

	inventoryOpen = false;
	inventoryIndex = 0;
	menuIndex = 0;
}
Player::~Player() {

}
void Player::doAction() {
	char input = _getch();

	if (input == 'E') {
		inventoryOpen = !inventoryOpen;
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
	case'W':
		break;
	case'A':
		break;
	case'S':
		break;
	case'D':
		break;
	default:
		break;
	}
}

void Player::handleInventory(char inputVal)
{
	switch (inputVal) {
	case'W':
		if (inventoryIndex > 0) {
			inventoryIndex--;
		}
		break;
	case'A':
		if (menuIndex > 0) {
			menuIndex--;
		}
		break;
	case'S':
		if (inventoryIndex < 10) {
			inventoryIndex++;
		}
		break;
	case'D':
		if (menuIndex < 3) {
			menuIndex++;
		}
		break;
	default:
		break;
	}
}

int Player::getInventoryIndex()
{
	return inventoryIndex;
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
