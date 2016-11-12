//! @file
//! @brief Header file for the ItemContainer class
//!

#ifndef ItemContainer_h
#define ItemContainer_h

#include <string>
#include<vector>
#include "Item.h"
using namespace std;
enum cType
{
    C_NONE = 0,
    BACKPACK = 1,
    WORN_ITEMS = 2,
    CHEST = 3
};

//! Class that implements an item container
class ItemContainer
{
public:
    // Default constructor
    ItemContainer();
    // Constructor
    ItemContainer(cType c_type, vector<Item> items);
    // method to get the items of the container
    vector<Item> getItems();
    // method to add an item to the item container
    void addItem(Item anitem);
    // method to remove the last item in the item container
    void removeItem();
    // method to get an item from the item container
    Item getItem(int i);
    
    cType getType();
    void setType(cType c_type);
    void setItems(vector<Item> items);
    void displayItems();
    Item Equip(Item a);
    void remove(Item a);
private:
    cType ctype;
    vector<Item> Items;
};

#endif

