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
    SDL_Rect dstrectTEMP={0,0,defaultTileSize,defaultTileSize};
    this->testimage=gameItem(renderer, srcrectTEMP,
                              dstrectTEMP, "ds");
    gameItem temp1;
    this->type=type_mainMenu;
    
    
    //Nelson Edit:
    //change array name, size, addresses, some order changes
    const int numberMainMenuButtons = 5;
    string mainMenuButtonImagesAddresses[numberMainMenuButtons]={
        "resources/menu_buttons/main_newgame.png",
        "resources/menu_buttons/main_mapeditor.png",
        "resources/menu_buttons/main_item_editor.png",
        "resources/menu_buttons/main_character_editor.png",
        "resources/menu_buttons/main_exit.png"
    };
    const int numberCharSelectMenuButtons = 2;
    string charSelectMenuButtonImagesAddresses[numberCharSelectMenuButtons]={
        "resources/menu_buttons/charSelect_default_character.png",
        "resources/menu_buttons/charSelect_load_character.png"
    };
    const int numberMapSelectMenuButtons = 2;
    string mapSelectMenuButtonImagesAddresses[numberMapSelectMenuButtons]={
        "resources/menu_buttons/mapSelect_default_map.png",
        "resources/menu_buttons/mapSelect_load_map.png"
    };
    
    SDL_Rect srcrect={0,0,382,157};
    SDL_Rect dstrect={(w-200)/2,h/9,w/4,h/9};

    //Nelson Edit:
    //change 4 to const int of number main menu buttons
    
    //load main menu buttons into stack
    for(int i=0; i < numberMainMenuButtons;i++){
        dstrect.y=80+i*h/9+i*45; //TODO: get input from Oscar to change this
        temp1=gameItem(renderer,srcrect,dstrect,mainMenuButtonImagesAddresses[i]);
        mainMenuButtonStack.push_back(temp1);
    }
    //Nelson Edit:
    //
    //load char select menu buttons into stack
    for(int i=0; i< numberCharSelectMenuButtons; i++){
        dstrect.y=i*h/9+i*45+h/4; //TODO: get input from oscar to change this
        temp1=gameItem(renderer,srcrect,dstrect,charSelectMenuButtonImagesAddresses[i]);
        charSelectMenuButtonStack.push_back(temp1);
    }
    //Nelson Edit:
    //
    //load map select menu buttons into stack
    for(int i=0; i< numberMapSelectMenuButtons; i++){
        dstrect.y=i*h/9+i*45+h/4; //TODO: get input from oscar to change this
        temp1=gameItem(renderer,srcrect,dstrect,mapSelectMenuButtonImagesAddresses[i]);
        mapSelectMenuButtonStack.push_back(temp1);
    }
    //Nelson Edit:
    //
    //Load scroll messages
    this->scrollMessageItemEditor = gameItem(renderer, SDL_Rect{0,0,781,763}, SDL_Rect{0,0,w,h}, "resources/scroll_message_item_editor.png");
    this->scrollMessageCharacterEditor = gameItem(renderer, SDL_Rect{0,0,781,763}, SDL_Rect{0,0,w,h}, "resources/scroll_message_character_editor.png");
    this->scrollMessageCharacterLoad = gameItem(renderer, SDL_Rect{0,0,781,763}, SDL_Rect{0,0,w,h}, "scroll_message_load_character.png");
    this->scrollMessageMapLoad = gameItem(renderer, SDL_Rect{0,0,781,763}, SDL_Rect{0,0,w,h}, "scroll_message_load_map.png");
    //load background
    this->mainBackground = gameItem(renderer, SDL_Rect{0,0,1773,1182}, SDL_Rect{0,0,w,h}, "resources/background.jpg");
    
    
    srcrect={0,0,600,600};
    dstrect={0,600,defaultTileSize,defaultTileSize};
    for(int i=0;i<8;i++){
        temp1=gameItem(renderer,srcrect,dstrect,address2[i]);
        itemeditor_map.push_back(temp1);
        dstrect.x+=defaultTileSize;
    }

};

