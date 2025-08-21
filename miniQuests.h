#pragma once
#include "iostream"
#include "string"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "item.h"
using namespace std;

#pragma once
#include <string>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "item.h"
using namespace std;

class miniQuests {
protected:
    const static int numberOfQuests = 7;
    int questCompleted[numberOfQuests];
    bool questActive[numberOfQuests];
    string questNames[numberOfQuests];
    int questGoldReward[numberOfQuests];
    int questXPReward[numberOfQuests];

public:
    miniQuests();
    ~miniQuests();

    void activateQuest(int index);
    void completeQuest(int index, Player& player);
    bool isQuestCompleted(int index) const;

    void setQuest(int index, string name, int gold, int xp);
    void showQuests() const;

    void checkQuestCompletion(Player& player, Enemy& enemy);

    string getQuestName(int index) const;
    int getQuestGoldReward(int index) const;
    int getQuestXPReward(int index) const;

    int getEnemiesDefeated() const;   
    bool hasSolvedPuzzle() const;     
    int getWeaponCount() const;       
};


   

  




	


