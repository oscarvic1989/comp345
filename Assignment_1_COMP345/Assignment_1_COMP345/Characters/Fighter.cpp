#include "Fighter.h"
#include <Qlist>

Fighter::Fighter(){}
Fighter::~Fighter(){}

void Fighter::init(){
   level=1;
   hitDie=10;
   mattackBonus<<1;
}

void Fighter::levelUp(){
    ++level;
     mattackBonus[0] = mattackBonus[0] + 1;
     
    if (level == 6 || level == 11 || level == 16){
        mattackBonus = 1;
    }else if (level > 6 || level < 11){
        mattackBonus[1] = mattackBonus[1] + 1;
    }else if (level > 11 || level <16){
        mattackBonus[2] = mattackBonus[2] + 1;
    }else if (level > 16 || level < 21){
        mattackBonus[3] = mattackBonus[3] + 1;
    }
}

int Fighter::attackBonus(int attacks){
    if(attacks<=mattackBonus.size() && attacks > 0){
        mattackBonus.at(attacks -1);
    }
    return -1;
}

void Fighter::stats(int str, int dex, int cons, int intel, int wis, int chari)
{
    this -> str += str;
    this -> dex += dex;
    this -> cons += cons;
    this -> intel += intel;
    this -> wis += wis;
    this -> chari += chari;
 
    notify(*this);
}