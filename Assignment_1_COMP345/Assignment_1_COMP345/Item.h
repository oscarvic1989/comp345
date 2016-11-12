//! @file 
//! @brief Header file for the Item class  
//!
#ifndef Item_h
#define Item_h

#include <string>
#include<vector>
#include "Enhancement.h"
using namespace std;

enum iType
{
	I_NONE = 0,
	HELMET = 1,
	ARMOR = 2,
	SHIELD = 3,
	RING = 4,
	BELT = 5,
	BOOTS = 6,
	WEAPON = 7
};

//! class for the implementation of items wearable by a character
class Item
{
public:
	// Default constructor
	Item();
	// Constructor
	Item(string iName, iType type, vector<Enhancement> enhances);
	// method to get the type of the item
	iType getType();
	// method to get the influences of the item
	vector<Enhancement> getEnhances();
	//get item's name
	string getName();

	void setName(string item_name);
	void setType(iType item_type);
	void setEnhances(vector<Enhancement> influences);

private:
	string iName;
	iType itype;
	vector<Enhancement> enhances;
};
#endif

