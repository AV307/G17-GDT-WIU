#include "Entity.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"
#include "Stage.h"
#include "mainRoom.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
string newPos;

//pair<int, int> Enemy::setEnemyPos(int enemyXPair, int enemyYPair) {  
//	enemyArray[enemyYPair][enemyXPair] = true;						// paring is a function that returns a pair of values can be both bool or int or string etc.
//	return make_pair(enemyXPair, enemyYPair);
//};
Enemy::Enemy() {

}
void Enemy::initializeEnemyArraies() {
	for (int h = 0; h < MAX_ENEMY_TYPE; h++) {
		enemyDrops[h] = 0;
	}
	for (int i = 0; i < emaxEnemy; ++i) {
		for (int j = 0; j < 2; ++j) {
			enemyPos[i][j] = 0;
		}
	}
	for (int x = 0; x < emaxEnemy; x++) {
		enemy[x] = nullptr;
	}

	for (int y = 0; y < 28; y++) {
		for (int z = 0; z < 28; z++) {
			enemyArray[y][z] = false;
		}
	}
}
Enemy::Enemy(string type, char status) {
	//Checks what type of the enemy is (Undead/Animal/Flower ... )
	xp = 0;
	gold = 0;
	dropAMTID = 0;
	for (int i = 0; i < MAX_ENEMY_TYPE; i++) {
		if (type == enemyBank[i]) {
			enemyType = type;
			health = enemyStats[0][i];
			attack = enemyStats[1][i];
			defense = enemyStats[2][i];
			//CRITRate = enemyStats[3][i];
			//CRITDMG = enemyStats[4][i];

			enemyDrops[i] += 1;
			xp = enemyStats[5][i];
			chance = enemyStats[6][i];
			dropName = i;

			CRITRate = critRate[i];
			CRITDMG = critDMG[i];
		}
	}
	enemyStatus = status;

	switch (status) {

	case 'N':
		break;
	case 'B':
		health = health/2;
		attack = attack/2;
		defense = defense/3;
		break;
	case 'E':
		dropAMTID = 0;
		health = health*static_cast<int>(100 / 100);
		attack = attack*static_cast<int>(100 / 100);
		defense = defense*static_cast<int>(100 / 100);
		break;
	case 'D':
		dropAMTID = 1;
		health = health*static_cast<int>(150 / 100);
		attack = attack*static_cast<int>(125 / 100);
		defense = defense*static_cast<int>(125 / 100);
		break;
	case 'X':
		dropAMTID = 2;
		health = health*static_cast<int>(200 / 100);
		attack = attack*static_cast<int>(150 / 100);
		defense = defense*static_cast<int>(120 / 100);
		break;
	}
}

void Enemy::initEnemies(int eX, int eY, int eI) {
		enemyXR = eX;
		enemyYR = eY;
		char status = entityStatus[rand() % 2];
		enemy[eI] = new Enemy(enemyBank[rand() % 8], status);
		enemyPos[eI][0] = eX;
		enemyPos[eI][1] = eY;
		enemyArray[eY][eX] = true;
		//std::cout << enemyPos[eI][0] << enemyPos[eI][1] << "\n";
		if (enemy[eI] == nullptr) {
			//std::cerr << "enemy[" << eI << "] is STILL nullptr 😡\n";
		}
		else {
			//std::cout << "enemy[" << eI << "] initialized ✅\n";
		}

}

int Enemy::setEnemyXR(int x) const {
	return x;
}
int Enemy::setEnemyYR(int y) const {
	return y;
}

//void Enemy::resetEnemy() {
//	for (int r = 0; r < emaxEnemy; r++) {
//		delete enemy[r];
//		enemy[r] = nullptr;
//	}
//}

bool Enemy::isEnemyThere(Player* player, int indexE) const {
	if (player == nullptr) return false;
	if (indexE < 0 || indexE >= emaxEnemy) return false;


	if (player->getXPos() == enemyPos[indexE][0]) {
		if (player->getYPos() == enemyPos[indexE][1]) {
			std::cout << "Enemy encountered at (" << enemyXR << ", " << enemyYR << ")\n";
			return true;
		}
	}

	return false;
}

