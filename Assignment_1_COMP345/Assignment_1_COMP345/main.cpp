//
//  main.cpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-10-19.
//  Copyright © 2016 oscar. All rights reserved.
//

/**
 * Game rules:
 *   1)Enter the width of the screen
 *   2)Enter the height of the screen
 *   3)Enter the start point
 *   4)Enter the end point
 * Design:
 *   Thie application promote user to generate a map related to D&D game;
 * Libaray:
 *   SDL2;SDL2/IMAGE
 */
#include <iostream>
#include <SDL2/SDL.h>
#include "gameMap.hpp"
#include "mapUnit.hpp"
#include "game.hpp"
#include <SDL2_ttf/SDL_ttf.h>

 const int weigth=800;
 const int height=600;
int main(int argc, const char * argv[]) {
    cout<<"start"<<endl;
    
    SDL_Window *window = SDL_CreateWindow("COMP345_PROJECT",
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, weigth, height, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer=SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    gameMap maptest=gameMap(weigth,height,renderer);
    game gametest=game(renderer,weigth,height);
    bool quit=false;
    
    //test
    TTF_Init();
    TTF_Font* Sans;
    Sans= TTF_OpenFont("/Users/oscar/Documents/xcode project/OpenSans-Light.ttf", 90); //this opens a font style and sets a size
    
    SDL_Color White = {255, 100, 100};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
    
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "Welcome", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
    
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture
    
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 0;  //controls the rect's x coordinate
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect
    
    while(!quit){
    
        while(gametest.type==type_manu){
            SDL_RenderClear(renderer);
            for(std::vector<gameItem>::iterator it = gametest.buttonStack.begin() ; it != gametest.buttonStack.end(); ++it){
                SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                //Update screen
            }
            SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
            SDL_RenderPresent(renderer );
            SDL_RenderClear(renderer);
            gametest.handleinput();
            if(gametest.e.key.keysym.sym == SDLK_ESCAPE&&gametest.e.type == SDL_KEYDOWN)
                quit=true;break;
        }
        
        while(gametest.type==type_mapeditor){
            SDL_RenderClear(renderer);
            for(std::vector<mapUnit>::iterator it = maptest.mapStack.begin() ; it != maptest.mapStack.end(); ++it){
                SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                //Update screen
            }
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);
            if(gametest.e.key.keysym.sym == SDLK_ESCAPE&&gametest.e.type == SDL_KEYDOWN)
                quit=true;break;
        }
    }
    return 0;
}
