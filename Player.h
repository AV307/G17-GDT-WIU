#pragma once
#include "Entity.h"
#include "Item.h"
class Player : public Entity
{
private:
    Item* weaponry[10];
    Item* armoury[10];
    Item* consumables[10];

    Item* equippedWeapon;
    Item* equippedArmour;
    
    bool inventoryOpen;
    bool hasKey;

    int menuIndex;
    int inventoryIndex;

    int CRITRate, CRITDMG, strength;
public:

    Player();
    ~Player();
    void doAction();
    void checkCollision();
    void checkConsumption();
    void handleMovement(char inputVal);
    void handleInventory(char inputVal);

    int getInventoryIndex();
    int getMenuIndex();

    bool checkInventoryOpen();
    bool checkKey();

    Item** getWeapons();
    Item** getArmours();
    Item** getConsumables();
    void addConsumable(std::string Name, int attackVal, int defenseVal);
    void removeConsumable(int index);
};



