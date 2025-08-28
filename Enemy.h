#pragma once
#include "Entity.h"
#include <cstdlib>
#include <string>
using namespace std;

class Game;
class Player;

class Enemy : public Entity {
private:
    int currentStage = 0;
    int baseEXP = 0;
    int chance = 0;
    int dropAMTID = 0;
    bool sleepState;
    bool enemyArray[28][28];
    int enemyXR, enemyYR;
    char entityStatus[4] = { 'B','E','D','X' };
    //pair<int, int> enemyPositions[50];

public:
    Enemy();
    Enemy(string type, char status);
    ~Enemy();
    bool killEnemy(Game* game);
    bool isBossDefeated() const;
    void calculateLoot();
    int calculateDropChance(int mult);
    bool isEnemyThere(Player* player, int indexE) const;
    //pair<int, int> setEnemyPos[mainRoom::maxEnemy];

    //void resetEnemy();
    bool getSleepState();
    void setSleepState(bool sleepState);
    void initializeEnemyArraies();
    void initEnemies(int eX, int eY, int eI);
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getXP() const;
    string getEnemyType() const;
    char getEnemyStatus() const;

    static const int emaxEnemy = 50;

    Enemy* enemy[emaxEnemy];
    int enemyPos[emaxEnemy][2];
    Enemy** getEnemyPos();
    //Enemy** getEnemyArray();
    int setEnemyXR(int x) const;
    int setEnemyYR(int y) const;
    //air<int, int> enemyPositions[emaxEnemy];
    static Enemy& getInstance(); 

};


