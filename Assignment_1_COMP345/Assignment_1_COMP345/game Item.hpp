//
//  game Item.hpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-10-26.
//  Copyright © 2016 oscar. All rights reserved.
//

#ifndef game_Item_hpp
#define game_Item_hpp

#include <stdio.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

using namespace std;



class gameItem{
public:
    SDL_Surface * image;
    SDL_Texture * texture;
    SDL_Rect srcrect;
    SDL_Rect dstrect;
    gameItem(SDL_Renderer *renderer,SDL_Rect srcrect,
             SDL_Rect dstrect, string address);
    gameItem();
    void setImage(SDL_Renderer *renderer,string address);
};
#endif /* game_Item_hpp */
