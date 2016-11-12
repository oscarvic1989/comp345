#pragma once
#include <QtCore/QtCore>
#include <QtCore/QList>
#include "PlayerCharacter.h"
using namespace std;

class Fighter : public PlayerCharacter
{
public:
    Fighter();
    virtual ~Fighter(); //deconstructor
    
    virtual void stats(int,int,int,int,int,int);
    virtual void levelUp();
    void init();
    int attackBonus(int attacks);

    
protected:
    string name;
    int level;
    int hitDie;
    QList<int> mattackBonus;
};