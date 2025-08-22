#include "TradingSystem.h"
#include <iostream>
using namespace std;

TradingSystem::TradingSystem(Player* p, Entity* e) {
    player = p;
    entity = e;
}

void TradingSystem::showAvailableDrops() {
    cout << "Available drops to trade:\n";
    for (int i = 0; i < 8; i++) {
        cout << i << " - " << drops[i].name
            << " (You have: " << entity->getListDrops(i) << ")\n";
    }
}

void TradingSystem::tradeDrop(int dropIndex, int choice, string enemyType) {
    if (dropIndex < 0 || dropIndex >= 8) {
        cout << "Invalid drop index.\n";
        return;
    }

    int dropCount = entity->getListDrops(dropIndex);
    if (dropCount <= 0) {
        cout << "You don't have any of that drop!\n";
        return;
    }

    cout << "Trading " << drops[dropIndex].name << " from " << enemyType << "...\n";

    int goldReward = 0;

    // Adjust gold reward based on enemy type
    if (enemyType == "Basic") goldReward = drops[dropIndex].goldBasic;
    else if (enemyType == "Elite") goldReward = drops[dropIndex].goldElite;
    else if (enemyType == "Delux") goldReward = drops[dropIndex].goldDelux;
    else if (enemyType == "Boss") goldReward = drops[dropIndex].goldBoss;
    else goldReward = 1; // default

    // Apply choice reward
    switch (choice) {
    case 0: // Gold
        player->setGold(player->getGold() + goldReward);
        cout << "You received " << goldReward << " gold!\n";
        break;
    case 1: // XP
        player->setXP(player->getXP() + goldReward); // could scale XP same way
        cout << "You gained " << goldReward << " XP!\n";
        break;
    case 2: // Weapon
        player->addWeapon("Sword", goldReward);
        cout << "You received a Sword with power " << goldReward << "!\n";
        break;
    default:
        cout << "Invalid choice.\n";
        return;
    }

    entity->consumeDrop(dropIndex); // consume one drop
}
