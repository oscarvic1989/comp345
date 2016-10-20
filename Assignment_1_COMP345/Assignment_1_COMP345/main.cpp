//
//  main.cpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-10-19.
//  Copyright © 2016 oscar. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "gameMap.hpp"
#include "mapUnit.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    SDL_Window *window = SDL_CreateWindow("SDL2 Displaying Image",
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer *renderer=SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    /*create a texture 
    SDL_Surface *image = IMG_Load("/Users/oscar/Documents/xcode project/Assignment_1_COMP345/ground.jpg");
    SDL_Texture *texture=SDL_CreateTextureFromSurface(renderer,image);
     */
    gameMap *maptest=new gameMap(800,600,renderer);
    
    while(true){
        for(std::vector<mapUnit>::iterator it = maptest->mapStack.begin() ; it != maptest->mapStack.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
        SDL_RenderPresent(renderer );
        SDL_RenderClear(renderer);
    }
    return 0;
}
