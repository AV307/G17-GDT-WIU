#include "RoomObjects.h"
#include <iostream>

// Ang Zhi En 252317H
// Constructor for roomObjects, creates empty room and creates array for objects
// Incomplete
RoomObjects::RoomObjects(bool openSide, int roomColumn, int roomWidth, int roomHeight)
{
    objects = new Object** [roomHeight];
    for (int i = 0; i < roomHeight; i++) {
        objects[i] = new Object*[roomWidth];
        for (int j = 0; j < roomWidth; j++) {
            objects[i][j] = nullptr;
        }
    }

    // creates empty room with walls
    for (int i{ 0 }; i < roomHeight; i++)
    {
        for (int j{ 0 }; j < roomWidth; j++)
        {
            if (i == 0 || i == roomHeight - 1 || j == 0 || j == roomWidth - 1)
            {
                objects[i][j] = new Object{WALL, -1, false, " ", ' '}; // set to wall
            }
            else 
            {
                objects[i][j] = new Object{ SPACE, -1, false, " ", ' ' };; // set to space
            }
        }
    }

    if (openSide)
    {
        if (roomColumn > 40)
        {
            // left wall gap
            for (int i = roomHeight / 2 - 2; i <= roomHeight / 2 + 1; i++) {
                objects[i][0] = new Object{ SPACE, -1, false, " ", ' ' };
            }
        }
        else
        {
            // right wall gap
            for (int i = roomHeight / 2 - 2; i <= roomHeight / 2 + 1; i++) {
                objects[i][roomWidth - 1] = new Object{ SPACE, -1, false, " ", ' ' };
            }
        }
    }
}

RoomObjects::~RoomObjects()
{
}

