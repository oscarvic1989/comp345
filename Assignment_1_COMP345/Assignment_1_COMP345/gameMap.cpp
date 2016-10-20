//
//  map.cpp
//  COMP345_Project
//
//  Created by oscar on 2016-10-12.
//  Copyright © 2016 oscar. All rights reserved.
//

#include "gameMap.hpp"


gameMap::gameMap(){
    
}
//mapuint :20*20
gameMap::gameMap(int width, int length,SDL_Renderer *renderer){
    for(int i=0;i*100<length;i++){
        int index=1;
        for(int j=0;j*100<width;j++){
            mapUnit temp=*new mapUnit(j*100,i*100,renderer,index);
            this->mapStack.push_back(temp);
            this->nV=j;
        }
        index++;
        this->nH=i;
    }
    this->totalgrid=this->nH*this->nV;
}
void gameMap::setOrder(){
   
}
