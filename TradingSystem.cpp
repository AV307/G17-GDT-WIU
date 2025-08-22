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

    switch (choice) {
    case 0: { // Gold
        int goldReward = 100;
        player->setGold(player->getGold() + goldReward);
        std::cout << "You received " << goldReward << " gold!\n";
        break;
    }
    case 1: { // XP
        int xpReward = 50;
        player->setXP(player->getXP() + xpReward);
        std::cout << "You gained " << xpReward << " XP!\n";
        break;
    }
    case 2: { // Weapon
        player->addWeapon("Sword", 10); 
        std::cout << "You received a Sword!\n";
        break;
    }
    case 3: { // Armour
        player->addArmour("Shield", 5); // 
        std::cout << "You received a Shield!\n";
        break;
    }
    case 4: { // Potion
        player->addConsumable("Potion", 0, 0, 20); 
        std::cout << "You received a Health Potion!\n";
        break;
    }
    case 5: { // Artifact
        player->addArtifact("Artifact");
        std::cout << "You received an Artifact!\n";
        break;
    }
    default:
        std::cout << "Invalid choice.\n";
        return;
    }

   
    entity->consumeDrop(dropIndex);
}
