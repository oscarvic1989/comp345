//
//  mapunit.cpp
//  COMP345_Project
//
//  Created by oscar on 2016-10-19.
//  Copyright © 2016 oscar. All rights reserved.
//

#include "mapUnit.hpp"

mapUnit::mapUnit(){
    
};

mapUnit::mapUnit(int w,int l,SDL_Renderer *renderer,int number){
    this->image = IMG_Load("/Users/oscar/Documents/xcode project/COMP345_Project/image/ground.jpg");
    this->dstrect={w,l,100,100};
    this->texture=SDL_CreateTextureFromSurface(renderer, this->image);
    this->index=number;
};

int mapUnit::getIndex(){
    return this->index;
}
void mapUnit::setUp(mapUnit a){
    this->up=&a;
};
void mapUnit::setDown(mapUnit a){
    this->down=&a;
};
void mapUnit::setLeft(mapUnit a){
    this->left=&a;
};
void mapUnit::setRight(mapUnit a){
    this->right=&a;
};
