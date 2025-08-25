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

void TradingSystem::tradeDrop(int dropIndex, int choice, std::string enemyType) {
    if (dropIndex < 0 || dropIndex >= 8) {
        std::cout << "Invalid drop index.\n";
        return;
    }

    int dropCount = entity->getListDrops(dropIndex);
    if (dropCount <= 0) {
        std::cout << "You don't have any of that drop!\n";
        return;
    }

    std::cout << "Trading " << drops[dropIndex].name << " from " << enemyType << "...\n";

    int goldReward = 0;
    int xpReward = 0;

    // Determine rewards based on enemy type
    if (enemyType == "Basic") {
        goldReward = drops[dropIndex].goldBasic;
        xpReward = drops[dropIndex].xpBasic;
    } else if (enemyType == "Elite") {
        goldReward = drops[dropIndex].goldElite;
        xpReward = drops[dropIndex].xpElite;
    } else if (enemyType == "Delux") {
        goldReward = drops[dropIndex].goldDelux;
        xpReward = drops[dropIndex].xpDelux;
    } else if (enemyType == "Boss") {
        goldReward = drops[dropIndex].goldBoss;
        xpReward = drops[dropIndex].xpBoss;
    } else {
        goldReward = 1;
        xpReward = 1;
    }

    switch (choice) {
    case 0: // Gold
        player->setGold(player->getGold() + goldReward);
        std::cout << "You received " << goldReward << " gold!\n";
        break;

    case 1: // XP
        player->setXP(player->getXP() + xpReward);
        std::cout << "You gained " << xpReward << " XP!\n";
        break;

    case 2: // Weapon
    {
        const std::string weaponHierarchy[4] = { "Sword", "Mace", "Scythe", "Warhammer" };
        std::string nextWeapon = "";
        for (int i = 0; i < 4; i++) {
            if (!player->hasWeapon(weaponHierarchy[i])) {
                nextWeapon = weaponHierarchy[i];
                break;
            }
        }

        if (!nextWeapon.empty()) {
            int atk = goldReward + xpReward / 2;
            int critRate = xpReward % 20;
            int critDamage = atk / 2;

            player->addWeapon(nextWeapon, atk, critRate, critDamage);

            std::cout << "You received " << nextWeapon
                      << " (ATK: " << atk
                      << ", CRIT Rate: " << critRate
                      << "%, CRIT Dmg: " << critDamage << ")!\n";
        } else {
            std::cout << "You already have all weapons! You get gold instead.\n";
            player->setGold(player->getGold() + goldReward);
            std::cout << "You received " << goldReward << " gold!\n";
        }
        break;
    }

    case 3: 
        player->addArmour("Shield", goldReward);
        std::cout << "You received a Shield with defense " << goldReward << "!\n";
        break;

    default:
        std::cout << "Invalid choice.\n";
        return;
    }

    entity->consumeDrop(dropIndex);
}
