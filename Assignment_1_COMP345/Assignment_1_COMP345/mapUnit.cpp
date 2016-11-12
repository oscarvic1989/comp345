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
<<<<<<< HEAD
    this->image = IMG_Load("/Users/oscar/Documents/xcode project/COMP345_Project/image/ground.jpg");
    this->dstrect={w,l,100,100};
=======
    //Nelson Edit:
    //changed file path
    this->image = IMG_Load("resources/ground.jpg");
    this->dstrect={w,l,defaultTileSize,defaultTileSize};
>>>>>>> map-with-basic-gui
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
<<<<<<< HEAD
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

void mapUnit::setOccupied(bool flag){
    this->occupied=flag;
}

bool mapUnit::getOccupied(){
=======
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
//Nelson Edit:
//added below method
void mapUnit::setOccupied(bool val){
    this->occupied = val;
}

//Nelson Edit:
//renamed getOccupied() to isOccupied();
bool mapUnit::isOccupied(){
>>>>>>> map-with-basic-gui
    return this->occupied;
}

void mapUnit::setImage(char a){
    this->image = IMG_Load(&a);
}
