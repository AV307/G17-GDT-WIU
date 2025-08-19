#include "Stage.h"
#include "mainRoom.h"
#include "ShopRoom.h"
#include "TreasureRoom.h"
#include "BedRoom.h"
#include "BossRoom.h"

#include "Game.h"

#include <random>

Stage::Stage(Game* game)
	: game(game), gen(rd()), dis(1, 3)
{
    int currentStage = game->getCurrentStage();

	rooms[0] = new mainRoom;


    int randomRoom1 = dis(gen);
    switch (randomRoom1) {
    case 0:
        rooms[1] = new ShopRoom;
        break;
    case 1:
        rooms[1] = new TreasureRoom;
        break;
    case 2:
        rooms[1] = new BedRoom;
        break;
    }

    if (currentStage == 3 || currentStage == 5) {
        rooms[2] = new BossRoom;
    }
    else {
        int randomRoom2 = dis(gen);
        switch (randomRoom2) {
        case 0:
            rooms[1] = new ShopRoom;
            break;
        case 1:
            rooms[1] = new TreasureRoom;
            break;
        case 2:
            rooms[1] = new BedRoom;
            break;
        }
    }
}

Stage::~Stage() {
    for (int i = 0; i < 3; i++) {
        delete rooms[i];
    }
}