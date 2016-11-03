//
//  character.hpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-11-02.
//  Copyright © 2016 oscar. All rights reserved.
//

#ifndef character_hpp
#define character_hpp
#include "game Item.hpp"
#include <stdio.h>

class character :public gameItem{
public:
    character();
    character(SDL_Renderer *renderer);
    int movecounter=0;
    int Directioncounter=2;
    int movestep=128;
    
};
#endif /* character_hpp */
