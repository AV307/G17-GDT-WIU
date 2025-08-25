#pragma once
#include <string>
#include <iostream>
using namespace std;


class Entity
{
protected:
    int attack ,health ,damage ,defense ,xp ,gold ,level, CRITDMG, CRITRate;

    int dropName = 0;
    const static int MAX_ENEMY_TYPE = 8;
    const string enemyBank[MAX_ENEMY_TYPE] = { "Undead", "Animal", "Flower", "Aquatic", "Vampire", "Humanoid", "Ascendants", "Cubed" };


    // 2 2D array to store the stats and drop respectively
    int enemyStats[7][MAX_ENEMY_TYPE] = {
        { 90 ,100 ,110, 45, 125, 100, 50, 130 },
        { 10, 10, 7, 35, 15, 10, 13, 7 },
        { 10, 10, 9, 10, 12, 10, 35, 5 },
        { 20, 25, 5, 45, 25, 20, 10, 15 },
        { 50, 50, 95, 40, 70, 40, 60, 60 },
        { 8, 9, 12, 8, 14, 7, 10, 13 },
        { 25, 25, 50, 50, 20, 20, 10, 50 }
    };

    int dropAmount[MAX_ENEMY_TYPE][3] = {
        {1, 2, 3},
        {1, 2, 4},
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 4},
        {1, 2, 3},
        {50, 1, 2},
        {2, 3, 5}
    };
    int sycophant_heart = 0, poisoned_fang = 0, withered_nectar = 0, prismarine_fin = 0,
        jar_of_hemovibe = 0, burning_skin = 0, opal_crystals = 0, magma_jelly = 0;
    int enemyDrops[MAX_ENEMY_TYPE] = { sycophant_heart, poisoned_fang, withered_nectar, prismarine_fin, jar_of_hemovibe, burning_skin, opal_crystals, magma_jelly };
    const string enemyDropName[MAX_ENEMY_TYPE] = { "sycophant_heart", "poisoned_fang", "withered_nectar", "prismarine_fin", "jar_of_hemovibe", "burning_skin", "opal_crystals", "magma_jelly" };

    int xPos;
    int yPos;
    string enemyType = "None";
    char enemyStatus = ' ';

public:
	Entity();

    void setHealth(int hp);
    void setAttack(int atk);
    void setDamage(int dmg);
    void setDefense(int def);
    void setXP(int xp);
    void setGold(int gold);
    void setLvl(int lvl);
    void setCritDMG(int critDMG);
    void setCritRate(int critRate);
    void setXPos(int val);
    void setYPos(int val);

    //Drops for trading system
    int drops[8];

    int getListDrops(int index);
    void addDrop(int index, int amount);
    void consumeDrop(int index);

    void poison(int turns, int dmgPerTurn);


    Entity(int hp, int atk, int dmg, int def, int exp, int g, int lvl, int critdmg, int critrate);

    const static int MAX_LEVEL = 15;
    int currentLevel = 1;
    int thresholdXP[(MAX_LEVEL-1)] = { 5, 15, 20, 40, 65, 90, 135, 170, 200, 360, 450, 600, 800, 1000 };
    int getThresholdXP();
    int getHealth() const;
    int getAttack() const;
    int getDamage() const;
    int getDefense() const;
    int getXP() const;
    int getGold() const;
    int getLvl() const;
    int getCRITDMG() const;
    int getCRITRate() const;
    int getXPos() const;
    int getYPos() const;
    string getEntityType() const;
    char getEnemyStatus() const;
    int getListDrops(int enemyType) const;
    string getEntityDropName() const;
    int getEntityDrops() const;
	//string printShopInventory() const;

	virtual bool isAlive() const {
		return health > 0;
    }

    virtual void healing(int health);
	virtual ~Entity();
    void burn(int turns, int dmgPerTurn);

	void freeze(int turns, int dmgPerTurn);
    
};
  

