//
//  character.hpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-11-02.
//  Copyright © 2016 oscar. All rights reserved.
//

#ifndef character_hpp
#define character_hpp
#include "game Item.hpp"
<<<<<<< HEAD
#include <stdio.h>

=======
#include "ItemContainer.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "ItemBuilder.hpp"
#include "Item.hpp"
>>>>>>> map-with-basic-gui
class character :public gameItem{
public:
    character();
    character(SDL_Renderer *renderer);
<<<<<<< HEAD
    int movecounter=0;
    int Directioncounter=2;
    int movestep=128;
    
=======
    void characterEdit();
    int movecounter=0;
    int Directioncounter=2;
    int movestep=128;
    void setName(string a);
    int a=100;
    int b=100;
    int c=100;
    int d=100;
    string name;
    //itemContainer bag;
    void iniCharacterFromFile(string a,string b,string c);
    ItemContainer *backPack=new ItemContainer;
    ItemContainer *InventoryPane=new ItemContainer;
    void iniAblility();
    void equip();
    void removeItem();
    int abilityScore[6]={100,100,100,100,100,100};//0:str;1:dex;2:con;3:intel;4: wis;5 cha
    int hitpoint;
    int level=1;
private:
>>>>>>> map-with-basic-gui
};
#endif /* character_hpp */
