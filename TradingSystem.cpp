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

    int goldReward = 0;
    int xpReward = 0;

    // Assign rewards based on drop type
    switch (dropIndex) {
    case 0: goldReward = 25; xpReward = 1; break;   // Sycophant Heart
    case 1: goldReward = 25; xpReward = 3; break;   // Poisoned Fang
    case 2: goldReward = 50; xpReward = 2; break;   // Withered Nectar
    case 3: goldReward = 50; xpReward = 2; break;   // Prismarine Fin
    case 4: goldReward = 20; xpReward = 2; break;   // Jar of Hemovibe
    case 5: goldReward = 20; xpReward = 2; break;   // Burning Skin
    case 6: goldReward = 50; xpReward = 25; break;  // Opal Crystals
    case 7: goldReward = 50; xpReward = 5; break;   // Magma Jelly
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
        player->addWeapon("Sword", 10);
        std::cout << "You received a Sword!\n";
        break;
    case 3: // Armour
        player->addArmour("Shield", 5);
        std::cout << "You received a Shield!\n";
        break;
    case 4: // Potion
        player->addConsumable("Potion", 0, 0, 20);
        std::cout << "You received a Health Potion!\n";
        break;
    case 5: // Artifact
        player->addArtifact("Artifact");
        std::cout << "You received an Artifact!\n";
        break;
    default:
        std::cout << "Invalid choice.\n";
        return;
    }

    entity->consumeDrop(dropIndex); // Remove 1 drop after trading
}
