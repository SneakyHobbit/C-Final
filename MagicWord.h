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

// base class declaration
#include "CarryIt.h"

//----------------------------------------------------------
// Weapon class derived from base class for carried items
//----------------------------------------------------------
class MagicWord : public CarryIt
{
private:
    int m_usesRemaining;

public:
    MagicWord();
    MagicWord(std::string mwName);
    // Weapon persists for app lifetime
    // so destructor not needed
    //~Weapon();

    bool setUsesRemaining(int uses);
    int getUsesRemaining() const;
    int addUsesRemaining(int uses);
};

#endif

