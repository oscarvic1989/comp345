//
//  GameMap2.hpp
//  C++ Testing
//
//  Created by Nelson Frank on 2016-11-03.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef GameMap2_hpp
#define GameMap2_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include <vector>

enum MapType{
    MAP_START,
    MAP_INSIDE,
    MAP_END
};

enum GroundType{ //this set is obviously incomplete and mostly given for example
    STONE = 1,
    GRASS = 2,
    WATER = 3,
    WALL = 4
}; //additions to GroundType may require updating canMoveInto() and fillCell()

struct coordinate{
    int x;
    int y;
};

class GameMap2{
private:
    class BlockData{
    private:
        //denotes whether a block is a starting point, ending point, or neither
        MapType mapType;
        
        //determines the type of terrain
        GroundType groundType;
        
        //determines what is located on the block e.g.; character, item, chest
        GameObject* containedItem;
        
        //helper variable, ignore
        bool v = false;
        
    public:
        //constructors
        BlockData();
        BlockData(MapType mType, GroundType gType, GameObject* cItem);
        
        //destructor
        ~BlockData();
        
        //getters & setters
        MapType getMapType();
        GroundType getGroundType();
        GameObject* getContainedItem();
        void setMapType(MapType mType);
        void setGroundType(GroundType gType);
        void setContainedItem(GameObject* cItem);
        
        bool canMoveInto();
        bool isOccupied();
        
        //3 helper methods, ignore
        bool isVisited();
        void setVisited();
        void resetV();
    };
    
    std::vector<std::vector<BlockData*>*>* mapArray;
    coordinate arrayDimensions = {1,1};
    
    coordinate startingBlock;
    coordinate endingBlock;
    
    GameMap2* previousMap;
    GameMap2* nextMap;
    
    //helper method for validatePath()
    bool validatePathHelper(coordinate a, coordinate b);
    
public:
    //constructors
    GameMap2(); //sets default size and start/end
    GameMap2(int w, int h, coordinate startBlock, coordinate endBlock, GameMap2* pMap, GameMap2* nMap);
    
    //destructor
    ~GameMap2();
    
    //getters and setters for start/end blocks
    coordinate getStartingBlock();
    coordinate getEndingBlock();
    void setStartingBlock(coordinate sBlock);
    void setEndingBlock(coordinate eBlock);
    
    //getter for arbitrary block
    BlockData* getBlock(int x, int y);
    //and alternate
    BlockData* getBlock(coordinate block);
    
    //getter for array dimensions
    coordinate getArrayDimensions();
    
    //add or remove a gameObject from a block
    void occupyBlock(coordinate block, GameObject* obj);
    void deOccupyBlock(coordinate block);
    
    //required methods as specified in assignment 1
    bool validateMap();
    void fillcell(int x, int y, char obj);
    bool isOccupied(int x, int y);
    
    //helper methods for assignment methods
    bool validatePath(coordinate a, coordinate b);
    void fillcell(coordinate block, GroundType gType);
    bool isOccupied(coordinate block);
};

#endif /* GameMap2_hpp */
