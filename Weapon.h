#pragma once
#include "Item.h"
#include <string>
using namespace std;
class Weapon : public Item
{
private:
	int attack;        // Base attack value
	int critRate;      // Critical hit rate (percentage)
	int critDamage;    // Critical hit damage (percentage of normal damage)
    string weaponType[4] = {"Sword", "Mace", "Scythe", "Warhammer"};
	int attackValues[4] = { 8, 10, 12, 15 };
	double critRateValues[4] = { 0.1, 0.15, 0.2, 0.25 }; // 10%, 15%, 20%, 25%
	double critDamageValues[4] = { 0.2, 0.5, 0.7, 1.0 }; // 50%, 75%, 100%, 125%

public:
    Weapon(); // default constructor
    Weapon(int weaponIndex);
    Weapon(const std::string& name, int atk, int critRate, int critDamage); // parameterized constructor
    ~Weapon();

    // Optional: getters/setters if needed
	int getAttack() const;  
    int getCritRateVal() const;
    int getCritDamageVal() const;

    void setCritRate(int val);
    void setCritDamage(int val);
};

