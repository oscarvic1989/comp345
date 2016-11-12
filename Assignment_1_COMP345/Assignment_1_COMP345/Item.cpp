//! @file
//! @brief Implementation file for the Item class
//!

#include <iostream>
#include "Item.hpp"
using namespace std;

//! default constructor
Item::Item()
{
    iName = "";
    itype = I_NONE;
    enhances = vector<Enhancement>();
}

//! constructor that receives an item type as a string and a vector containing the enhancements that this item gives
//! @param type_name : string representing the type of item
//! @param influences : vector containing all the characteristics influenced by the item
Item::Item(string item_name, iType i_type, vector<Enhancement> influences)
{
    iName = item_name;
    itype = i_type;
    enhances = influences;
}

//! method to get the type of the item
//! @return : type of the item
iType Item::getType()
{
    return itype;
}

//! method to get the influences of the item
//! @return : vector containg the list of stats that the item enhances
vector<Enhancement> Item::getEnhances()
{
    return enhances;
}

string Item::getName()
{
    return iName;
}

void Item::setName(string item_name)
{
    iName = item_name;
}

void Item::setType(iType item_type)
{
    itype = item_type;
}

void Item::setEnhances(vector<Enhancement> influences)
{
    enhances = influences;
}

void Item::setValueTozero(){
    for(int i=0;i<this->enhances.size();i++){
        this->enhances[i].setBonus(0);
    }
}
