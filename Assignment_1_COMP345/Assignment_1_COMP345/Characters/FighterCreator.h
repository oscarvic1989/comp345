

#ifndef FIGHTERCREATOR_H
#define FIGHTERCREATOR_H

#pragma once

#include "Fighter.h"


class FighterCreator{
public:
    
    //setter
    void setBuilder(Fighter*);

    Fighter* getFighter(string, int);
};


#endif /* FIGHTERCREATOR_H */

