#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "mainRoom.h"
#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "Stage.h"

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
    bool shopOpen;

    bool hasKey;
    bool hasHammer;

    int menuIndex;
    int inventoryIndex;
    int itemsTraded;

    int enemiesDefeated;      
    bool solvedPuzzle;        
    int weaponCount;

    std::string action;

    // Combat Related
    bool isInCombat;
    bool isRunning;
    bool combatIsWon;
    Entity* currentEnemy;
    bool justLeftCombat;

    Weapon* currentWeapon;
    Armour* currentArmour;

    bool skillTreeOpen;
    int statPoints;


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
    bool getJustLeftCombat();
    void setJustLeftCombat(bool justLeftCombat);

    Enemy enemyInstance;
    Weapon* getCurrentWeapon();
    void setCurrentWeapon(Weapon* weapon);
    Armour* getCurrentArmour();
    void setCurrentArmour(Armour* armour);

    bool checkSkillTreeOpen();
    void setSkillTreeOpen(bool skillTreeOpen);
    int getStatPoints();
    void setStatPoints(int statPoints);

    int getInventoryIndex();
    int getMenuIndex();
    int getItemsTraded();
    int resetStats();
	int setPosition(int x, int y);

    bool checkInventoryOpen();
    
    std::string getAction();

    Item** getWeapons();
    Item** getArmours();
    Item** getConsumables();
    Item** getArtifacts();

    //void addWeapon(std::string Name, int attackVal, int critRate, int critDamage);
    void addWeapon(const std::string& Name, int attackVal, int critRate, int critDamage);
    void removeWeapon(int index);

    void addArmour(std::string Name, int defenseVal);
    void removeArmour(int index);

    void addConsumable(std::string Name, int attackVal, int defenseVal, int healVal);
    void removeConsumable(int index);

    void addArtifact(std::string Name);

    void updateStats();
    bool hasWeapon(const std::string& weaponName) const;
    void addItemInventory(Item* item);

	void printInventory() const;

    void setKey(bool val);
    bool checkHasKey() const;

    void setHammer(bool val);
    bool checkHasHammer() const;

    bool checkKey() const;

};



