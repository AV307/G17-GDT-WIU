#pragma once
#include "iostream"
#include "string"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "item.h"
using namespace std;

using namespace std;

class miniQuests {
protected:
    int questCompleted[7];
    bool questActive[7];
    string questNames[7];
    int questGoldReward[7];
    int questXPReward[7];
    int numberOfQuests;

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


   

  




	


