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
<<<<<<< HEAD
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
=======
#include "campaign.hpp"
#include <SDL2_ttf/SDL_ttf.h>
#include "ItemContainer.hpp"
#include "Item.hpp"
#include "ItemBuilder.hpp"
#include "Enhancement.hpp"
//Nelson Edit:
//added types, changed manu to mainMenu
enum GameType {
    type_mainMenu,
    type_mapeditor,
    type_play,
    type_characterEditor,
    type_itemEditor,
    type_characterSelector,
    type_mapSelector,
    type_mapFileLoad,
    type_characterFileLoad,
    type_exit,
    type_congratulation
};
class game{
public:
    
    //
    campaign Campaign;
    gameMap gamemap;
    GameType type;
    
    //Nelson Edit:
    //change name of button stack, add two more button stacks
    std::vector<gameItem> mainMenuButtonStack;
    std::vector<gameItem> charSelectMenuButtonStack;
    std::vector<gameItem> mapSelectMenuButtonStack;
    std::vector<gameItem> CampaignEditorButtonStack;
    gameItem glowingSquare;
    
    std::vector<gameItem> itemeditor_map;
    std::vector<gameItem> display_item;

>>>>>>> map-with-basic-gui
    SDL_Event e;
    SDL_Renderer *renderer;
    
    
    game();
    game(SDL_Renderer *renderer,int w,int h);
    void handleinput();
    void play();
    void render(SDL_Renderer *renderer);
private:
<<<<<<< HEAD
    void manu_gui_event();
    void Cmove();
=======
    void mainMenu_gui_event();
    void charSelectMenuGuiEvent();
    void mapSelectMenuGuiEvent();
    void mapEditorControlButtonsHandler();
    void Cmove();
    void gamePlayHandler();
>>>>>>> map-with-basic-gui
    bool select=false;
    gameItem testimage;
    void ball();
    int selection();
    bool checkifinside(int x,int y,SDL_Rect dstrect);
<<<<<<< HEAD
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
=======
    
    //Nelson Edit:
    //changed filepath
    string address2[8]={
        "resources/ball.png",
        "resources/ball.png",
        "resources/ball.png",
        "resources/ball.png",
        "resources/ball.png",
        "resources/ball.png",
        "resources/ball.png",
        "resources/ball.png",
    };
    //Nelson Edit:
    //added 3 images
    gameItem scrollMessageItemEditor;
    gameItem scrollMessageCharacterEditor;
    gameItem scrollMessageCharacterLoad;
    gameItem scrollMessageMapLoad;
    gameItem mainBackground;
    
    void checkifnextMap();
    int numberofMap = 0;
    int currentMapCounter=0;
    
    //Nelson edit:
    // I made this variable to assist the charEditor and mapEditor types in render(). This should not be needed after refactoring properly
    //the name is totally arbitrary
    int ccc = 0;
>>>>>>> map-with-basic-gui
};

#endif /* game_hpp */
