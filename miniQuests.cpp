#include "miniQuests.h"
#include "iostream"
#include "string"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "item.h"
using namespace std;

miniQuests::miniQuests() {
    numberOfQuests = 6;
    for (int i = 0; i < numberOfQuests; i++) {
        questCompleted[i] = 0;
        questActive[i] = false;
        questNames[i] = "Quest " + to_string(i + 1);  
        questGoldReward[i] = 10 * (i + 1);            
        questXPReward[i] = 5 * (i + 1);              
    }
}

miniQuests::~miniQuests() {
}

void miniQuests::activateQuest(int index) {
    if (index >= 0 && index < numberOfQuests) {
        questActive[index] = true;
        cout << questNames[index] << " is now active!" << endl;
    }
}

void miniQuests::completeQuest(int index, Player& player) {
    if (index >= 0 && index < numberOfQuests && !questCompleted[index]) {
        questCompleted[index] = 1;
        questActive[index] = false;
        cout << questNames[index] << " completed! Reward: "
            << questGoldReward[index] << " gold, "
            << questXPReward[index] << " XP." << endl;
		player.setGold(player.getGold() + questGoldReward[index]);
		player.setXP(player.getXP() + questXPReward[index]);
		player.updateStats();  
	}
	else {
		cout << "Quest already completed or invalid index!" << endl;
    }
}

bool miniQuests::isQuestCompleted(int index) const {
    if (index >= 0 && index < numberOfQuests)
        return questCompleted[index] == 1;
    return false;
}

void miniQuests::showQuests() const {
    for (int i = 0; i < numberOfQuests; i++) {
        cout << i + 1 << ". " << questNames[i]
            << " - " << (questCompleted[i] ? "Completed" : "Incomplete") << endl;
    }
}

string miniQuests::getQuestName(int index) const {
    if (index >= 0 && index < numberOfQuests)
        return questNames[index];
    return "";
}

int miniQuests::getQuestGoldReward(int index) const {
    if (index >= 0 && index < numberOfQuests)
        return questGoldReward[index];
    return 0;
}

int miniQuests::getQuestXPReward(int index) const {
    if (index >= 0 && index < numberOfQuests)
        return questXPReward[index];
    return 0;
}
