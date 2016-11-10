//
//  campaign.cpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-11-09.
//  Copyright © 2016 oscar. All rights reserved.
//

#include "campaign.hpp"

campaign::campaign(){
    
};

campaign::campaign(SDL_Renderer *renderer){
    this->renderer=renderer;
}

void campaign::setName(string name){
    this->name=name;
}

string campaign::getName(){
    return this->name;
}

void campaign::setMaps(){
    for(int i=0;i<this->mapNameStack.size();i++){
        std::ifstream inputfile ("saved map/"+this->mapNameStack[i]+".txt");
        std::string line;
        while (std::getline(inputfile, line))
        {
            this->mapNameStack.push_back(line);
        }
        inputfile.close();

    }
}
