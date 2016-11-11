#ifndef INVENTORY_H
#define INVENTORY_H
#include "PlayerCharacter.h"
#include <QtCore/QtCore>
#include <QtCore/QList>


class Inventory
{
public:
    Inventory();
    void equipItem(const char &a);
    void unequipItem(const char &a);
    QList<ItemType*> backpack();
    void setEquipment;
    
    
    
    char armor='a';
    char belt='b';
    char boots='c';
    char helmet='h';
    char ring='r';
    char shield='s';
    char weapon='w';

    void setArmor(char);
    void setBelt(char);
    void setBoots(char);
    void setHelmet(char);
    void setRing(char);
    void setShield(char);
    void setWeapon(char);
   
    
    char getArmor();
    char getBelt();
    char getBoots();
    char getHelmet();
    char getRing();
    char getShield();
    char getWeapon();
    
protected:
    QList<ItemType*> _backPack;
};



#endif // INVENTORY_H