Enemy& Enemy::getInstance() {
	static Enemy instance;
	return instance;
}

Enemy::~Enemy() {  }

//Caleb 250601F
//Calculate the chance of the enemy loot based on level, status, and type
//Completed
int Enemy::calculateDropChance(int mult) {
	return (rand() % 100 <= chance + mult) ? 1 : 0;
}

//Caleb 250601F
//Calculate enemy loot based on level, status, and type
//Completed
void Enemy::calculateLoot()
{
	currentStage = 1; 
	xp = 10;
	gold = 5;

	switch (enemyStatus) {
	case 'B':
		xp = static_cast<int>(baseEXP / 100);
		gold = 3 + currentStage;
		enemyDrops[dropName] = calculateDropChance(0);
		return;
	case 'E':
		if (enemyType == "Ascendants" || dropAmount[dropName][dropAMTID] == 50) {          // If drop amount is 50% chance and type is ascendants
			enemyDrops[dropName] = calculateDropChance(40);
		}
		else {
			enemyDrops[dropName] = dropAmount[dropName][dropAMTID];
		}
		xp = static_cast<int>(baseEXP / 70);
		baseEXP += 2;
		gold = 5 + currentStage;
		return;

	case 'D':
		xp = static_cast<int>(baseEXP / 35);
		gold = 10 + currentStage;
		baseEXP += 3;
		enemyDrops[dropName] = dropAmount[dropName][dropAMTID];
		return;
	case 'X':
		xp = static_cast<int>(baseEXP / 10);
		baseEXP += 4;
		gold = 25 + currentStage;
		enemyDrops[dropName] = dropAmount[dropName][dropAMTID];
		return;
	}
}

//Caleb 250601F
//Checks if enemy is killed, returns true if does and vice versa
//Completed

bool Enemy::isBossDefeated() const
{
	if (enemyStatus != 'X') {
		return false;
	}
	if (enemyStatus == 'X') {
		if (health <= 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool Enemy::killEnemy(Game* game) {
	if (health <= 0) {
		isBossDefeated();
		calculateLoot();
		delete this;
		return true;
	}
	else {
		return false;
	}
}

//Caleb 250601F
//Getter functions for enemy statistics
//Completed <- may expand 
int Enemy::getHealth() const
{
	return health;
}
int Enemy::getAttack() const
{
	return attack;
}
int Enemy::getDefense() const
{
	return defense;
}
int Enemy::getXP() const
{
	return baseEXP;
}
string Enemy::getEnemyType() const {
	return enemyType;
}
char Enemy::getEnemyStatus() const {
	return enemyStatus;
}

// enemy.cpp
Enemy* enemyList[10];

Enemy** getEnemyList() {
	return enemyList;
}
// DRAFT DESIGNS
// vampire
//			    \--\           \--\ 
//               \  \ -----------  \
//				Y \    o  v  v   o  \
//			   / o| ______________   \
//            /___/                  /
//            Y Y \__mm_________mm__/      
// 
// Humanoid
//           _________________
//          |                 |
//			|UUUUUUUUUUUUUUUUU|
//        __|   o   ---   o   |__ 
//       |  |_________________|  |    						
//       |_X|                 |X_|
//          |_______|-|_______|
//
// Ascendants
//				  /|\
//				 / |  \
//				/__ | __\
//			   /|-| 0 |- \
//			  / _ | ___|  _\
//			 / __ / \_ / \__\
//
// Cubed
//           __________________
//          |\_________________\
//          ||                 |
//          ||                 |
//          ||                 |
//          ||    o    >     o |
//          \|_________________|

bool Enemy::getSleepState() {
	return sleepState;
}

void Enemy::setSleepState(bool sleepState) {
	this->sleepState = sleepState;
}