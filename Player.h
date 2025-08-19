#pragma once
#include "Entity.h"
#include "Item.h"
class Player : public Entity
{
private:
    Item* weaponry[10];
    Item* armoury[10];
    Item* consumables[10];

    bool inventoryOpen;
    bool hasKey;

    int menuIndex;
    int inventoryIndex;
public:
    Player();
    Player(string n, int h, int atk, int dmg, int def, int xp, int gold, int lvl);
    ~Player();
    void doAction();
    void checkCollision();
    void checkConsumption();
    void handleMovement(char inputVal);
    void handleInventory(char inputVal);

    int getInventoryIndex();
    int getMenuIndex();

    bool checkInventoryOpen();
    Item** getWeapons();
    Item** getArmours();
    Item** getConsumables();

};



