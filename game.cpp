//
//  game.cpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-10-22.
//  Copyright © 2016 oscar. All rights reserved.
//

#include "game.hpp"

game::game(){
    
}

//button loading
game::game(SDL_Renderer *renderer,int w,int h){
    gameItem temp1;
    this->type=type_manu;
    string address[4]={
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button Items/menu_new_game2.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button Items/menu_new_game2.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button Items/menu_new_game3.png",
        "/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button Items/menu_new_game4.png"
    };
    SDL_Rect srcrect={0,0,481,124};
    SDL_Rect dstrect={(w-200)/2,h/9,w/4,h/9};

    for(int i=0;i<4;i++){
        dstrect.y=80+i*h/9;
        temp1=gameItem(renderer,srcrect,dstrect,address[i]);
        buttonStack.push_back(temp1);
    }
};

void game::play(){
    
}
void game::handleinput(){
    if(this->type==type_manu){
        manu_gui_event();
    }
    if(this->type==type_mapeditor){
    }
}

bool game::checkifinside(int x,int y,SDL_Rect dstrect){
    if((x<(dstrect.x+dstrect.w)&&x>(dstrect.x))&&(y<(dstrect.y+dstrect.h)&&x>(dstrect.y)))
       return true;
    else
       return false;
}
void game::manu_gui_event()
{
    SDL_WaitEvent(&e);
    bool inside = false;
    int x, y;
    int index=999;
    x = e.motion.x;
    y = e.motion.y;
    for(int i=0;i<this->buttonStack.size();i++)
    {
        inside=checkifinside(x,y, buttonStack[i].dstrect);
        if(inside&&(e.button.button == SDL_BUTTON_LEFT)){
            if(i==2)
                this->type=type_mapeditor;
            break;
        }
    }
}
