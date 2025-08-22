#include "TradingSystem.h"
#include <iostream>

TradingSystem::TradingSystem(Player* p, Entity* e)
{
    player = p;
    entity = e;
}

void TradingSystem::showAvailableDrops() {
    std::cout << "Available drops to trade:\n";
    for (int i = 0; i < 8; i++) {
        std::cout << i << " - " << drops[i]
            << " (You have: " << entity->getListDrops(i) << ")\n";
    }
}

void TradingSystem::tradeDrop(int dropIndex, int choice) {
    if (dropIndex < 0 || dropIndex >= 8) {
        std::cout << "Invalid drop index.\n";
        return;
    }

    int dropCount = entity->getListDrops(dropIndex);
    if (dropCount <= 0) {
        std::cout << "You don’t have any of that drop!\n";
        return;
    }

    std::cout << "Trading " << drops[dropIndex] << "...\n";

    if (choice == 0) { // Gold
        int goldReward = 100; // fixed since no rand
        player->setGold(player->getGold() + goldReward);
        std::cout << "You received " << goldReward << " gold!\n";
    }
    else if (choice == 1) { // XP
        int xpReward = 50;
        player->setXP(player->getXP() + xpReward);
        std::cout << "You gained " << xpReward << " XP!\n";
    }
    else if (choice == 2) { // Item
        std::cout << "You received a Health Potion!\n";
    }
    else {
        std::cout << "Invalid choice.\n";
        return;
    }

    // Consume the drop
    entity->consumeDrop(dropIndex);
}
