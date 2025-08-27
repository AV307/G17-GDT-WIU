#pragma once  
#include "Room.h"  
#include "Enemy.h"  

class Game;
class mainRoom : public Room  
{  
private:  

public:  
    void setUpEnemy();
    Enemy enemyInstance; 
    char** mainRoomArray;  
    int setX, setY;  
    mainRoom(int currentStage);  
    ~mainRoom();  
    char** getMainRoomArray();  
    char getSpecificMainRoomTile(int x, int y);  
    const static int maxEnemy = 50;  
    Enemy* enemy[maxEnemy];

    int getMaxEnemy();  
    int getX() const;  
    int getY() const;  
    Enemy* getEnemyList(int num); 
};
