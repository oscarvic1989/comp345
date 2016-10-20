//
//  map.hpp
//  COMP345_Project
//
//  Created by oscar on 2016-10-12.
//  Copyright © 2016 oscar. All rights reserved.
//

#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include <Vector>
#include "mapUnit.hpp"



class gameMap{
public:
    std::vector<mapUnit> mapStack;
    gameMap();
    gameMap(int width,int length,SDL_Renderer *renderer);
private:
    int nH;
    int nV;
    int totalgrid;
    void setOrder();
};


#endif /* map_hpp */

