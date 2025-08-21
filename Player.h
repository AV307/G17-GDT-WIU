#pragma once
#include "Entity.h"
#include "Item.h"
class Player : public Entity
{
private:
    Item* weaponry[10];
    Item* armoury[10];
    Item* consumables[10];
    Item* artifacts[10];

    Item* equippedWeapon;
    Item* equippedArmour;
    
    bool inventoryOpen;
    bool hasKey;

    int menuIndex;
    int inventoryIndex;

    int enemiesDefeated;      
    bool solvedPuzzle;        
    int weaponCount;          


    int CRITRate, CRITDMG, strength;
public:

    Player();
    ~Player();
    void doAction();
    void checkCollision();
    void checkConsumption();
    void handleMovement(char inputVal);
    void handleInventory(char inputVal);
    int getEnemiesDefeated() const;    
    bool hasSolvedPuzzle() const;      
    int getWeaponCount() const;        


    int getInventoryIndex();
    int getMenuIndex();

    bool checkInventoryOpen();
    bool checkKey();

    Item** getWeapons();
    Item** getArmours();
    Item** getConsumables();
    Item** getArtifacts();

    void addWeapon(std::string Name, int attackVal);
    void removeWeapon(int index);

    void addArmour(std::string Name, int defenseVal);
    void removeArmour(int index);

    void addConsumable(std::string Name, int attackVal, int defenseVal, int healVal);
    void removeConsumable(int index);

    void addArtifact(std::string Name);

    void updateStats();
};



