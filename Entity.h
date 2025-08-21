#pragma once
#include <string>
#include<iostream>
using namespace std;
class Entity
{
protected:
    int attack ,health ,damage ,defense ,xp ,gold ,level, CRITDMG, CRITRate;
    int sycophant_heart;
    int xPos;
    int yPos;

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

    void poison(int turns, int dmgPerTurn);


    Entity(int hp, int atk, int dmg, int def, int exp, int g, int lvl, int critdmg, int critrate);

    const static int MAX_LEVEL = 5;
    int currentLevel = 1;
    int thresholdXP[(MAX_LEVEL-1)] = { 50, 100, 200, 300 };
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


	virtual bool isAlive() const {
		return health > 0;
    }

    virtual void healing(int health);
	virtual ~Entity();
    void burn(int turns, int dmgPerTurn);

	void freeze(int turns, int dmgPerTurn);
    
};
  

