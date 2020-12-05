/******************************************************************************
* app_init_map.cpp
* CS 281 - 0798, Fall 2020
*
* Room map initialization functions
* 
* The Room map is an array of Room pointers in each Room.
* Each Room knows which Room can be accessed in each direction.
* There is no overall map of the Rooms.
*******************************************************************************
*/
#include "app.h"

/******************************************************************************
* void initRoomMap()
*******************************************************************************
*/
void initRoomMap()
{
    // Wizard of Illuvitar Dungeons
    g_pTower->setDirectionPtr(ROOM_NORTH, nullptr);
    g_pTower->setDirectionPtr(ROOM_SOUTH, nullptr);
    g_pTower->setDirectionPtr(ROOM_EAST, nullptr);
    g_pTower->setDirectionPtr(ROOM_WEST, nullptr);
    g_pTower->setDirectionPtr(ROOM_UP, nullptr);
    g_pTower->setDirectionPtr(ROOM_DOWN, g_pKeep);

    g_pKeep->setDirectionPtr(ROOM_NORTH, nullptr);
    g_pKeep->setDirectionPtr(ROOM_SOUTH, nullptr);
    g_pKeep->setDirectionPtr(ROOM_EAST, nullptr);
    g_pKeep->setDirectionPtr(ROOM_WEST, nullptr);
    g_pKeep->setDirectionPtr(ROOM_UP, g_pTower);
    g_pKeep->setDirectionPtr(ROOM_DOWN, g_pVault);

    g_pVault->setDirectionPtr(ROOM_NORTH, nullptr);
    g_pVault->setDirectionPtr(ROOM_SOUTH, nullptr);
    g_pVault->setDirectionPtr(ROOM_EAST, g_pTomb);
    g_pVault->setDirectionPtr(ROOM_WEST, g_pCrypt);
    g_pVault->setDirectionPtr(ROOM_UP, g_pKeep);
    g_pVault->setDirectionPtr(ROOM_DOWN, nullptr);

    g_pCrypt->setDirectionPtr(ROOM_NORTH, nullptr);
    g_pCrypt->setDirectionPtr(ROOM_SOUTH, nullptr);
    g_pCrypt->setDirectionPtr(ROOM_EAST, g_pTomb);
    g_pCrypt->setDirectionPtr(ROOM_WEST, nullptr);
    g_pCrypt->setDirectionPtr(ROOM_UP, nullptr);
    g_pCrypt->setDirectionPtr(ROOM_DOWN, nullptr);

    g_pTomb->setDirectionPtr(ROOM_NORTH, nullptr);
    g_pTomb->setDirectionPtr(ROOM_SOUTH, nullptr);
    g_pTomb->setDirectionPtr(ROOM_EAST, nullptr);
    g_pTomb->setDirectionPtr(ROOM_WEST, g_pCrypt);
    g_pTomb->setDirectionPtr(ROOM_UP, nullptr);
    g_pTomb->setDirectionPtr(ROOM_DOWN, nullptr);
}

//#TODO Magic Word In Case Alternate Map
void initRoomTeleport()
{
    // Wizard of Illuvitar Dungeon Teleportation
    g_pTower->setDirectionPtr(ROOM_NORTH, g_pKeep);
    g_pTower->setDirectionPtr(ROOM_SOUTH, g_pTower);
    g_pTower->setDirectionPtr(ROOM_EAST, g_pVault);
    g_pTower->setDirectionPtr(ROOM_WEST, g_pCrypt);
    g_pTower->setDirectionPtr(ROOM_UP, g_pTomb);

    g_pKeep->setDirectionPtr(ROOM_NORTH, g_pKeep);
    g_pKeep->setDirectionPtr(ROOM_SOUTH, g_pTower);
    g_pKeep->setDirectionPtr(ROOM_EAST, g_pVault);
    g_pKeep->setDirectionPtr(ROOM_WEST, g_pCrypt);
    g_pKeep->setDirectionPtr(ROOM_UP, g_pTomb);

    g_pVault->setDirectionPtr(ROOM_NORTH, g_pKeep);
    g_pVault->setDirectionPtr(ROOM_SOUTH, g_pTower);
    g_pVault->setDirectionPtr(ROOM_EAST, g_pVault);
    g_pVault->setDirectionPtr(ROOM_WEST, g_pCrypt);
    g_pVault->setDirectionPtr(ROOM_UP, g_pTomb);

    g_pCrypt->setDirectionPtr(ROOM_NORTH, g_pKeep);
    g_pCrypt->setDirectionPtr(ROOM_SOUTH, g_pTower);
    g_pCrypt->setDirectionPtr(ROOM_EAST, g_pVault);
    g_pCrypt->setDirectionPtr(ROOM_WEST, g_pCrypt);
    g_pCrypt->setDirectionPtr(ROOM_UP, g_pTomb);

    g_pTomb->setDirectionPtr(ROOM_NORTH, g_pKeep);
    g_pTomb->setDirectionPtr(ROOM_SOUTH, g_pTower);
    g_pTomb->setDirectionPtr(ROOM_EAST, g_pVault);
    g_pTomb->setDirectionPtr(ROOM_WEST, g_pCrypt);
    g_pTomb->setDirectionPtr(ROOM_UP, g_pTomb);
}

