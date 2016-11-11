//
//  campaign.hpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-11-09.
//  Copyright © 2016 oscar. All rights reserved.
//

#ifndef campaign_hpp
#define campaign_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "gameMap.hpp"
#include "character.hpp"

class campaign{
public:
    std::vector<gameMap> gameMapStack;
    character hero;
    std::vector<gameItem> gameitem;
    campaign();
    campaign(SDL_Renderer *renderer);
    void setMaps();
    void setName(string name);
    string getName();
    std::vector<string> mapNameStack;
private:
    SDL_Renderer *renderer;
    string name;
    
};
#endif /* campaign_hpp */
