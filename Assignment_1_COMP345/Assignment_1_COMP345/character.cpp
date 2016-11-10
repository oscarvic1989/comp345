//
//  character.cpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-11-02.
//  Copyright © 2016 oscar. All rights reserved.
//

#include "character.hpp"

character::character(){
    
}
character::character(SDL_Renderer *renderer){
    this->dstrect={0,0,100,100};
    this->srcrect={movecounter*movestep,Directioncounter*movestep,128,128};
    this->image = IMG_Load("resources/hero.png");
    this->texture=SDL_CreateTextureFromSurface(renderer, this->image);
}
