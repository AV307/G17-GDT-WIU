#pragma once
#include "Room.h"
#include <random>
class Stage
{
public:
    Stage();
    ~Stage();
private:
    char stageArray[100][100];
    Room* rooms[3];

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
};

