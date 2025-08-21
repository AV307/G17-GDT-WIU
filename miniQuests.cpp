#include "miniQuests.h"
#include "iostream"
#include "string"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "item.h"
using namespace std;

//Benjamin 250572M 
//Constructor for miniQuests, loops through the number of quests and initializes them
miniQuests::miniQuests() {
    for (int i = 0; i < numberOfQuests; i++) {
        questCompleted[i] = 0;
        questActive[i] = false;
        questNames[i] = "Quest " + to_string(i + 1);
        questGoldReward[i] = 10 * (i + 1);
        questXPReward[i] = 5 * (i + 1);
    }
}

miniQuests::~miniQuests() {}

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

void miniQuests::setQuest(int index, string name, int gold, int xp) {
    if (index >= 0 && index < numberOfQuests) {
        questNames[index] = name;
        questGoldReward[index] = gold;
        questXPReward[index] = xp;
        questCompleted[index] = 0;
        questActive[index] = false;
    }
}

void miniQuests::showQuests() const {
    for (int i = 0; i < numberOfQuests; i++) {
        cout << i + 1 << ". " << questNames[i]
            << " - " << (questCompleted[i] ? "Completed" : "Incomplete") << endl;
    }
}

//Benjamin 250572M
//Checks if the player has completed any quests based on their actions
void miniQuests::checkQuestCompletion(Player& player, Enemy& enemy) {
    if (!questCompleted[0] && player.getEnemiesDefeated() >= 10)
        completeQuest(0, player);

    if (!questCompleted[1] && player.hasSolvedPuzzle())
        completeQuest(1, player);

    if (!questCompleted[2] && player.getWeaponCount() >= 5)
        completeQuest(2, player);

    if (!questCompleted[3] && player.getGold() >= 500)
        completeQuest(3, player);

    if (!questCompleted[4] && player.getWeaponCount() >= 10)
        completeQuest(4, player);

    if (!questCompleted[5] && player.getWeaponCount() >= 20)
        completeQuest(5, player);

    if (!questCompleted[6] && enemy.isBossDefeated())
        completeQuest(6, player);
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

int miniQuests::getEnemiesDefeated() const
{
    return 0;
}

bool miniQuests::hasSolvedPuzzle() const
{
    return false;
}

int miniQuests::getWeaponCount() const
{
    return 0;
}
