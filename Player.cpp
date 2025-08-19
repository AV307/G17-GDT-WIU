#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <conio.h>

Player::Player() {
	health = 100;
	attack = 15;
	defense = 10;
	CRITRate = 25;
	CRITDMG = 50;
	strength = 0;
	identity = 'P';
}
Player::~Player() {

}
void Player::move() {

}

void Player::checkCollision() {

}

void Player::checkConsumption() {

}
