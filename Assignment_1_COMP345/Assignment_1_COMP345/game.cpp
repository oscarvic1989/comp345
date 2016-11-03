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
    hero=character(renderer);
    this->renderer=renderer;
    SDL_Rect srcrectTEMP={0,0,600,600};
    SDL_Rect dstrectTEMP={0,0,100,100};
    this->testimage=gameItem(renderer, srcrectTEMP,
                              dstrectTEMP, "ds");
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
    srcrect={0,0,600,600};
    dstrect={0,600,100,100};
    for(int i=0;i<8;i++){
        temp1=gameItem(renderer,srcrect,dstrect,address2[i]);
        itemeditor_map.push_back(temp1);
        dstrect.x+=100;
    }

};

void game::play(){
    handleinput();
}
void game::render(SDL_Renderer *renderer){
    if(this->type==type_manu){
        for(std::vector<gameItem>::iterator it = this->buttonStack.begin() ; it != this->buttonStack.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
    }
    if(this->type==type_mapeditor){
        for(std::vector<mapUnit>::iterator it = this->gamemap.mapStack.begin() ; it != this->gamemap.mapStack.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
        for(std::vector<gameItem>::iterator it = this->itemeditor_map.begin() ;
            it != this->itemeditor_map.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
        for(std::vector<gameItem>::iterator it = this->gameitem.begin() ;
            it != this->gameitem.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
         SDL_RenderCopy(renderer, this->hero.texture,&this->hero.srcrect, &this->hero.dstrect);
        SDL_RenderCopy(renderer, this->testimage.texture,&this->testimage.srcrect, &this->testimage.dstrect);
    }
    if(this->type==type_play){
        for(std::vector<mapUnit>::iterator it = this->gamemap.mapStack.begin() ; it != this->gamemap.mapStack.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
        SDL_RenderCopy(renderer, this->hero.texture,&this->hero.srcrect, &this->hero.dstrect);
        SDL_RenderCopy(renderer, this->testimage.texture,&this->testimage.srcrect, &this->testimage.dstrect);
    }

}
void game::handleinput(){
    if(this->type==type_manu){
        manu_gui_event();
    }
    if(this->type==type_mapeditor){
        ball();
        selection();
        Cmove();
    }
    if(this->type==type_play){
        Cmove();
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
    x = e.motion.x;
    y = e.motion.y;
    for(int i=0;i<this->buttonStack.size();i++)
    {
        inside=checkifinside(x,y, buttonStack[i].dstrect);
        if(inside&&(e.button.button == SDL_BUTTON_LEFT)){
            if(i==1){
                this->type=type_play;
                break;
            }
            if(i==2){
                this->type=type_mapeditor;
                break;
            }
        }
    }
}
void game::Cmove(){
    SDL_WaitEvent(&e);
    switch(e.key.keysym.sym){
        case SDLK_w:
            if(e.type == SDL_KEYDOWN){
                if(hero.Directioncounter!=3){
                    hero.movecounter=0;
                    hero.Directioncounter=3;
                }
                else{
                    if(hero.movecounter<=3)
                        hero.movecounter++;
                    else
                        hero.movecounter=0;
                    hero.Directioncounter=3;
                }
                hero.dstrect.y-=100;
            }
            break;
        case SDLK_s:
            if(e.type == SDL_KEYDOWN){
                if(hero.Directioncounter!=2){
                    hero.movecounter=0;
                    hero.Directioncounter=2;
                }
                else{
                    if(hero.movecounter<=3)
                        hero.movecounter++;
                    else
                        hero.movecounter=0;
                    hero.Directioncounter=2;
                }
                hero.dstrect.y+=100;
            }
            break;
        case SDLK_a:
            if(e.type == SDL_KEYDOWN){
                if(hero.Directioncounter!=0){
                    hero.movecounter=0;
                    hero.Directioncounter=0;
                }
                else{
                    if(hero.movecounter<=3)
                        hero.movecounter++;
                    else
                        hero.movecounter=0;
                    hero.Directioncounter=0;
                }
                hero.dstrect.x-=100;
            }
            break;
        case SDLK_d:
            if(e.type == SDL_KEYDOWN){
                if(hero.Directioncounter!=1){
                    hero.movecounter=0;
                    hero.Directioncounter=1;
                }
                else{
                    if(hero.movecounter<=3)
                        hero.movecounter++;
                    else
                        hero.movecounter=0;
                    hero.Directioncounter=1;
                }
                hero.dstrect.x+=100;
            }
            break;
    }
    hero.srcrect.x=hero.movecounter*hero.movestep;
    hero.srcrect.y=hero.Directioncounter*hero.movestep;
    
    }
void game::ball()
{
    int flag=selection();
    string address="/Users/oscar/Documents/xcode project/Assignment_1_COMP345/button"+to_string(flag)+" copy.png";
    SDL_WaitEvent(&e);
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);
    if(flag!=-1&&select){
        x=x/100*100;
        y=y/100*100;
        if(y>500)
            y=500;
        this->testimage.dstrect.x=x;
        this->testimage.dstrect.y=y;
        this->testimage.setImage(this->renderer, address2[flag]);
        if(e.button.button == SDL_BUTTON_RIGHT)
        {
            flag=-1;
            select=false;
            gameitem.push_back(this->testimage);
        }
    }
    else if(select&&flag==-1){
        x=x/100*100;
        y=y/100*100;
        if(y>500)
            y=500;
        this->testimage.dstrect.x=x;
        this->testimage.dstrect.y=y;
        if(e.button.button == SDL_BUTTON_RIGHT)
        {
            gameitem.push_back(this->testimage);
            select=false;
        }
    }
    
}
int game::selection(){
    SDL_WaitEvent(&e);
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);
    x=x/100*100;
    y=y/100*100;
    if(y>500&&(e.button.button == SDL_BUTTON_LEFT))
    {
        cout<<x/100;
        select=true;
        return x/100;
    }
    else
        return -1;
}
