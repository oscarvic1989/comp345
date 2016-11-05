//
//  GameMap2.cpp
//  C++ Testing
//
//  Created by Nelson Frank on 2016-11-03.
//  Copyright © 2016 COMP 345. All rights reserved.
//
#include <iostream>
#include "GameMap2.hpp"
using std::vector;
//Methods for inner class BlockData
//
//Constructors
GameMap2::BlockData::BlockData(){
    mapType = MAP_INSIDE;
    groundType = GRASS;
    containedItem = nullptr;
}
GameMap2::BlockData::BlockData(MapType mType, GroundType gType, GameObject* cItem){
    mapType = mType;
    groundType = gType;
    containedItem = cItem;
}

//Destructor
GameMap2::BlockData::~BlockData(){
    delete containedItem;
    containedItem = nullptr;
}

//getters and setters
MapType GameMap2::BlockData::getMapType(){
    return mapType;
}
GroundType GameMap2::BlockData::getGroundType(){
    return groundType;
}
GameObject* GameMap2::BlockData::getContainedItem(){
    return containedItem;
}
void GameMap2::BlockData::setMapType(MapType mType) {
    mapType = mType;
}
void GameMap2::BlockData::setGroundType(GroundType gType) {
    groundType = gType;
}
void GameMap2::BlockData::setContainedItem(GameObject *cItem) {
    containedItem = cItem;
}

//determines if a block can be entered by a character
//may need to be updated if GroundType enum is updated
//may need to be updated if multiple forms of movement  are implemented. e.g.; flying, walking
bool GameMap2::BlockData::canMoveInto(){
    if(isOccupied() ||
       groundType == WALL ||
       groundType == WATER
       
        ){
        return false;
    }
    else{return true;}
}
//determines if block contains an item/character/etc
bool GameMap2::BlockData::isOccupied(){
    return (containedItem == nullptr)? false:true;
}

//Methods for GameMap
//
//constructors
GameMap2::GameMap2(){
    //Uses other constructor
    GameMap2(arrayDimensions.x,
             arrayDimensions.y,
             coordinate{0,0},
             coordinate{arrayDimensions.x-1,arrayDimensions.y-1},
             nullptr,
             nullptr);

}
GameMap2::GameMap2(int w, int h, coordinate startBlock, coordinate endBlock, GameMap2* pMap, GameMap2* nMap){
    //set size of map
    mapArray = new vector<vector<BlockData*>*>(w);
    //mapArray->resize(w);
    for(int c = 0; c < w; c++){
        mapArray->at(c) = new vector<BlockData*>(h);
        //mapArray->at(c)->resize(h);
    }
    //fill map with default blocks
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            mapArray->at(c)->at(r) = new BlockData();
        }
    }
    //set starting block
    mapArray->at(startBlock.x)->at(startBlock.y)->setMapType(MAP_START);
    startingBlock = startBlock;
    //set ending block
    mapArray->at(endBlock.x)->at(endBlock.y)->setMapType(MAP_END);
    endingBlock = endBlock;
    
    //set new array dimensions
    arrayDimensions={w,h};
    
    //sets connected maps
    this->previousMap = pMap;
    this->nextMap = nMap;
}
//destructor
GameMap2::~GameMap2(){
    for(int c = 0; c < arrayDimensions.x; c++){
        for(int r = 0; r < arrayDimensions.y; r++){
            delete mapArray->at(c)->at(r);
        }
    }
    for(int c = 0; c < arrayDimensions.x; c++){
        delete mapArray->at(c);
    }
    delete mapArray;
}

//getters and setters for start/end blocks
coordinate GameMap2::getStartingBlock(){
    return startingBlock;
}
coordinate GameMap2::getEndingBlock(){
    return endingBlock;
}
void GameMap2::setStartingBlock(coordinate sBlock){
    startingBlock = sBlock;
}
void GameMap2::setEndingBlock(coordinate eBlock){
    endingBlock = eBlock;
}

