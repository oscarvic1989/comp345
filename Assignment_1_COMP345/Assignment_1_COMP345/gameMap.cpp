//
//  map.cpp
//  COMP345_Project
//
//  Created by oscar on 2016-10-12.
//  Copyright © 2016 oscar. All rights reserved.
//

#include "gameMap.hpp"
#include <iostream>

gameMap::gameMap(){
}
//mapuint :20*20
gameMap::gameMap(int width, int length,SDL_Renderer *renderer){
    int index=1;
    for(int i=0;i*100<length-100;i++){
        for(int j=0;j*100<width;j++){
            mapUnit temp=*new mapUnit(j*100,i*100,renderer,index);
            this->mapStack.push_back(temp);
            this->nV=j;
            index++;
        }
        this->nH=i;
    }
    this->nH++;
    this->nV++;
    this->totalgrid=this->nH*this->nV;
    setOrder();
}
void gameMap::setOrder(){
    for(int i=0;i<this->nH;i++){
        for(int j=i*this->nV;j<i*this->nV+this->nV-1;j++){
            mapStack[j].setRight(&mapStack[j+1]);
        }
    }
    for(int i=this->nH-1;i>=0;i--){
        for(int j=(this->nV-1);j>0;j--){
            mapStack[i*this->nV+j].setLeft(&mapStack[i*this->nV+j-1]);
        }
    }
    for(int i=0;i<this->nV;i++){
        for(int j=0;j<this->nH-1;j++){
            mapStack[j*(this->nV-1)+i].setDown(&mapStack[j*(this->nV-1)+i+8]);
        }
    }
    for(int i=this->nV-1;i>=0;i--){
        for(int j=this->nH-1;j>0;j--){
            mapStack[j*(this->nV)+i].setUp(&mapStack[j*(this->nV)+i-8]);
        }
    }
}

bool gameMap::mapValidateInit(){
    std::vector<mapUnit> dsfqueue;
    std::vector<mapUnit> alreadyin;
    for(int i=0;this->mapStack.size();i++){
        if(mapStack[i].STATE==MAP_START)
        {
            if(mapStack[i].getDown()!=NULL){
                alreadyin.push_back(*mapStack[i].getDown());
                dsfqueue.push_back(*mapStack[i].getDown());
            }
            if(mapStack[i].getUp()!=NULL){
                alreadyin.push_back(*mapStack[i].getUp());
                dsfqueue.push_back(*mapStack[i].getUp());
            }if(mapStack[i].getLeft()!=NULL){
                alreadyin.push_back(*mapStack[i].getLeft());
                dsfqueue.push_back(*mapStack[i].getLeft());
            }if(mapStack[i].getRight()!=NULL){
                alreadyin.push_back(*mapStack[i].getRight());
                dsfqueue.push_back(*mapStack[i].getRight());
            }
            break;
        }
    }
    return mapValidate(dsfqueue,alreadyin);
}

bool gameMap::mapValidate(std::vector<mapUnit> a,std::vector<mapUnit> b){
    bool flag;
    mapUnit temp=a.back();
    a.pop_back();
    std::cout<<temp.getIndex()<<"\n";
    if(temp.getOccupied()==true){
        flag=mapValidate(a,b) or flag;
    }
    if(temp.getOccupied()==false&&temp.STATE!=Map_END){
        if(temp.getRight()!=NULL){
            if(!stackContainElement(b,*temp.getRight()))
            {
                a.push_back(*temp.getRight());
                b.push_back(*temp.getRight());
            }
        }
        if(temp.getDown()!=NULL){
            if(!stackContainElement(b,*temp.getDown()))
            {
                a.push_back(*temp.getDown());
                b.push_back(*temp.getDown());
            }
        }
        if(temp.getUp()!=NULL){
            if(!stackContainElement(b,*temp.getUp()))
            {
               a.push_back(*temp.getUp());
                b.push_back(*temp.getUp());
            }
        }
        if(temp.getLeft()!=NULL){
            if(!stackContainElement(b,*temp.getLeft()))
            {
                a.push_back(*temp.getLeft());
                b.push_back(*temp.getLeft());
            }
        }
        flag=mapValidate(a,b) or flag;
    }
    else if(temp.getOccupied()==false&&temp.STATE==Map_END)
        flag=true;
    return flag;
};
bool gameMap::stackContainElement(std::vector<mapUnit> a, mapUnit b){
    bool flag=false;
    for(int i=0;i<a.size();i++){
        if(a[i].getIndex()==b.getIndex())
        {
            flag= true;
            break;
        }
    }
    return flag;
};
