#ifndef ItemBuilder_h
#define ItemBuilder_h


#include "ItemContainer.h"
#include "Item.h"
#include "Enhancement.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>



//return name of item type 
string get_iTname(int iit);

//return name of enhancement
string get_eTname(int eet);

//return name of container type
string get_cTname(int cct);

//return container type
cType get_ctype(int c_type);

//return item type
iType get_itype(int itype);

//return enhancement type
eType get_etype(int etype);

//enter bonus value
int enterBonus();

//create a vector of enhancements
vector<Enhancement> createEnhancements(int i_opt);

//save an item
void saveI(string fileName, Item item);

//create an item
void createItem1();

//create a vector of items for itemcontainer
vector<Item> createItem2();

//create worn items
vector<Item> createItem3();

//save an Item Container
void saveIC(string fileName, ItemContainer ic);

//create an Item Container
void createItemContainer();

//load an Item
void loadItem(string f_name, Item& item);

//Load an Item Container
void loadItemContainer(string f_name, ItemContainer& ic);

//edit an item
void editItem(string f_name, Item &m_item);

//edit an item container
void editItemContainer(string f_name, ItemContainer &m_ic);

//Item editor main menu
int ItemMenu();





#endif