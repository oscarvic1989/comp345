//! @file
//! @brief Implementation file for the Item class
//!
#include "Enhancement.h"

// default constructor

//! default constructor
Enhancement::Enhancement()
{
    etype = E_NONE;
    bonus = 0;
}

//! constructor that receives a type of item as a string and a bonus value as an int
//! @param type_name : type of the item
//! @param bonus_value : bonus given by the item [1..5]
Enhancement::Enhancement(eType type_name, int bonus_value)
{
    etype = type_name;
    bonus = bonus_value;
}

//! method to get the type of the item
//! @return : type of the item
eType Enhancement::getType()
{
    return etype;
}

//! method to get the bonus of the type
//! @return : bonus given by the item
int Enhancement::getBonus()
{
    return bonus;
}

void Enhancement::setType(eType bonus_type)
{
    etype = bonus_type;
}

void Enhancement::setBonus(int bonus_val)
{
    bonus = bonus_val;
}
