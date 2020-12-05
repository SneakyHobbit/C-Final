/******************************************************************************
* MagicWord.h
* CS 281-0798, Fall 2020
*
* MagicWord class declaration
*******************************************************************************
*/
#ifndef MAGICWORD_H
#define MAGICWORD_H

#include <string>

#define MAGICWORD_CARRYIT   'm'
// default MagicWord element characteristics
#define MAX_POWER    10
#define MIN_POWER    10

class MagicWord 
{
private:
    int m_id;
    int m_power;
    int m_points;
    int m_roomInfo;
    int m_playerInfo;
    std::string m_text;
    std::string m_name;
    int m_usesRemaining;  

public:
    MagicWord();
    int getId() const;
    bool setName(const std::string& name);
    bool getName(std::string& name) const;
    int addPoints(int points);
    bool setPoints(int points);
    int getPoints() const;
    bool setText(const std::string& text);
    bool getText(std::string& text) const;
    bool setPower(int power);
    int getPower() const;
    int addPower(int morePower);

};

#endif

