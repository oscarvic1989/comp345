#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QPair>
#include <QList>
#include "PlayerCharacter.h"

class Equipment {
public:
    enum ItemType
    {
        armor = 0,
        belt,
        boots,
        helmet,
        ring,
        shield,
        weapon,
    };

    Equipment();
    Equipment(const ItemType &_itemType);

    ItemType itemType();
   
    void setEquipped(bool equip);
    bool isEquipped();
    
protected:
    ItemType mItemType;
    bool _isEquipped;
    QList<ItemType*> _backPack;
};


#endif /* EQUIPMENT_H */

