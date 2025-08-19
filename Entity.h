#pragma once
#include <string>
using namespace std;
class Entity
{
protected:
    int attack ,health ,damage ,defence ,xp ,gold ,level, CRITDMG, CRITRate;

public:
	Entity();

    void setHealth(int hp);
    void setAttack(int atk);
    void setDamage(int dmg);
    void setDefense(int defence);
    void setXP(int xp);
    void setGold(int gold);
    void setLvl(int lvl);
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

