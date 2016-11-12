//! @file
//! @brief Header file for the Enhancement class
//!
#ifndef Enhancement_h
#define Enhancement_h

#include <string>
#include<vector>
using namespace std;

enum eType
{
    E_NONE = 0,
    STRENGTH = 1,
    DEXTERITY = 2,
    CONSTITUTION = 3,
    INTELLIGENCE = 4,
    WISDOM = 5,
    CHARISMA = 6,
    ARMOR_CLASS = 7,
    ATTACK_BONUS = 8,
    DAMAGE_BONUS = 9
};

//! class for the implementation of an enhancement, i.e. a stat influenced by an item, as well as the bonus it gives
class Enhancement
{
public:
    // Default constructor
    Enhancement();
    // Constructor
    Enhancement(eType type, int bonus);
    // method to get the type of the item
    eType getType();
    // method to get the bonus of the type
    int getBonus();
    
    void setType(eType bType);
    void setBonus(int eVal);
    
    
private:
    
    eType etype;
    int bonus;
};

#endif

