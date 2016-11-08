#include "Equipment.h"

Equipment::Equipment()
{
}

Equipment::Equipment(const ItemType &_itemType) :
    mItemType(_itemType)
{
    mItemType = Equipment::ItemType;
   
}

void Equipment::setEquipped(bool equip)
{
    _isEquipped = equip;
}

bool Equipment::isEquipped()
{
    return _isEquipped;
}

Equipment::ItemType Equipment::itemType()
{
    return mItemType;
}