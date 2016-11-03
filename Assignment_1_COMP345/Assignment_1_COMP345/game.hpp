//
//  game.hpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-10-22.
//  Copyright © 2016 oscar. All rights reserved.
//

#ifndef game_hpp
#define game_hpp
 #include <unistd.h>
#include <stdio.h>
#include "gameMap.hpp"
#include "character.hpp"
enum GameType {
    type_manu,
    type_mapeditor,
    type_play
};
class game{
public:
    gameMap gamemap;
    character hero;
    GameType type;
    std::vector<gameItem> buttonStack;
    std::vector<gameItem> itemeditor_map;
    std::vector<gameItem> gameitem;
    SDL_Event e;
    SDL_Renderer *renderer;
    
    
    game();
    game(SDL_Renderer *renderer,int w,int h);
    void handleinput();
    void play();
    void render(SDL_Renderer *renderer);
private:
    void manu_gui_event();
    void Cmove();
    bool select=false;
    gameItem testimage;
    void ball();
    int selection();
    bool checkifinside(int x,int y,SDL_Rect dstrect);
    string address2[8]={
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button1 copy.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button1 copy.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button1 copy.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button1 copy.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button1 copy.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button1 copy.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button1 copy.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button1 copy.png",
    };
};

#endif /* game_hpp */
