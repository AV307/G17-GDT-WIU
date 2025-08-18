#include "Stage.h"
#include "mainRoom.h"
#include "ShopRoom.h"
#include "TreasureRoom.h"
#include "BedRoom.h"

#include <random>

Stage::Stage()
	: gen(rd()), dis(1, 3)
{
	rooms[1] = new mainRoom;
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

Stage::~Stage()
{
}