void game::play(){
    handleinput();
}
void game::render(SDL_Renderer *renderer){
    //Nelson Edit:
    //render background
    SDL_RenderCopy(renderer, this->mainBackground.texture,&this->mainBackground.srcrect, &this->mainBackground.dstrect);
    
    
    if(this->type==type_mainMenu){
        for(std::vector<gameItem>::iterator it = this->mainMenuButtonStack.begin() ; it != this->mainMenuButtonStack.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
    }
    else if(this->type==type_mapeditor){
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
        //SDL_RenderCopy(renderer, this->hero.texture,&this->hero.srcrect, &this->hero.dstrect);
        SDL_RenderCopy(renderer, this->testimage.texture,&this->testimage.srcrect, &this->testimage.dstrect);
    }
    else if(this->type==type_play){
        for(std::vector<mapUnit>::iterator it = this->gamemap.mapStack.begin() ; it != this->gamemap.mapStack.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
        SDL_RenderCopy(renderer, this->hero.texture,&this->hero.srcrect, &this->hero.dstrect);
       
    }
    //Nelson Edit:
    //added ability to quit game with quit button
    else if(this->type == type_exit){
        exit(0);
    }
    //TODO
    else if(this->type == type_itemEditor){
        //render scroll message
        if(ccc % 2 == 0){
            SDL_RenderCopy(renderer, this->scrollMessageItemEditor.texture, &this->scrollMessageItemEditor.srcrect, &this->scrollMessageItemEditor.dstrect);
        }
        else{
            //start Yann's code here:
            cout << "TEST" << endl;
            char a;
            cin >> a;
            //end Yann's code here
            
            this->type = type_mainMenu;
        }
        ccc++;
    }
    else if(this->type == type_characterEditor){
        //render scroll message
        if(ccc % 2 == 0){
            SDL_RenderCopy(renderer, this->scrollMessageCharacterEditor.texture, &this->scrollMessageCharacterEditor.srcrect, &this->scrollMessageCharacterEditor.dstrect);
        }
        else{
            //start Wan's code here:
            cout << "TEST" << endl;
            char a;
            cin >> a;
            //end Wan's code here
            
            this->type = type_mainMenu;
        }
        ccc++;
    }
    else if(this->type == type_characterSelector){
        //add selector menu and input and stuff
        for(std::vector<gameItem>::iterator it = this->charSelectMenuButtonStack.begin() ; it != this->charSelectMenuButtonStack.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
        //transition to map selector
    }
    else if(this->type == type_mapSelector){
        //add selector menu and input and stuff
        for(std::vector<gameItem>::iterator it = this->mapSelectMenuButtonStack.begin() ; it != this->mapSelectMenuButtonStack.end(); ++it){
            SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
            //Update screen
        }
        //transtion to game selector
    }
    else if(this->type == type_mapFileLoad){
        //render scroll message
        if(ccc % 2 == 0){
            SDL_RenderCopy(renderer, this->scrollMessageMapLoad.texture, &this->scrollMessageMapLoad.srcrect, &this->scrollMessageMapLoad.dstrect);
        }
        else{
            //start Map load code here:
            cout << "TEST" << endl;
            char a;
            cin >> a;
            //end Map load code here
            
            this->type = type_mainMenu;
        }
        ccc++;
    }

}
void game::handleinput(){
    //Nelson Edit:
    //changed to switch statement, added some cases
    switch (this->type) {
        case type_mainMenu:
            mainMenu_gui_event();
            break;
        case type_mapeditor:
            ball();
            selection();
            Cmove();
            break;
        case type_play:
            Cmove();
            break;
        case type_characterSelector:
            charSelectMenuGuiEvent();
            break;
        case type_mapSelector:
            mapSelectMenuGuiEvent();
            break;
            
        case type_characterEditor:
        case type_itemEditor:
        case type_mapFileLoad:
        case type_characterFileLoad:
            //do nothing, GUI input is suspended in favour of console
            break;
        case type_exit:
            std::cerr << "This code should never be able to be reached. handleInput()" << std::endl;
            break;
        default:
            std::cerr << "Unhandled type in method handleinput()" << std::endl;
            break;
    }
}

bool game::checkifinside(int x,int y,SDL_Rect dstrect){
    //Nelson Edit:
    //change y to x in last part
    if(x < (dstrect.x + dstrect.w) &&
       y < (dstrect.y + dstrect.h) &&
       x > dstrect.x &&
       y > dstrect.y )
    {
        return true;
    }
    else{
        return false;
    }
}
void game::mainMenu_gui_event(){
    SDL_WaitEvent(&e);
    bool inside = false;
    int x, y;
    x = e.motion.x;
    y = e.motion.y;
   
    
    //Nelson Edit:
    //make it only run on click
     int i = 0;
    if(e.button.button == SDL_BUTTON_LEFT && e.button.state == SDL_RELEASED){
        for(i = 0; i <this->mainMenuButtonStack.size();i++){
            inside = checkifinside(x,y, mainMenuButtonStack[i].dstrect);
            if(inside){
                break;
            }
        }
        
    }
    if(inside){
        //Nelson Edit:
        //change multiple ifs to switch and added cases
        switch(i){
            case 0: this->type = type_characterSelector ;break;
            case 1: this->type = type_mapeditor ;break;
            case 2: this->type = type_itemEditor ;break;
            case 3: this->type = type_characterEditor ;break;
            case 4: this->type = type_exit ;break;
            default: std::cerr << "Error selecting button." << std::endl; break;
        }
    }
    SDL_FlushEvent(1026); //Fixes specific bug which would cause things to trigger twice.
}

//Nelson Edit:
//added these 2 methods
void game::charSelectMenuGuiEvent(){
    SDL_WaitEvent(&e);
    bool inside = false;
    int x, y;
    x = e.motion.x;
    y = e.motion.y;

    int i = 0;
    if(e.button.button == SDL_BUTTON_LEFT && e.button.state == SDL_RELEASED){
        for(i = 0; i <this->charSelectMenuButtonStack.size();i++){
            inside = checkifinside(x,y, charSelectMenuButtonStack[i].dstrect);
            if(inside){
                break;
            }
        }
        
    }
    if(inside){
        switch(i){
            case 0:
                //TODO: load the default map;
                break;
            case 1:
                //TODO get path to map from file and load that
                break;
            default: std::cerr << "Error selecting button." << std::endl; break;
        }
        this->type = type_mapSelector;
    }
    SDL_FlushEvent(1026); //Fixes specific bug which would cause things to trigger twice.
}
void game::mapSelectMenuGuiEvent(){
    SDL_WaitEvent(&e);
    bool inside = false;
    int x, y;
    x = e.motion.x;
    y = e.motion.y;
    
    int i = 0;
    if(e.button.button == SDL_BUTTON_LEFT && e.button.state == SDL_RELEASED){
        for(i = 0; i <this->mapSelectMenuButtonStack.size();i++){
            inside = checkifinside(x,y, mapSelectMenuButtonStack[i].dstrect);
            if(inside){
                break;
            }
        }
        
    }
    if(inside){
        switch(i){
            case 0:
                //TODO: load the default character;
                break;
            case 1:
                //TODO get path to character from file and load that
                break;
            default: std::cerr << "Error selecting button." << std::endl; break;
        }
        this->type = type_play;
    }
    SDL_FlushEvent(1026); //Fixes specific bug which would cause things to trigger twice.
}

void game::Cmove(){
    //Nelson Edit::
    //fixing this whole method
    
    SDL_WaitEvent(&e);
    switch(e.key.keysym.sym){
        case SDLK_UP: //execute code in next case
        case SDLK_w:
            if(e.type == SDL_KEYDOWN){
                
                //check if within map bounds
                bool withinMapBounds = false;
                if(hero.dstrect.y > 0){
                    withinMapBounds = true;
                }
                
                //check if next block is occupied
                bool nextIsNotOccupied = false;
                SDL_Rect nextRect = hero.dstrect; nextRect.y -= defaultTileSize;
                if(! this->gamemap.checkifOccpuied(nextRect) ){
                    nextIsNotOccupied = true;
                }
                
                if(withinMapBounds && nextIsNotOccupied){
                    
                    //set next block to occupied (by hero)
                    this->gamemap.setOccpuied(nextRect);
                    //set current block to unoccupied
                    this->gamemap.setOccupied(hero.dstrect, false);
                    
                    //move hero
                    hero.dstrect.y -= defaultTileSize;
                }
                
                //set character's facing direction
                hero.Directioncounter = 3;
            }
            break;
        case SDLK_DOWN: //execute code in next case
        case SDLK_s:
            if(e.type == SDL_KEYDOWN){
                //check if within map bounds
                bool withinMapBounds = false;
                if(hero.dstrect.y < (this->gamemap.getNumberVerticalElements()-1)*defaultTileSize){
                    withinMapBounds = true;
                }
                
                //check if next block is occupied
                bool nextIsNotOccupied = false;
                SDL_Rect nextRect = hero.dstrect; nextRect.y += defaultTileSize;
                if(! this->gamemap.checkifOccpuied(nextRect) ){
                    nextIsNotOccupied = true;
                }
                
                if(withinMapBounds && nextIsNotOccupied){
                    
                    //set next block to occupied (by hero)
                    this->gamemap.setOccpuied(nextRect);
                    //set current block to unoccupied
                    this->gamemap.setOccupied(hero.dstrect, false);
                    
                    //move hero
                    hero.dstrect.y += defaultTileSize;
                }
                
                //set character's facing direction
                hero.Directioncounter = 2;
            }
            break;
        case SDLK_LEFT: //execute code in next case
        case SDLK_a:
            if(e.type == SDL_KEYDOWN){
                
                //check if within map bounds
                bool withinMapBounds = false;
                if(hero.dstrect.x > 0){
                    withinMapBounds = true;
                }
                
                //check if next block is occupied
                bool nextIsNotOccupied = false;
                SDL_Rect nextRect = hero.dstrect; nextRect.x -= defaultTileSize;
                if(! this->gamemap.checkifOccpuied(nextRect) ){
                    nextIsNotOccupied = true;
                }
                
                if(withinMapBounds && nextIsNotOccupied){
                    
                    //set next block to occupied (by hero)
                    this->gamemap.setOccpuied(nextRect);
                    //set current block to unoccupied
                    this->gamemap.setOccupied(hero.dstrect, false);
                    
                    //move hero
                    hero.dstrect.x -= defaultTileSize;
                }
                
                //set character's facing direction
                hero.Directioncounter = 0;
            }
            break;
        case SDLK_RIGHT: //execute code in next case
        case SDLK_d:
            if(e.type == SDL_KEYDOWN){
                
                //check if within map bounds
                bool withinMapBounds = false;
                if(hero.dstrect.x < (this->gamemap.getNumberHorizontalElements()-1)*defaultTileSize){
                    withinMapBounds = true;
                }
                
                //check if next block is occupied
                bool nextIsNotOccupied = false;
                SDL_Rect nextRect = hero.dstrect; nextRect.x += defaultTileSize;
                if(! this->gamemap.checkifOccpuied(nextRect) ){
                    nextIsNotOccupied = true;
                }
                
                if(withinMapBounds && nextIsNotOccupied){
                    
                    //set next block to occupied (by hero)
                    this->gamemap.setOccpuied(nextRect);
                    //set current block to unoccupied
                    this->gamemap.setOccupied(hero.dstrect, false);
                    
                    //move hero
                    hero.dstrect.x += defaultTileSize;
                }
                
                //set character's facing direction
                hero.Directioncounter = 1;
            }
            break;
    }
    //update move counter if a button was pressed
    if(e.type == SDL_KEYDOWN){
        hero.movecounter = (hero.movecounter + 1) % 4;
    }
    
    //select appropriate sprite
    hero.srcrect.x=hero.movecounter*hero.movestep;
    hero.srcrect.y=hero.Directioncounter*hero.movestep;
    
    }

void game::ball(){
    int flag=selection();
    SDL_WaitEvent(&e);
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);
    if(flag!=-1&&select){
        x=x/defaultTileSize*defaultTileSize;
        y=y/defaultTileSize*defaultTileSize;
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
        x=x/defaultTileSize*defaultTileSize;
        y=y/defaultTileSize*defaultTileSize;
        if(y>500)
            y=500;
        this->testimage.dstrect.x=x;
        this->testimage.dstrect.y=y;
        if(e.button.button == SDL_BUTTON_RIGHT)
        {
            if(!this->gamemap.checkifOccpuied(this->testimage.dstrect)){
                gameitem.push_back(this->testimage);
                select=false;
                this->gamemap.setOccpuied(this->testimage.dstrect);
            }
        }
    }
    
}

int game::selection(){
    SDL_WaitEvent(&e);
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);
    x = x / defaultTileSize*defaultTileSize; //truncate to integer
    y = y / defaultTileSize*defaultTileSize; //truncate to integer
    if(y > 500 && (e.button.button == SDL_BUTTON_LEFT) )
    {
        //For tracing: cout<<x/defaultTileSize;
        select = true;
        return x/defaultTileSize;
    }
    else
        return -1;
}
