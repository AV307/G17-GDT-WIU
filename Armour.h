#pragma once  
#include "Item.h"  
#include <string>  

using namespace std;  
class Armour : public Item  
{  
private:  
    const static int maxArmourTypes = 4;  
    string armourName[maxArmourTypes] = { "Shield", "Helmet", "Stoneplate", "Boots" };  
    int defenseBoost[maxArmourTypes] = { 5, 10, 15, 7 };  
	string armourNameVal;
    int defenseVal;
public:  
    Armour();  
    Armour(int armourIndex); // Fixed parameter type and spelling  
    ~Armour();  

	string getArmourName() const;
	int getDefenseBoost() const;
};
#include "Armour.h"  

