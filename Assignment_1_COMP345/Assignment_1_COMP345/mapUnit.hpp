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

class mapUnit{
public:
    mapUnit();
    mapUnit(int w,int l,SDL_Renderer *renderer,int number);
    void setSrcrect(int a,int b,int c,int d);
    void setDstrect(int a,int b,int c,int d);
    SDL_Rect getSrcrect();
    SDL_Rect getDstrect();
    SDL_Surface * image;
    SDL_Texture * texture;
    SDL_Rect srcrect={0,0,128,128} ;
    SDL_Rect dstrect ;
    int getIndex();
    void setUp(mapUnit a);
    void setDown(mapUnit a);
    void setLeft(mapUnit a);
    void setRight(mapUnit a);
private:
    bool occupied;
    mapUnit *up;
    mapUnit *down;
    mapUnit *left;
    mapUnit *right;
    int index;
};

#endif /* mapunit_hpp */
