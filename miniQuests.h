#pragma once
#include "iostream"
#include "string"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "item.h"
using namespace std;

class miniQuests {
protected:
    int questCompleted[6];      
    bool questActive[6];        
    string questNames[6];      
    int questGoldReward[6];    
    int questXPReward[6];      
    int numberOfQuests;         

public:
    miniQuests();
    ~miniQuests();

    // Quest management
    void activateQuest(int index);          
    void completeQuest(int index, Player &player);           
    bool isQuestCompleted(int index) const;  

    void showQuests() const;                

    string getQuestName(int index) const;
    int getQuestGoldReward(int index) const;
    int getQuestXPReward(int index) const;
};



	


