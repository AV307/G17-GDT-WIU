#pragma once
#include "Entity.h"
#include "Item.h"
#include "Weapon.h"
class Player : public Entity
{
private:
    Item* weaponry[10];
    Item* armoury[10];
    Item* consumables[10];
    Item* artifacts[10];
	Item* shopInventory[10];

    Item* equippedWeapon;
    Item* equippedArmour;
    
    bool inventoryOpen;
    bool hasKey;

    int menuIndex;
    int inventoryIndex;
    int itemsTraded;

    int enemiesDefeated;      
    bool solvedPuzzle;        
    int weaponCount;         

    std::string action;

    bool isInCombat;
    bool isRunning;
    bool combatIsWon;
    Entity* currentEnemy;


    int CRITRate, CRITDMG, strength;
public:

    Player();
    ~Player();
    void doAction();
    void checkCollision(Entity& specifiedEnemy);
    void checkConsumption();
    void handleMovement(char inputVal);
    void handleInventory(char inputVal);
    int getEnemiesDefeated() const;    
    bool hasSolvedPuzzle() const;      
    int getWeaponCount() const;     

    bool getIsInCombat();
    void setIsInCombat(bool isInCombat);
    bool getRun();
    void setRun(bool isRunning);
    bool getCombatIsWon();
    void setCombatIsWon(bool combatIsWon);
    Entity* getCurrentEnemy();
    void setCurrentEnemy(Entity* specifiedEnemy);


    int getInventoryIndex();
    int getMenuIndex();
    int getItemsTraded();
    int resetStats();
	int setPosition(int x, int y);

    bool checkInventoryOpen();
    bool checkKey();
    
    std::string getAction();

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
    void addItemInventory(const std::string& name);

	void printInventory() const;
    bool checkKey() const;
};



