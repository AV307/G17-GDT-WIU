#pragma once
#include <string>
using namespace std;
class Entity
{
protected:
    int attack ,health ,damage ,defence ,xp ,gold ,level, CRITDMG, CRITRate;

public:
	Entity();

    void setHealth();
    void setAttack();
    void setDamage();
    void setDefense();
    void setXP();
    void setGold();
    void setLvl();
    void setCRITDMG();
    void setCRITRate();


    int getHealth() const;
    int getAttack() const;
    int getDamage() const;
    int getDefense() const;
    int getXP() const;
    int getGold() const;
    int getLvl() const;
    int getCRITDMG() const;
    int getCRITRate() const;





	virtual ~Entity();

};

