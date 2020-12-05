/******************************************************************************
* app.cpp
* CS 281 - 0798, Fall 2020
*
* App main with entry point main()
*******************************************************************************
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <cstdlib>
#include <time.h>

// app common include file
#include "app.h"

// local function prototypes
void displayMessageQueue(std::vector<std::string>& msgQueue);
int mapMoveCommand(char cmd);
char menuOption();
Room* teleport();


// global variables available (extern) to all app code
Room* g_pTower = nullptr;
Room* g_pKeep = nullptr;
Room* g_pVault = nullptr;
Room* g_pCrypt = nullptr;
Room* g_pTomb = nullptr;

Player* pForNewFeature;

/******************************************************************************
* int main()
* entry point
*******************************************************************************
*/
int main()
{
    // seed random number generator for CarryIt power values
    time_t t;
    srand(static_cast<unsigned int>(time(&t)));

    // accumulate messages for display each game loop iteration
    std::vector<std::string> messageQueue;

    // init game rooms with text, Treasure, Weapons, Bogies
    g_pTower = initTower();
    g_pKeep = initKeep();
    g_pVault = initVault();
    g_pCrypt = initCrypt();
    g_pTomb = initTomb();
    // init game rooms done

    // all global pointers now valid for use as Room map pointers
    initRoomMap();

    // #TODO put Player in starting Room of your choice
    // set utility pointer used throughout app main()
    Room* pRoom = g_pTower;

    // all-purpose string and message buffer
    std::string str;
    std::string playerName;

    // #TODO your game name goes here
    std::cout << "\nCS 281 Fall 2020 Game Project\n";
//    std::cout << "What's your name? ";
//    std::cin >> playerName;
    playerName = "~Wizard of Iluvitar~";

    // display app version
    messageQueue.push_back("Welcome " + playerName + "!\n");

    // create Player, award Room points,
    // and queue messages for display
    Player* pPlayer = new Player(playerName, PLAYER_LIVES);
    visitRoom(pPlayer, pRoom, messageQueue);

    // display things Player sees in this Room
    getInventory(pRoom, messageQueue);

    // display queued messages and clear queue
    displayMessageQueue(messageQueue);

    // one-character command from user cin >> userCmd
    char userCmd;
    int direction = ROOM_DEAD_END;

    // temp Room pointer for Player "movement"
    Room* pNextRoom = nullptr;

// main app loop: display game menu, handle user command
    do
    {
        userCmd = menuOption();

        // handle move commands first
                // translate char command to int direction constant
        direction = mapMoveCommand(userCmd);
        if (direction != ROOM_DEAD_END)
                pRoom = movePlayer(pPlayer, pRoom, direction, messageQueue);
        // L)ook command
        else if (userCmd == 'l')
            lookAllDirections(pRoom, messageQueue);
        // G)et treasure command
        else if (userCmd == 'g')
            grabTreasure(pPlayer, pRoom, messageQueue);
        // dR)op treasure command
        else if (userCmd == 'r')
            dropTreasure(pPlayer, pRoom, messageQueue);
        // T)ake weapon command
        else if (userCmd == 't')
            grabWeapon(pPlayer, pRoom, messageQueue);
        // deF)end command forces q)uit if Player out of lives
        else if (userCmd == 'f')
            userCmd = defendSelf(pPlayer, pRoom, messageQueue);
        // drO)p weapon command
        else if (userCmd == 'o')
            dropWeapon(pPlayer, pRoom, messageQueue);

        // teleP)ort magic spell command
        else if (userCmd == 'p')
        {
            pRoom = movePlayer(pPlayer, teleport(), direction, messageQueue, true);
        }

        // inC)inerate magic spell command
        else if (userCmd == 'c')
            userCmd = incinerate(pPlayer, pRoom, messageQueue);

        // I)nfo command
        else if (userCmd == 'i')
            getAllInfo(pPlayer, pRoom, messageQueue);
        // Q)uit command 
        else if (userCmd == 'q')
            messageQueue.push_back("Leaving so soon?");
        // handle bad input
        else
            messageQueue.push_back("\aSorry, I don't know that command.");

        displayMessageQueue(messageQueue);

    } while (userCmd != 'q');
    // end main input loop

    // status display and farewell to Player
    getInfo(pPlayer, pRoom, messageQueue);
    messageQueue.push_back("\nGoodbye " + playerName + "!\n");
    displayMessageQueue(messageQueue);

    system("pause");

    return 0;
}

/******************************************************************************
* displayMessageQueue()
*
* display queued messages and clear queue
*
*******************************************************************************
*/
void displayMessageQueue(std::vector<std::string>& msgQ)
{
    std::cout << std::endl;

    // add a newline after each queued message 
    for (std::string msg : msgQ)
        std::cout << msg << "\n";

    // reset queue for next iteration
    msgQ.clear();
 }

/******************************************************************************
* mapMoveCommand()
*
* assumes parameter is lower case
* 
* if passed command char is a move command,
* return the direction constant
* 
* otherwise return ROOM_DEAD_END
* 
* #TODO add custom direction mappings here
*******************************************************************************
*/
int mapMoveCommand(char cmd)
{
    if (cmd == 'n')         // n)orth
        return ROOM_NORTH;   
    if (cmd == 's')         // s)outh
        return ROOM_SOUTH;
    if (cmd == 'e')         // e)ast
        return ROOM_EAST;
    if (cmd == 'w')         // w)est
        return ROOM_WEST;
    if (cmd == 'u')         // u)p
        return ROOM_UP;
    if (cmd == 'd')         // d)own
        return ROOM_DOWN;

    // this is not a move command!
    return ROOM_DEAD_END;
}

/******************************************************************************
* 
* teleport()
* 
*******************************************************************************
*/
Room* teleport()
{
    //initRoomTeleport()

    int num;
    num = rand() % 100 + 1;

    if (num > 80)
    {
        return g_pTower;
    }
    if (num > 60 && num < 80)
    {
        return g_pKeep;
    }
    if (num > 40 && num < 60)
    {
        return g_pVault;
    }
    if (num > 20 && num < 40 )
    {
        return g_pCrypt;
    }
    else
    {
        return g_pTomb;
    }
}

/******************************************************************************
* char menuOption()
*
* display menu and prompt
* 
* return lower case user command
*
*******************************************************************************
*/
char menuOption()
{
    char cmd;

    // display game menu
    std::cout << std::endl;
    std::cout << "N)orth, S)outh, E)ast, W)est, U)p, D)own, L)ook,\n";
    std::cout << "G)et treasure, dR)op treasure,\n";
    std::cout << "T)ake weapon, deF)end, drO)p weapon,\n";
    std::cout << "teleP)ort, inC)inerate,\n";
    std::cout << "I)nfo, Q)uit ? ";

    // get user command
    std::cin >> cmd;
    
    // lower case simplifies command handling
    cmd = tolower(cmd);

    return cmd;
}

