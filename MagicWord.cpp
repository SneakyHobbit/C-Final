/******************************************************************************
* MagicWord.cpp
* CS 281-0798, Fall 2020
*
* MagicWord class definition
*******************************************************************************
*/
#include <string>

#include "MagicWord.h"

//***********************************************************
// MagicWord(string mName)
//
// overload constructor
//
// mName is a call by value string parameter
// to allow passing string literals
//***********************************************************
MagicWord::MagicWord(std::string wName)
{
    m_id = static_cast<int>(WEAPON_CARRYIT);
    m_name = wName;
}
//***********************************************************
// Weapon()
//
// constructor
//***********************************************************
MagicWord::MagicWord() : MagicWord("Abracadabra!!")
{ }


