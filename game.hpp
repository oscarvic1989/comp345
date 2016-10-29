//
//  game.hpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-10-22.
//  Copyright © 2016 oscar. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "gameMap.hpp"
enum GameType {
    type_manu,
    type_mapeditor
};
class game{
public:
    gameMap gamemap;
    GameType type;
    game();
    game(SDL_Renderer *renderer,int w,int h);
    std::vector<gameItem> buttonStack;
    void handleinput();
    void play();
    SDL_Event e;
private:
    void manu_gui_event();
    bool checkifinside(int x,int y,SDL_Rect dstrect);
};

#endif /* game_hpp */
