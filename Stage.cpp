#include "Stage.h"
#include "mainRoom.h"
#include "ShopRoom.h"
#include "TreasureRoom.h"
#include "BedRoom.h"

#include "Game.h"

#include <random>


Stage::Stage(Game* game)
	: game(game), gen(rd()), dis(1, 3)
{
    int currentStage = game->getCurrentStage();

	rooms[1] = new mainRoom[currentStage];

    for (int i{ 1 }; i <= 2; i++) {
        int randomType = dis(gen);
        switch (randomType) {
        case 0:
            rooms[i] = new ShopRoom;
            break;
        case 1:
            rooms[i] = new TreasureRoom;
            break;
        case 2:
            rooms[i] = new BedRoom;
            break;
        }
    }
}

Stage::~Stage() {
    for (int i = 0; i < 3; i++) {
        delete rooms[i];
    }
}