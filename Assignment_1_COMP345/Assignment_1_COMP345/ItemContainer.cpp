//! @file
//! @brief IMplementation file for the ItemContainer class
//!

#include "ItemContainer.hpp"

//! default constructor
ItemContainer::ItemContainer()
{
    ctype = C_NONE;
    Items = vector<Item>();
}

//! constructor that takes a vector of items as input to create an ItemContainer
//! @param containeritems: vector of items to put in the new container
ItemContainer::ItemContainer(cType c_type, vector<Item> containeritems)
{
    ctype = c_type;
    Items = containeritems;
}

//! method to get the items of the container
//! @return : return the vector of items contained in the ItemContainer
vector<Item> ItemContainer::getItems()
{
    return Items;
}

//! method to add an item to the item container
//! @param anitem : new item to put in the ItemContainer
void ItemContainer::addItem(Item anitem)
{
    Items.push_back(anitem);
}

//! method to remove the last item in the item container
void ItemContainer::removeItem()
{
    Items.pop_back();
}

//! method to return the item of a certain type contained in the ItemContainer
//! assumption: the container can only contain one element of each type
//! @param itemType : type of item to extract from the container
//! @return : item of the specified kind provided in input

Item ItemContainer::getItem(int i)
{
    return Items[i];
}

cType ItemContainer::getType()
{
    return ctype;
}

void ItemContainer::setType(cType c_type)
{
    ctype = c_type;
}

void ItemContainer::setItems(vector<Item> vitems)
{
    Items = vitems;
}

void ItemContainer::displayItems(){
    
}

Item ItemContainer::Equip(Item a){
    Item temp=Item();
    switch (a.getType()) {
        case HELMET:
            temp=this->Items[0];
            this->Items[0].setName(a.getName());
            this->Items[0].setEnhances(a.getEnhances());
            return temp;
            break;
        case ARMOR:
            temp=this->Items[1];
            this->Items[1].setName(a.getName());
            this->Items[1].setEnhances(a.getEnhances());
            return temp;
            break;
        case SHIELD:
            temp=this->Items[2];
            this->Items[2].setName(a.getName());
            this->Items[2].setEnhances(a.getEnhances());
            return temp;
            break;
        case RING:
            temp=this->Items[3];
            this->Items[3].setName(a.getName());
            this->Items[3].setEnhances(a.getEnhances());
            return temp;
            break;
        case BELT:
            temp=this->Items[4];
            this->Items[4].setName(a.getName());
            this->Items[4].setEnhances(a.getEnhances());
            return temp;
            break;
        case BOOTS:
            temp=this->Items[5];
            this->Items[5].setName(a.getName());
            this->Items[5].setEnhances(a.getEnhances());
            return temp;
            break;
        case WEAPON:
            temp=this->Items[6];
            this->Items[6].setName(a.getName());
            this->Items[6].setEnhances(a.getEnhances());
            return temp;
            break;
        default:
            return temp;
            break;
    }
}

void ItemContainer::remove(Item a){
    
}
