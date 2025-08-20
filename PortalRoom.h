#pragma once
#include "Room.h"
class PortalRoom :
    public Room
{
private:
    char** portalRoomArray;
public:
    PortalRoom(int currentStage, int roomNumber);
    ~PortalRoom();
    char** getPortalRoomArray();
};

