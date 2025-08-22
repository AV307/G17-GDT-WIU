#pragma once
#include<iostream>
#include<string>
#include "Player.h"
#include "Entity.h"
#include "Item.h"
using namespace std;

class TradingSystem
{
protected:
	Player* player;
	Entity* entity;
	Item* item;
	int itemPrice;
	string itemName;
};

