//
//  mapunit.hpp
//  COMP345_Project
//
//  Created by oscar on 2016-10-19.
//  Copyright © 2016 oscar. All rights reserved.
//

#ifndef mapunit_hpp
#define mapunit_hpp

#include <stdio.h>
#include <SDL2_image/SDL_image.h>
#include "game Item.hpp"

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
enum MapType {
    MAP_START,
    MAP_INSIDE,
    Map_END,
};

class mapUnit :public gameItem{
public:
    MapType STATE=MAP_INSIDE;
    mapUnit();
    mapUnit(int w,int l,SDL_Renderer *renderer,int number);
    int getIndex();
    void setUp(mapUnit *a);
    void setDown(mapUnit *a);
    void setLeft(mapUnit *a);
    void setRight(mapUnit *a);
    mapUnit * getUp();
    mapUnit * getDown();
    mapUnit * getLeft();
    mapUnit * getRight();
    void setOccupied(bool flag);
    bool getOccupied();
    int index;
    void setImage(char a);
    
private:
    bool occupied=false;
    mapUnit *up=nullptr;
    mapUnit *down=nullptr;
    mapUnit *left=nullptr;
    mapUnit *right=nullptr;
};

#endif /* mapunit_hpp */
