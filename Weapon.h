#pragma once
#include "Item.h"

class Weapon : public Item
{
private:
	int critRate;      // Critical hit rate (percentage)
	int critDamage;    // Critical hit damage (percentage of normal damage)
public:
    Weapon(); // default constructor
    Weapon(const std::string& name, int atk, int critRate, int critDamage); // parameterized constructor
    ~Weapon();

    // Optional: getters/setters if needed
    int getCritRate() const;
    int getCritDamage() const;
};

