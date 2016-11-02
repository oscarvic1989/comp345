//
//  GameMap.hpp
//  C++ Testing
//
//  Created by Nelson Frank on 2016-10-31.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef GameMap_hpp
#define GameMap_hpp

#include <stdio.h>
#include <Vector>
#include "GameObject.hpp" //a GameObject represents any unit that can be placed on a map tile (e.g.; characters, chests, interactable objects)

enum MapType{
    MAP_START,
    MAP_INSIDE,
    MAP_END
};
enum GroundType{ //this set is obviously incomplete and mostly given for example
    STONE,
    GRASS,
    WATER,
    WALL
};

class GameMap{
private:
    //inner class to handle each map block
    class MapNode{
    private:
        //adjacent nodes
        MapNode* up = nullptr;
        MapNode* down = nullptr;
        MapNode* left = nullptr;
        MapNode* right = nullptr;
        
        //represents the relative xy displacement of a given node from the starting node
        //setting a adjacent node checks the relative x/y coordinates so that two nodes are not placed in the same location
        //allows to update pointers to all nodes around them
        int relativeX = 0;
        int relativeY = 0;
        
        //defines the type of ground e.g.; grass, water, stone path. wall?
        GroundType groundType = STONE;
        
        //Stores object positioned on node
        GameObject* containedItem = nullptr;
        
        MapType mapType = MAP_INSIDE;
        
    public:
        //constructors
        MapNode();
        MapNode(MapNode* up, MapNode* down, MapNode* left, MapNode* right);
        
        //destructor
        ~MapNode();
        
        //getters&setters for adjacent nodes
        MapNode* getUp();
        MapNode* getDown();
        MapNode* getLeft();
        MapNode* getRight();
        void setUp(MapNode* node);
        void setDown(MapNode* node);
        void setLeft(MapNode* node);
        void setRight(MapNode* node);
        
        //getter&setter for containedItem
        GameObject* getContainedItem();
        void setContainedItem(GameObject* object);
        
        //checks if node contains a gameObject
        bool isOccupied();
        
        //getter&setter for MapType
        MapType getMapType();
        void setMapType(MapType type);
        
    };
    
    //pointer starting and ending nodes (equivalent to head/tail of linked list)
    MapNode* startingNodes;
    MapNode* endingNodes;
    
public:
    //constructors
    GameMap();
    GameMap(MapNode startNode, MapNode endNode);
    GameMap(MapNode* startNode, MapNode* endNode);
    
    //destructor
    ~GameMap();
    
    //getters and setters for starting and ending node lists
    MapNode* getStartingNodes();
    MapNode* getEndingNodes();
    void setStartingNodes(MapNode* startNodes);
    void setEndingNodes(MapNode* endNodes);
    
    //required methods as specified in assignment 1
    bool validateMap();
    void fillCell(int x, int y, char obj); //can either use switch to correspond characters with groundType enum or replace enum with chars
    bool isOccupied(int x, int y);
    
    //counts the number of mapnodes in the map
    //optional
    int sizeOfMap();
};


#endif /* GameMap_hpp */
