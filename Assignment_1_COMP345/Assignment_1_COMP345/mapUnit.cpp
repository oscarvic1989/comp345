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
    this->image = IMG_Load("/Users/oscar/Documents/xcode project/Assignment_1_COMP345/ground.jpg");
    this->dstrect={w,l,100,100};
    this->srcrect={0,0,128,128};
    this->texture=SDL_CreateTextureFromSurface(renderer, this->image);
    this->index=number;
};

int mapUnit::getIndex(){
    return this->index;
}

void mapUnit::setUp(mapUnit *a){
    this->up=a;
};

void mapUnit::setDown(mapUnit *a){
    this->down=a;
};

void mapUnit::setLeft(mapUnit *a){
    this->left=a;
};

void mapUnit::setRight(mapUnit *a){
    this->right=a;
};

mapUnit * mapUnit::getRight(){
    return this->right;
};

mapUnit * mapUnit::getLeft(){
    return this->left;
};

mapUnit * mapUnit::getUp(){
    return this->up;
};

mapUnit * mapUnit::getDown(){
    return this->down;
};

void mapUnit::setOccupied(){
    this->occupied=true;
}

bool mapUnit::getOccupied(){
    return this->occupied;
}

void mapUnit::setImage(char a){
    this->image = IMG_Load(&a);
}
