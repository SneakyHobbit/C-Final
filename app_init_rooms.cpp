/******************************************************************************
* app_init_rooms.cpp
* CS 281 - 0798, Fall 2020
*
* Room initialization functions
*   - set Room entry text, exit text, direction text
*   - install Treasures in Room Treasure vector or in Room mixed vector
*   - install Weapons in Room Weapon vector or in Room mixed vector
* #TODO
*   - install magic words in Room MagicWord vector
*******************************************************************************
*/
#include "app.h"

/******************************************************************************
* Room* initTower()
*******************************************************************************
*/
Room* initTower()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "the Tower";
    pRoom->setName(str);

    str = "A spiral staircase decending below..";
    pRoom->setEntryText(str);

    str = "You are leaving the Tower.";
    pRoom->setExitText(str);

    str = "Tower walls to the north.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Tower walls to the south.";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Tower walls to the east.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Tower walls to the west.";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "A barred window is above.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "A dungeon keep is below.";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Potion of the Halfblood Prince.";
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Scepter of the Ancient Amethyst.";
    pWeapon->setName(str);
    pWeapon->setPoints(200);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    // create and initialize Dragon instance
    Bogie* pBogie = new Bogie();
    pBogie->setName("Hungarian Horntail.");
    pBogie->setText("Raaawwwwrrr!!");
    pBogie->setPoints(250);

    // install Dragon pointer in Room's Dragon vector
    pRoom->addBogie(pBogie);

    // create and initialize MagicWord instance
    MagicWord* pMagicWord = new MagicWord();
    pMagicWord->setName("Gandalf’s Firespell.");
    pMagicWord->setText("Naur an edraith ammen!");
    pMagicWord->setPoints(200);

    // install MagicWord pointer in Room's MagicWord vector
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}

/******************************************************************************
* Room* initKeep()
*******************************************************************************
*/
Room* initKeep()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(150);

    std::string str = "the Dungeon Keep";
    pRoom->setName(str);

    str = "A large dungeon vaguely lit from the light above.";
    pRoom->setEntryText(str);

    str = "You are leaving the Dungeon Keep.";
    pRoom->setExitText(str);

    str = "Stone walls to the north.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Stone walls to the south.";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Stone walls to the east.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Stone walls to the west.";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "An ascending staircase leads above.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "A trapdoor leading to a Vault.";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Slippers of Profound Silence.";
    pTreasure->setName(str);
    pTreasure->setPoints(150);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Ancient Elvish Spellbook.";
    pWeapon->setName(str);
    pWeapon->setPoints(200);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    // create and initialize Dragon instance
    Bogie* pBogie = new Bogie();
    pBogie->setName(str = "Peruvian Vipertooth.");
    pBogie->setText("Hsssssss!!");
    pBogie->setPoints(250);

    // install Dragon pointer in Room's Dragon vector
    pRoom->addBogie(pBogie);

    // create and initialize MagicWord instance
    MagicWord* pMagicWord = new MagicWord();
    pMagicWord->setName("Arwen’s Incantation.");
    pMagicWord->setText("Rimmo Nîn o Chithaeglir!");
    pMagicWord->setPoints(200);

    // install MagicWord pointer in Room's MagicWord vector
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}

/******************************************************************************
* Room* initVault()
*******************************************************************************
*/
Room* initVault()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(200);

    std::string str = "the Vault";
    pRoom->setName(str);

    str = "An expansive vault full of antique treasures & gold glitters about.";
    pRoom->setEntryText(str);

    str = "You are leaving the Vault.";
    pRoom->setExitText(str);

    str = "Vault walls to the north.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Vault walls to the south";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "A broken stone door to the Tomb lies to the east.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "A archway reading the Crypt lies to the west.";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "A ladder ascends to the Keep's hidden trap door.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "The Vault floor is strewn with ancient gold coins.";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Cloak of Adept Invisiblity";
    pTreasure->setName(str);
    pTreasure->setPoints(200);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Sword of the Secret Flame.";
    pWeapon->setName(str);
    pWeapon->setPoints(200);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    // create and initialize Dragon instance
    Bogie* pBogie = new Bogie();
    pBogie->setName("Hungarian Horntail.");
    pBogie->setText("Raaawwwwrrr!!");
    pBogie->setPoints(250);

    // install Dragon pointer in Room's Dragon vector
    pRoom->addBogie(pBogie);

    // create and initialize MagicWord instance
    MagicWord* pMagicWord = new MagicWord();
    pMagicWord->setName("Gandalf’s Firespell.");
    pMagicWord->setText("Naur an edraith ammen!");
    pMagicWord->setPoints(200);

    // install MagicWord pointer in Room's MagicWord vector
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}

/******************************************************************************
* Room* initCrypt()
*******************************************************************************
*/
Room* initCrypt()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(300);

    std::string str = "the Crypt";
    pRoom->setName(str);

    str = "An old crypt full of partially mummified dead bodies.";
    pRoom->setEntryText(str);

    str = "You are leaving the crypt.";
    pRoom->setExitText(str);

    str = "Countless stone caskets.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Countless stone caskets.";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "The Vault from whence you came.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Countless stone caskets.";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "Shhh.. Vampire bats are sleeping.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "The floor is littered with shattered bones.";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Enchanted Emerald Signet";
    pTreasure->setName(str);
    pTreasure->setPoints(250);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Dragon instance
    Bogie* pBogie = new Bogie();
    pBogie->setName(str = "Peruvian Vipertooth.");
    pBogie->setText("Hsssssss!!");
    pBogie->setPoints(300);

    // install Dragon pointer in Room's Dragon vector
    pRoom->addBogie(pBogie);

    // create and initialize MagicWord instance
    MagicWord* pMagicWord = new MagicWord();
    pMagicWord->setName("Arwen’s Incantation.");
    pMagicWord->setText("Rimmo Nîn o Chithaeglir!");
    pMagicWord->setPoints(200);

    // install MagicWord pointer in Room's MagicWord vector
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}

/******************************************************************************
* Room* initTomb()
*******************************************************************************
*/
Room* initTomb()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(300);

    std::string str = "the Tomb";
    pRoom->setName(str);

    str = "A dark tomb full of shattered stone caskets.";
    pRoom->setEntryText(str);

    str = "You are leaving the tomb.";
    pRoom->setExitText(str);

    str = "Countless stone caskets to the north.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Countless stone caskets to the south.";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Countless stone caskets to the east.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "The Vault from whence you came.";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "Stalagtites are above you dripping with water.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "The floor is littered with shattered bones.";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Crown of Druidic Mistletoe.";
    pTreasure->setName(str);
    pTreasure->setPoints(250);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Dragon instance
    Bogie* pBogie = new Bogie();
    pBogie->setName("Hungarian Horntail.");
    pBogie->setText("Raaawwwwrrr!!");
    pBogie->setPoints(300);

    // install Dragon pointer in Room's Dragon vector
    pRoom->addBogie(pBogie);

    // create and initialize MagicWord instance
    MagicWord* pMagicWord = new MagicWord();
    pMagicWord->setName("Gandalf’s Firespell.");
    pMagicWord->setText("Naur an edraith ammen!");
    pMagicWord->setPoints(200);

    // install MagicWord pointer in Room's MagicWord vector
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}