//get block at given coordinates
GameMap2::BlockData* GameMap2::getBlock(int x, int y){
    coordinate block = {x,y};
    return getBlock(block);
}
GameMap2::BlockData* GameMap2::getBlock(coordinate block){
    if(block.x < 0 || block.x > arrayDimensions.x-1){
        return nullptr;
    }
    if(block.y < 0 || block.y > arrayDimensions.y-1){
        return nullptr;
    }
    return mapArray->at(block.x)->at(block.y);
}

//returns the size of the gameMap
coordinate GameMap2::getArrayDimensions(){
    return arrayDimensions;
}

//determines if there is a navigable path from start point to end point
bool GameMap2::validateMap(){
    return validatePath(startingBlock, endingBlock);
}

//sets ground type of a given cell
//needs to be updated if groundtype is update
void GameMap2::fillcell(int x, int y, char obj){
    coordinate block = {x,y};
    GroundType gType;
    switch (obj) {
        case 's':
            gType = STONE;
            break;
        case 'g':
            gType = GRASS;
            break;
        case 'w':
            gType = WATER;
            break;
        case 'W':
            gType = WALL;
            break;
        default:
            break;
    }
    fillcell(block, gType);
}
void GameMap2::fillcell(coordinate block, GroundType gType){
    getBlock(block)->setGroundType(gType);
}

//determines if a block has a gameobject in it
bool GameMap2::isOccupied(int x, int y){
    coordinate block = {x,y};
    return isOccupied(block);
}
bool GameMap2::isOccupied(coordinate block){
    return getBlock(block)->isOccupied();
}

//add or remove a gameObject froma block
void GameMap2::occupyBlock(coordinate block, GameObject *obj){
    this->getBlock(block)->setContainedItem(obj);
}
void GameMap2::deOccupyBlock(coordinate block){
    this->getBlock(block)->setContainedItem(nullptr);
}


//--Validate Path Methods--//
//these 3 fuctions serve to help the validatePath method
bool GameMap2::BlockData::isVisited(){
    return this->v;
}
void GameMap2::BlockData::resetV(){
    this->v = false;
}
void GameMap2::BlockData::setVisited(){
    this->v = true;
}
//determines if there is a navigable path from two points
//does prepwork before calling validatePathHelper() which checks the path recursively
bool GameMap2::validatePath(coordinate a, coordinate b){
    //reset v
    for(int c = 0; c < arrayDimensions.y; c++){
        for(int r = 0; r < arrayDimensions.x; r++){
            getBlock(c, r)->resetV();
        }
    }
    return validatePathHelper(a, b);
    
}
//recursive part of validatePath algorithm
bool GameMap2::validatePathHelper(coordinate a, coordinate b){
    BlockData* current = getBlock(a);
    current->setVisited();
    if(a.x == b.x && a.y == b.y){
        return true;
    }
    else{
        coordinate upC = {a.x,a.y+1};
        coordinate downC = {a.x,a.y-1};
        coordinate leftC = {a.x-1,a.y};
        coordinate rightC = {a.x+1,a.y};
        BlockData* up = getBlock(upC);
        BlockData* down = getBlock(downC);
        BlockData* left = getBlock(leftC);
        BlockData* right = getBlock(rightC);
        
        if(right != NULL && right !=nullptr && right->canMoveInto() && !(right->isVisited())){
            if(validatePathHelper(rightC, b)){
                return true;
            }
        }
        if(up != NULL && up != nullptr && up->canMoveInto() && !(up->isVisited())){
            if(validatePathHelper(upC, b)){
                return true;
            }
        }
        if(down != NULL && down != nullptr && down->canMoveInto() && !(down->isVisited())){
            if(validatePathHelper(downC, b)){
                return true;
            }
        }
        if(left != NULL && left!= nullptr && left->canMoveInto() && !(left->isVisited())){
            if(validatePathHelper(leftC, b)){
                return true;
            }
        }
        return false;
    }
}
//--end of Validate Path Methods--//










