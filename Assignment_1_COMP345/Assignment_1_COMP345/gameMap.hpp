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
<<<<<<< HEAD
private:
    int nH;
    int nV;
=======
    int getNumberVerticalElements();
    int getNumberHorizontalElements();
    bool checkifOccpuied(SDL_Rect dstrect);
    int setOccpuied(SDL_Rect dstrect);
    int setOccupied(SDL_Rect, bool state);
    void setStart(int a);
    void setEnd(int a);
    int startindex;
    int endindex;
private:
    //Nelson Edit:
    //rename nH, nV to be correct and English
    
    int numberVerticalElements;
    int numberHorizontalElements;
>>>>>>> map-with-basic-gui
    void setOrder();
    mapUnit outBoundry;
};


#endif /* map_hpp */

