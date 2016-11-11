#include <QList>
#include "Inventory.h"
#include "Equipment.h"

Inventory::Inventory(){
    _backPack.clear();
}

void Inventory::equipItem(const char &a){
    Item items;
    cout << "Character equipped with items" << endl;
    if(a=='a'){
        items.armor=equipItem;
        cout << "ARMOR" << endl;
    }else if (a=='b'){
        items.belt=equipItem;
        cout << "BELT" << endl;
    }else if (a=='c'){
        items.boots=equipItem;
        cout << "BOOTS" << endl;
    }else if (a=='h'){
        items.helmet=equipItem;
        cout << "HELMET" << endl;
    }else if (a=='r'){
        items.ring=equipItem;
        cout << "RING" << endl;
    }else if (a=='s'){
        items.shield=equipItem;
        cout << "SHIELD" << endl;
    }else if (a=='w'){
        items.weapon=equipItem;
        cout << "WEAPON" << endl;
    }
    _backPack[a]->setEquipped(true);
}

void Inventory::unequipItem(const char &a)
{
    _backPack[a]->setEquipped(false);
}

QList<Item*> Inventory::backpack()
{
    return _backPack;
}