// Ang Zhi En 252317H
// Add (all) objects into a room after checking what room it is
// Incomplete
void RoomObjects::addObjects(int roomWidth, int roomHeight, int currentStage, char roomType)
{
    // essentially presets for the rooms
    switch (roomType)
    {
    case 'M': // main room
        switch (currentStage)
        {
        case 1:
            for (int i = 19; i < 29; i++) {
                objects[i][8] = new Object{ WALL, -1, false, " ", ' ' };
            }
            for (int i = 2; i < 8; i++) {
                objects[19][i] = new Object{ WALL, -1, false, " ", ' ' };
            }
            for (int i = 14; i < 19; i++) {
                objects[i][3] = new Object{ WALL, -1, false, " ", ' ' };
            }
            for (int i = 1; i < 11; i++) {
                objects[12][i] = new Object{ WALL, -1, false, " ", ' ' };
            }
            for (int i = 13; i < 18; i++) {
                objects[i][6] = new Object{ WALL, -1, false, " ", ' ' };
            }
            objects[14][7] = new Object{ WALL, -1, false, " ", ' ' };
            objects[14][8] = new Object{ WALL, -1, false, " ", ' ' };

            for (int i = 9; i < 20; i++) {
                objects[23][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 24; i++) {
                objects[i][10] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 4; i < 24; i++) {
                objects[i][18] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 23; i < 30; i++) {
                objects[i][12] = new Object{ WALL, -1, false, " ", ' ' };
			}

            for (int i = 9; i < 12; i++) {
                objects[26][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 23; i < 30; i++) {
                objects[i][19] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 19; i < 25; i++) {
                objects[24][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 10; i < 19; i++) {
                objects[18][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 10; i < 19; i++) {
                objects[4][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 19; i < 30; i++) {
                objects[16][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 19; i < 30; i++) {
                objects[14][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 4; i++) {
                objects[i][26] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 26; i < 30; i++) {
                objects[4][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 9; i++) {
                objects[7][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 6; i++) {
                objects[10][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 6; i < 13; i++) {
                objects[i][21] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 10; i < 15; i++) {
                objects[i][24] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 25; i < 27; i++) {
                objects[11][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 12; i < 14; i++) {
                objects[i][26] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 22; i < 30; i++) {
                objects[8][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 22; i < 28; i++) {
                objects[6][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            objects[13][7] = new Object{ TELEPORTER1, 1, false, " ", ' ' };
            objects[24][9] = new Object{ TELEPORTER2, 1, false, " ", ' ' };

            objects[17][11] = new Object{ TELEPORTER1, 2, false, " ", ' ' };
            for (int i = 11; i < 18; i++) {
                objects[8][i] = new Object{ TELEPORTER2, 2, false, " ", ' ' };
                objects[9][i] = new Object{ TELEPORTER2, 2, false, " ", ' ' };
                objects[10][i] = new Object{ TELEPORTER2, 2, false, " ", ' ' };
                objects[11][i] = new Object{ TELEPORTER2, 2, false, " ", ' ' };
            }
            for (int i = 8; i < 12; i++) {
                objects[i][13] = new Object{ TELEPORTER1, -1, false, " ", ' ' };
            }

            objects[15][19] = new Object{ TELEPORTER1, 3, false, " ", ' ' };
            objects[1][27] = new Object{ TELEPORTER2, 3, false, " ", ' ' };

            objects[13][25] = new Object{ TELEPORTER1, 4, false, " ", ' ' };
            objects[17][26] = new Object{ TELEPORTER2, 4, false, " ", ' ' };

            objects[22][9] = new Object{ CHEST, -1, false, " ", 'H' };
            objects[2][1] = new Object{ CHEST, -1, false, " ", 'K' };
            objects[11][1] = new Object{ CHEST, -1, false, "Art", 'A' };

            objects[24][12] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };
            objects[4][14] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };
            objects[14][21] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };
            objects[27][8] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };

            objects[25][18] = new Object{ SWITCH, 1, false, " ", ' ' };
            objects[3][28] = new Object{ SWITCH, 3, false, " ", ' ' };
            objects[28][9] = new Object{ SWITCH, 5, false, " ", ' ' };

            objects[23][15] = new Object{ DOOR, 1, false, " ", ' ' };
            objects[18][15] = new Object{ DOOR, 2, false, " ", ' ' };
            objects[13][24] = new Object{ DOOR, 3, false, " ", ' ' };
            objects[2][10] = new Object{ DOOR, 4, false, " ", ' ' };
            objects[11][5] = new Object{ DOOR, 5, false, " ", ' ' };

            objects[19][11] = new Object{ PRESSUREPLATE, 2, false, " ", ' ' };
            objects[26][20] = new Object{ PRESSUREPLATE, 4, false, " ", ' ' };

            objects[19][16] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };

            objects[25][20] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[27][20] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[28][20] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };

            objects[25][21] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[26][21] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[28][21] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };

            objects[27][22] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[26][22] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[28][22] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };

            objects[26][23] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[28][23] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };

            objects[0][15] = new Object{ KEYDOOR, -1, false, " ", ' ' };

            objects[23][4] = new Object{ SIGN, -1, false, " ", ' ',
                "Hey! Welcome to the dungeon!" };
            objects[21][15] = new Object{ SIGN, -1, false, " ", ' ',
                "You will find these blocks laying around. Push them onto those buttons on the floor!" };
            objects[26][15] = new Object{ SIGN, -1, false, " ", ' ',
                "Levers control doors, interact with them to open and close doors!" };
            objects[16][15] = new Object{ SIGN, -1, false, " ", ' ',
                "Teleporters bring you to another location. You will have to find the right path through these teleporters. Third time's the charm!" };
            objects[2][14] = new Object{ SIGN, -1, false, " ", ' ',
                "You will need a key to open that door. Try searching the right side." };
            objects[27][25] = new Object{ SIGN, -1, false, " ", ' ',
                "You cannot push multiple blocks at a time. Good luck with this small puzzle!" };
            objects[6][8] = new Object{ SIGN, -1, false, " ", ' ',
                "Every room has an artifact, something you can collect for achievements. These artifacts will have additional challenges in order to get them." };
            break;
        case 2:
            // VERTICAL WALLS

            for (int i = 16; i < 30;i++) {
                objects[i][6] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 23; i < 30; i++) {
                objects[i][12] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 13; i < 20; i++) {
                objects[i][9] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 11; i < 17; i++) {
                objects[i][12] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 14; i++) {
                objects[i][8] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 11; i < 16; i++) {
                objects[i][13] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 11; i < 16; i++) {
                objects[i][14] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 11; i < 16; i++) {
                objects[i][22] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 11; i < 16; i++) {
                objects[i][27] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 5; i < 9; i++) {
                objects[i][6] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 21; i < 24; i++) {
                objects[i][14] = new Object{ WALL, -1, false, " ", ' ' };
            }

            objects[27][27] = new Object{ WALL, -1, false, " ", ' ' };
            objects[26][27] = new Object{ WALL, -1, false, " ", ' ' };
			// HORIZONTAL WALLS

            for (int i = 0; i < 7; i++) {
                objects[21][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 7; i++) {
                objects[16][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 7; i < 9; i++) {
                objects[19][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 7; i < 12; i++) {
                objects[23][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 10; i < 12; i++) {
                objects[16][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 13; i < 30; i++) {
                objects[15][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 9; i < 28; i++) {
                objects[11][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 9; i < 30; i++) {
                objects[7][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 8; i++) {
                objects[8][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 8; i++) {
                objects[13][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 3; i++) {
                objects[14][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 15; i < 17; i++) {
                objects[14][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 20; i < 22; i++) {
                objects[12][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 19; i < 22; i++) {
                objects[14][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            objects[12][18] = new Object{ WALL, -1, false, " ", ' ' };
            objects[5][7] = new Object{ WALL, -1, false, " ", ' ' };

            // OBJECTS

            objects[15][1] = new Object{ TELEPORTER1, 1, false, " ", ' ' };
            objects[28][7] = new Object{ TELEPORTER2, 1, false, " ", ' ' };

            objects[13][11] = new Object{ TELEPORTER1, 2, false, " ", ' ' };
            objects[9][1] = new Object{ TELEPORTER2, 2, false, " ", ' ' };

            objects[21][3] = new Object{ TOPDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[13][3] = new Object{ TOPDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[12][15] = new Object{ TOPDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[12][19] = new Object{ TOPDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[13][17] = new Object{ TOPDIRECTIONALDOOR, -1, false, " ", ' ' };

            objects[18][6] = new Object{ RIGHTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[6][8] = new Object{ RIGHTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[12][16] = new Object{ RIGHTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[26][12] = new Object{ RIGHTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[12][17] = new Object{ RIGHTDIRECTIONALDOOR, -1, false, " ", ' ' };

            objects[23][9] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[14][18] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };

            objects[9][8] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[15][9] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };

            objects[14][17] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[13][16] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[13][15] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[13][18] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[13][19] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[13][20] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[13][21] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };

            objects[12][25] = new Object{ CHEST, -1, false, " ", 'H' };
            objects[9][15] = new Object{ CHEST, -1, false, " ", 'K' };
            objects[3][4] = new Object{ CHEST, -1, false, "Art2", 'A' };

            objects[8][7] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };
            objects[13][22] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };
            objects[11][17] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };

            objects[12][11] = new Object{ SWITCH, 1, false, " ", ' ' };
            objects[15][2] = new Object{ DOOR, 1, false, " ", ' ' };

            objects[16][18] = new Object{ PRESSUREPLATE, 2, false, " ", ' ' };
            objects[23][13] = new Object{ DOOR, 2, false, " ", ' ' };

            objects[16][13] = new Object{ PRESSUREPLATE, 3, false, " ", ' ' };
            objects[28][27] = new Object{ DOOR, 3, false, " ", ' ' };

            objects[22][7] = new Object{ PRESSUREPLATE, 4, false, " ", ' ' };
            objects[15][25] = new Object{ DOOR, 4, false, " ", ' ' };

            objects[16][28] = new Object{ PRESSUREPLATE, 5, false, " ", ' ' };
            objects[8][3] = new Object{ DOOR, 5, false, " ", ' ' };

            objects[16][14] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[22][13] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[22][12] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[26][28] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };

            objects[0][15] = new Object{ KEYDOOR, -1, false, " ", ' ' };
            break;
        case 3:
            // VERTICAL WALLS

            for (int i = 24; i < 29; i++) {
                objects[i][3] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 16; i < 29; i++) {
                objects[i][6] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 10; i < 29; i++) {
                objects[i][12] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 10; i < 29; i++) {
                objects[i][18] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 16; i < 24; i++) {
                objects[i][10] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 23; i < 29; i++) {
                objects[i][25] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 4; i < 12; i++) {
                objects[i][5] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 4; i < 11; i++) {
                objects[i][13] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 4; i < 9; i++) {
                objects[i][10] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 4; i++) {
                objects[i][11] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 4; i < 8; i++) {
                objects[i][21] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 2; i < 5; i++) {
                objects[i][22] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 8; i++) {
                objects[i][24] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 7; i < 12; i++) {
                objects[i][23] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 7; i < 11; i++) {
                objects[i][25] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 7; i < 10; i++) {
                objects[i][27] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 6; i < 9; i++) {
                objects[i][15] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 6; i < 9; i++) {
                objects[i][16] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 4; i < 9; i++) {
                objects[i][10] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 22; i < 28; i++) {
                objects[i][14] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 22; i < 25; i++) {
                objects[i][16] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 15; i < 18; i++) {
                objects[i][25] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 15; i < 18; i++) {
                objects[i][26] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 15; i < 18; i++) {
                objects[i][28] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 22; i < 26; i++) {
                objects[i][2] = new Object{ WALL, -1, false, " ", ' ' };
            }

			// HORIZONTAL WALLS

            for (int i = 0; i < 7; i++) {
                objects[19][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 4; i < 7; i++) {
                objects[24][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 6; i < 11; i++) {
                objects[16][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 10; i < 15; i++) {
                objects[23][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 14; i < 17; i++) {
                objects[22][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 14; i < 17; i++) {
                objects[24][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 12; i < 15; i++) {
                objects[26][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 12; i < 16; i++) {
                objects[27][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 17; i < 21; i++) {
                objects[27][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 22; i < 26; i++) {
                objects[27][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 25; i < 30; i++) {
                objects[23][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 18; i < 30; i++) {
                objects[17][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 18; i < 30; i++) {
                objects[13][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 12; i < 19; i++) {
                objects[18][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 7; i < 13; i++) {
                objects[13][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 12; i < 19; i++) {
                objects[10][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 0; i < 13; i++) {
                objects[11][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 18; i < 22; i++) {
                objects[9][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 23; i < 28; i++) {
                objects[7][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 24; i < 28; i++) {
                objects[5][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 24; i < 30; i++) {
                objects[3][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 11; i < 23; i++) {
                objects[2][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 15; i < 23; i++) {
                objects[4][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 15; i < 22; i++) {
                objects[6][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 15; i < 22; i++) {
                objects[7][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 5; i < 14; i++) {
                objects[4][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 10; i < 14; i++) {
                objects[8][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 25; i < 30; i++) {
                objects[11][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 6; i < 8; i++) {
                objects[23][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            for (int i = 6; i < 13; i++) {
                objects[27][i] = new Object{ WALL, -1, false, " ", ' ' };
            }

            objects[23][9] = new Object{ WALL, -1, false, " ", ' ' };

			// OBJECTS

            objects[3][19] = new Object{ TORCH, -1, false, " ", ' ' };
            objects[14][15] = new Object{ TORCH, -1, false, " ", ' ' };
            objects[23][15] = new Object{ TORCH, -1, false, " ", ' ' };
            objects[26][9] = new Object{ TORCH, -1, false, " ", ' ' };
            objects[28][4] = new Object{ TORCH, -1, false, " ", ' ' };
            objects[15][4] = new Object{ TORCH, -1, false, " ", ' ' };
            objects[8][9] = new Object{ TORCH, -1, false, " ", ' ' };
            objects[15][25] = new Object{ TORCH, -1, false, " ", ' ' };
            objects[27][28] = new Object{ TORCH, -1, false, " ", ' ' };
            objects[16][21] = new Object{ TORCH, -1, false, " ", ' ' };

            objects[26][17] = new Object{ TELEPORTER1, 1, false, " ", ' ' };
            objects[28][11] = new Object{ TELEPORTER2, 1, false, " ", ' ' };

            objects[17][7] = new Object{ TELEPORTER1, 2, false, " ", ' ' };
            objects[20][1] = new Object{ TELEPORTER2, 2, false, " ", ' ' };

            objects[25][2] = new Object{ TELEPORTER1, 3, false, " ", ' ' };
            objects[24][13] = new Object{ TELEPORTER2, 3, false, " ", ' ' };

            objects[5][6] = new Object{ TELEPORTER1, 4, false, " ", ' ' };
            objects[14][19] = new Object{ TELEPORTER2, 4, false, " ", ' ' };

            objects[16][27] = new Object{ TELEPORTER1, 5, false, " ", ' ' };
            objects[18][19] = new Object{ TELEPORTER2, 5, false, " ", ' ' };

            objects[22][11] = new Object{ TELEPORTER1, 6, false, " ", ' ' };
            objects[28][5] = new Object{ TELEPORTER2, 6, false, " ", ' ' };

            objects[3][12] = new Object{ TELEPORTER1, 7, false, " ", ' ' };
            objects[7][11] = new Object{ TELEPORTER2, 7, false, " ", ' ' };

            objects[28][15] = new Object{ TELEPORTER1, 8, false, " ", ' ' };
            objects[28][28] = new Object{ TELEPORTER2, 8, false, " ", ' ' };

            objects[18][4] = new Object{ SWITCH, -1, false, " ", ' ' };
            objects[18][5] = new Object{ SWITCH, -1, false, " ", ' ' };
            objects[18][2] = new Object{ SWITCH, -1, false, " ", ' ' };
            objects[17][1] = new Object{ SWITCH, -1, false, " ", ' ' };
            objects[16][1] = new Object{ SWITCH, -1, false, " ", ' ' };
            objects[15][1] = new Object{ SWITCH, -1, false, " ", ' ' };
            objects[14][1] = new Object{ SWITCH, -1, false, " ", ' ' };
            objects[13][1] = new Object{ SWITCH, -1, false, " ", ' ' };
            objects[12][4] = new Object{ SWITCH, -1, false, " ", ' ' };
            objects[12][6] = new Object{ SWITCH, -1, false, " ", ' ' };

            objects[18][15] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[17][15] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[21][5] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[22][5] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[22][1] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[23][1] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[23][5] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[20][5] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[24][1] = new Object{ BOTTOMDIRECTIONALDOOR, -1, false, " ", ' ' };

            objects[20][5] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[23][4] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[21][3] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[20][3] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[21][2] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[20][2] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[21][1] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[23][3] = new Object{ LEFTDIRECTIONALDOOR, -1, false, " ", ' ' };

            objects[20][4] = new Object{ TOPDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[21][4] = new Object{ TOPDIRECTIONALDOOR, -1, false, " ", ' ' };
            objects[22][3] = new Object{ TOPDIRECTIONALDOOR, -1, false, " ", ' ' };

            objects[22][4] = new Object{ RIGHTDIRECTIONALDOOR, -1, false, " ", ' ' };

            objects[25][14] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };
            objects[23][11] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };
            objects[13][28] = new Object{ BREAKABLEWALL, -1, false, " ", ' ' };

            objects[19][13] = new Object{ SWITCH, 1, false, " ", ' ' };
            objects[22][15] = new Object{ DOOR, 1, false, " ", ' ' };

            objects[13][22] = new Object{ SWITCH, 2, false, " ", ' ' };
            objects[15][21] = new Object{ DOOR, 2, false, " ", ' ' };

            objects[18][3] = new Object{ SWITCH, 3, false, " ", ' ' };
            objects[13][7] = new Object{ DOOR, 3, false, " ", ' ' };

            objects[12][5] = new Object{ SWITCH, 4, false, " ", ' ' };
            objects[11][9] = new Object{ DOOR, 4, false, " ", ' ' };

            objects[19][28] = new Object{ SWITCH, 5, false, " ", ' ' };
            objects[27][21] = new Object{ DOOR, 5, false, " ", ' ' };

            objects[12][1] = new Object{ PRESSUREPLATE, -1, false, " ", ' ' };

            objects[28][7] = new Object{ PRESSUREPLATE, 6, false, " ", ' ' };
            objects[27][10] = new Object{ DOOR, 6, false, " ", ' ' };
            objects[27][9] = new Object{ DOOR, 6, false, " ", ' ' };
            objects[27][8] = new Object{ DOOR, 6, false, " ", ' ' };

            objects[17][9] = new Object{ PRESSUREPLATE, 7, false, " ", ' ' };
            objects[20][6] = new Object{ DOOR, 7, false, " ", ' ' };

            objects[14][23] = new Object{ PRESSUREPLATE, 8, false, " ", ' ' };
            objects[14][25] = new Object{ DOOR, 8, false, " ", ' ' };

            objects[15][23] = new Object{ PRESSUREPLATE, 9, false, " ", ' ' };
            objects[14][26] = new Object{ DOOR, 9, false, " ", ' ' };

            objects[16][20] = new Object{ PRESSUREPLATE, 10, false, " ", ' ' };
            objects[14][27] = new Object{ DOOR, 10, false, " ", ' ' };

            objects[28][10] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[12][2] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[18][9] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[20][9] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[21][9] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[22][9] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[14][20] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[15][20] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };
            objects[15][22] = new Object{ MOVEABLEBLOCK, -1, false, " ", ' ' };

            objects[28][2] = new Object{ CHEST, -1, false, " ", 'H' };
            objects[5][12] = new Object{ CHEST, -1, false, " ", 'K' };
            objects[24][26] = new Object{ CHEST, -1, false, "Art3", 'A' };
            objects[28][21] = new Object{ CHEST, -1, false, "Rubber Duck", 'A' };

            objects[0][15] = new Object{ KEYDOOR, -1, false, " ", ' '};
            break;
        case 4:
            break;
        case 5:
            break;
        }
        break;
    case 'B': // bed room
        objects[10][10] = new Object{ BED, -1, false, " ", ' ' };
        break;
    case 'S': // shop room
        objects[10][10] = new Object{ SHOPKEEPER, -1, false, " ", ' ' };
        break;
    case 'F': // boss room
        switch (currentStage)
        {
        case 3:
            break;
        case 5:
            break;
        }
        break;
    case 'P': // portal room
        objects[5][5] = new Object{ PORTAL, -1, false, " ", ' ' };

        for (int i = 3; i < 8; i++)
        {
            objects[10][i] = new Object{ BOSSDOOR, -1, false, " ", ' ' };
        }
        break;
    case 'T': // treasure room
        objects[10][10] = new Object{ CHEST, -1, false, " ", 'I' };
        break;
    case 'C': // corridor room
        // creates empty room with SPACE
        for (int i = 0; i < roomHeight; i++) {
            for (int j = 0; j < roomWidth; j++) {
                objects[i][j] = new Object{ SPACE, -1, false, " ", ' ' };
            }
        }

        // Create walls
        for (int i = 0; i < roomWidth; i++) {
            if (i < 18 || i >= 23) {
                objects[11][i] = new Object{ WALL, -1, false, " ", ' ' };
                objects[16][i] = new Object{ WALL, -1, false, " ", ' ' };
            }
        }

        for (int i = 0; i < roomHeight; i++) {
            if (i < 12 || i >= 16) {
                objects[i][17] = new Object{ WALL, -1, false, " ", ' ' };
                objects[i][23] = new Object{ WALL, -1, false, " ", ' ' };
            }
        }
        break;
    }


    /*if (objects[yCoord][xCoord] != nullptr) 
    {
        delete objects[yCoord][xCoord];
    }
    objects[yCoord][xCoord] = new Object{type, id};*/
}

// Ang Zhi En 252317H
// Removes object from a coordinate
void RoomObjects::removeObject(int xCoord, int yCoord)
{
    if (objects[yCoord][xCoord] != nullptr) 
    {
        delete objects[yCoord][xCoord];
        objects[yCoord][xCoord] = nullptr;
    }
}

// Ang Zhi En 252317H
// Getter for object type at a certain coordinate
ObjectType RoomObjects::getObjectType(int column, int row) const
{
    Object* object{ objects[row][column] };
    if (object != nullptr) 
    {
        return object->type;
    }

    // might change this code later if we use SPACE instead of nullptr in roomobject constructor
    return SPACE;
}

// Ang Zhi En 252317H
// Getter for object ID at a certain coordinate
// Returns -1 if there's no ID (e.g. torch)
int RoomObjects::getObjectId(int column, int row) const
{
    Object* object = objects[row][column];
    if (object != nullptr) 
    {
        return object->id;
    }
    return -1;
}

//Jayren 250920U
//Getter for the state of the object
//Return toggle state of object, if no toggle state, return false
bool RoomObjects::getObjectToggle(int column, int row) const
{
    Object* obj = objects[row][column];
    if (obj != nullptr) {
        return obj->toggled;
    }
    return false;
}

std::string RoomObjects::getObjectItemName(int column, int row) const
{
    Object* obj = objects[row][column];
    if (obj != nullptr) {
        return obj->itemName;
    }
    return " ";
}

char RoomObjects::getObjectItemType(int column, int row) const
{
    Object* obj = objects[row][column];
    if (obj != nullptr) {
        return obj->itemType;
    }
    return ' ';
}

std::string RoomObjects::getObjectMessage(int column, int row) const
{
    Object* obj = objects[row][column];
    if (obj != nullptr) {
        return obj->message;
    }
    return " ";
}

//Jayren 250920U
//Setter for the state of the object
//Toggles state from true to false or false to true
void RoomObjects::setObjectToggle(int column, int row, bool toggle)
{
    Object* obj = objects[row][column];
    if (obj != nullptr) {
        obj->toggled = toggle;
    }
}

void RoomObjects::setObjectType(int column, int row, ObjectType type)
{
    Object* obj = objects[row][column];
    if (obj != nullptr) {
        obj->type = type;
    }
}
