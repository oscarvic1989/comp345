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
#include <Queue>

/**
 * Game rules:
 *   1)Enter the width of the screen
 *   2)Enter the height of the screen
 *   3)Enter the start point
 *   4)Enter the end point
 * Design:
 *   Thie application promote user to generate a map related to D&D game;
 * Libaray:
 *
 */
class gameMap{
public:
    std::vector<mapUnit> mapStack;
    gameMap();
    gameMap(int width,int length,SDL_Renderer *renderer);
    bool MAPvalidator();
    bool mapValidateInit();
    bool mapValidate(std::vector<mapUnit> a,std::vector<mapUnit> b);
    bool stackContainElement(std::vector<mapUnit> a, mapUnit b);
    int totalgrid;
private:
    int nH;
    int nV;
    void setOrder();
    mapUnit outBoundry;
};


#endif /* map_hpp */

