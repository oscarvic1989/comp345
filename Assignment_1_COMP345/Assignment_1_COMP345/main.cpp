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

 const int weigth=900;
 const int height=700;
int main(int argc, const char * argv[]) {
    cout<<"start"<<endl;
    
    SDL_Window *window = SDL_CreateWindow("COMP345_PROJECT",
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, weigth, height, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer=SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    game gametest=game(renderer,weigth,height);
    gametest.gamemap=gameMap(weigth,height,renderer);

    bool quit=false;
    //test
    /*
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
    */
    while(!quit){
        gametest.play();
        
        SDL_RenderClear(renderer);
        gametest.render(renderer);
        SDL_RenderPresent(renderer );
        SDL_RenderClear(renderer);
        /*if(gametest.e.key.keysym.sym == SDLK_ESCAPE&&gametest.e.type == SDL_KEYDOWN)
            quit=true;*/
    }
    return 0;
}


