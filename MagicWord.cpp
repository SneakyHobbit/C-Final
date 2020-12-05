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
MagicWord::MagicWord()
{
    m_id = static_cast<int>(MAGICWORD_CARRYIT);
    m_name = "Exxplosion!!";
    m_power = rand() % MAX_POWER + MIN_POWER;
    m_roomInfo = 0;
    m_playerInfo = 0;
}

//***********************************************************
// getId() 
//***********************************************************
int MagicWord::getId() const
{
    return m_id;
}

//***********************************************************
// setName()
//***********************************************************
bool MagicWord::setName(const std::string& name)
{
    m_name = name;
    return true;
}

//***********************************************************
// getName()
//***********************************************************
bool MagicWord::getName(std::string& name) const
{
    name = m_name;
    return true;
}

//***********************************************************
// setPoints()
//***********************************************************
bool MagicWord::setPoints(int points)
{
    m_points = points;
    return true;
}

//***********************************************************
// getPoints()
//***********************************************************
int MagicWord::getPoints() const
{
    return m_points;
}

//***********************************************************
// addPoints()
//
// adds passed value to container's points
//***********************************************************
int MagicWord::addPoints(int points)
{
    m_points += points;
    return true;
}

//***********************************************************
// setText()
//***********************************************************
bool MagicWord::setText(const std::string& text)
{
    m_text = text;
    return true;
}

//***********************************************************
// getText()
//***********************************************************
bool MagicWord::getText(std::string& text) const
{
    text = m_text;
    return true;
}

//***********************************************************
// setPower()
//***********************************************************
bool MagicWord::setPower(int power)
{
    m_power = power;
    return true;
}

//***********************************************************
// getPower()
//***********************************************************
int MagicWord::getPower() const
{
    return m_power;
}

//***********************************************************
// addPower()
//
// returns updated power setting
//***********************************************************
int MagicWord::addPower(int morePower)
{
    m_power += morePower;
    return m_power;
}



