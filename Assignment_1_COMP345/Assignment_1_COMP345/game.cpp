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
    Campaign = campaign(renderer);
    
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
        "resources/menu_buttons/campaignSelect_load_map.png",
        "resources/menu_buttons/campaignSelect_create_new.png"
    };
    const int numberCampaignEditorButtons = 2;
    string CampaignEditorButtons[numberCampaignEditorButtons]={
        "resources/me_exit.png",
        "resources/me_next.png"
    };
    glowingSquare = gameItem(renderer, SDL_Rect{0,0,256,256}, SDL_Rect{0,0,defaultTileSize,defaultTileSize},"resources/glowingsquare.png");
    
    SDL_Rect srcrect={0,0,382,157};
    SDL_Rect dstrect={(w-200)/2,h/9,w/4,h/9};

    //Nelson Edit:
    //change 4 to const int of number main menu buttons
    
    //load main menu buttons into stack
    for(int i=0; i < numberMainMenuButtons;i++){
        dstrect.y=80+i*h/9+i*45;
        temp1=gameItem(renderer,srcrect,dstrect,mainMenuButtonImagesAddresses[i]);
        mainMenuButtonStack.push_back(temp1);
    }
    //Nelson Edit:
    //
    //load char select menu buttons into stack
    for(int i=0; i< numberCharSelectMenuButtons; i++){
        dstrect.y=i*h/9+i*45+h/4;
        temp1=gameItem(renderer,srcrect,dstrect,charSelectMenuButtonImagesAddresses[i]);
        charSelectMenuButtonStack.push_back(temp1);
    }
    //Nelson Edit:
    //
    //load campaign select menu buttons into stack
    for(int i=0; i< numberMapSelectMenuButtons; i++){
        dstrect.y=i*h/9+i*45+h/4;
        temp1=gameItem(renderer,srcrect,dstrect,mapSelectMenuButtonImagesAddresses[i]);
        mapSelectMenuButtonStack.push_back(temp1);
    }
    //load campaign editor buttons into stack
    srcrect = {0,0,191,157};
    dstrect = {w-numberCampaignEditorButtons*2*defaultTileSize,h-defaultTileSize,defaultTileSize*2,defaultTileSize};
    for(int i=0; i< numberCampaignEditorButtons; i++){
        dstrect.x += i*2*defaultTileSize;
        temp1=gameItem(renderer,srcrect,dstrect,CampaignEditorButtons[i]);
        CampaignEditorButtonStack.push_back(temp1);
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
    
    //load "balls"
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
    
    switch(this->type){
        case type_mainMenu:
        {
            for(std::vector<gameItem>::iterator it = this->mainMenuButtonStack.begin() ; it != this->mainMenuButtonStack.end(); ++it){
                SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                //Update screen
            }
            break;
        }
        case type_mapeditor:
        {
            for(std::vector<mapUnit>::iterator it = this->gamemap.mapStack.begin() ; it != this->gamemap.mapStack.end(); ++it){
                SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                //Update screen
            }
            for(std::vector<gameItem>::iterator it = this->itemeditor_map.begin() ;
                it != this->itemeditor_map.end(); ++it){
                it->dstrect.y=defaultTileSize*this->gamemap.getNumberVerticalElements();
                SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                //Update screen
            }
            for(std::vector<gameItem>::iterator it = this->Campaign.gameitem.begin() ;
                it != this->Campaign.gameitem.end(); ++it){
                if(it->getMapNumber()==this->currentMapCounter){
                    SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                }
            }
            for(std::vector<gameItem>::iterator it = this->CampaignEditorButtonStack.begin() ;
                it != this->CampaignEditorButtonStack.end(); ++it){
                it->dstrect.y=defaultTileSize*this->gamemap.getNumberVerticalElements();
                SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                //Update screen
            }
            //SDL_RenderCopy(renderer, this->hero.texture,&this->hero.srcrect, &this->hero.dstrect);
            SDL_RenderCopy(renderer, this->testimage.texture,&this->testimage.srcrect, &this->testimage.dstrect);
            break;

        }
        case type_play:
        {
            //test
            TTF_Init();
            TTF_Font* Sans;
            Sans= TTF_OpenFont("OpenSans-Bold.ttf", 90); //this opens a font style and sets a size
            
            SDL_Color White = {255, 100, 100};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
            char const *pchar[2]={
                to_string(this->Campaign.hero.level).c_str(),
                to_string(this->Campaign.hero.hitpoint).c_str(),
            };
            
            this->Campaign.hero.InventoryPane->displayItems();
            
            SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, pchar[0], White);
            
            SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture
            
            SDL_Rect Message_rect; //create a rect
            Message_rect.x = 0;  //controls the rect's x coordinate
            Message_rect.y = 0; // controls the rect's y coordinte
            Message_rect.w = 100; // controls the width of the rect
            Message_rect.h = 100; // controls the height of the rect
            
            for(std::vector<mapUnit>::iterator it = this->Campaign.gameMapStack[this->currentMapCounter].mapStack.begin() ;
                it != this->Campaign.gameMapStack[this->currentMapCounter].mapStack.end(); ++it){
                SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                //Make end glow
                //Update screen
            }
            SDL_RenderCopy(renderer, glowingSquare.texture, &glowingSquare.srcrect, &glowingSquare.dstrect);
            for(std::vector<gameItem>::iterator it = this->Campaign.gameitem.begin() ;
                it != this->Campaign.gameitem.end(); ++it){
                if(it->getMapNumber()==currentMapCounter){
                    SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                }
                //Update screen
            }
            SDL_RenderCopy(renderer, this->Campaign.hero.texture,&this->Campaign.hero.srcrect, &this->Campaign.hero.dstrect);
            for(int i=0;i<3;i++){
                SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, pchar[i], White);
                SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
                Message_rect.x=Message_rect.x+i*100;
                SDL_RenderCopy(renderer,Message,NULL,&Message_rect);
            }
            }
            break;
        case type_exit:
            exit(0);
            break;
        case type_itemEditor:
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
            break;
        case type_characterEditor:
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
            break;
        case type_characterSelector:
            //add selector menu and input and stuff
            for(std::vector<gameItem>::iterator it = this->charSelectMenuButtonStack.begin() ; it != this->charSelectMenuButtonStack.end(); ++it){
                SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                //Update screen
            }
            break;
        case type_mapSelector:
            //add selector menu and input and stuff
            for(std::vector<gameItem>::iterator it = this->mapSelectMenuButtonStack.begin() ; it != this->mapSelectMenuButtonStack.end(); ++it){
                SDL_RenderCopy(renderer, it->texture,&it->srcrect, &it->dstrect);
                //Update screen
            }
            //transtion to game selector
            break;
        case type_characterFileLoad:
            //TODO
            break;
        default: std::cerr << "This code should never execute. In render()" << std::endl;
    }
}
void game::handleinput(){
    //Nelson Edit:
    //add ability to quit with exit button
    //if(e.type == SDL_QUIT){exit(0);}
    
    
    //Nelson Edit:
    //changed to switch statement, added some cases
    switch (this->type) {
        case type_mainMenu:
            mainMenu_gui_event();
            break;
        case type_mapeditor:
            ball();
            selection();
            mapEditorControlButtonsHandler();
            break;
        case type_play:
            Cmove();
            gamePlayHandler();
            break;
        case type_characterSelector:
            charSelectMenuGuiEvent();
            break;
        case type_mapSelector:
            mapSelectMenuGuiEvent();
            break;
            
        case type_characterEditor:
        {
            cout<<"Please enter file of you character";
            string temp;
            cin>>temp;
            cout<<"Please enter file inventory file";
            string temp2;
            cin>>temp2;
            cout<<"Please enter file of you backpack file";
            string temp3;
            cin>>temp3;
            this->Campaign.hero.iniCharacterFromFile(temp,temp2,temp3);
            this->Campaign.hero.characterEdit();
            this->type=type_mainMenu;
        }
            break;
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
                if(inside){
                    //Nelson Edit:
                    //change multiple ifs to switch and added cases
                    switch(i){
                        case 0: this->type = type_characterSelector ;break;
                        case 1:
                        {
                            cout<<"Please enter 1 to create a new map or please enter 2 to load a map:"<<endl;
                            int temp;
                            cin>>temp;
                            switch(temp){
                                case 1:
                                {
                                    cout<<"please enter width of the new map:"<<endl;
                                    int w;cin>>w;
                                    cout<<"please enter width of the new map:"<<endl;
                                    int h;cin>>h;
                                    this->gamemap=gameMap(w,h,renderer);
                                    this->type = type_mapeditor ;
                                    break;
                                }
                                case 2:
                                {
                                    cout<<"Please choose maps:"<<endl;
                                    string address;
                                    cin>>address;
                                    std::ifstream inputfile("resources/save_maps/"+address+".txt");
                                    int m,n;
                                    int a,b;
                                    inputfile>>m;
                                    inputfile>>n;
                                    a=m;
                                    b=n;
                                    gamemap=gameMap(a*defaultTileSize, b*defaultTileSize, renderer);
                                    inputfile>>m;
                                    inputfile>>n;
                                    a=m;
                                    b=n;
                                    gamemap.setStart(a);
                                    gamemap.setEnd(b);
                                    bool flag=true;
                                    while(flag){
                                        inputfile>>m>>n;
                                        a=m;b=n;
                                        //cout<<m<<endl;
                                        if(a==9999 or b==9999)
                                            break;
                                        else if(n==1)
                                            gamemap.mapStack[a].setOccupied();
                                    }
                                    while(inputfile.eof()){
                                        inputfile>>n;
                                        b=n;
                                        //cout<<b<<endl;
                                        SDL_Rect srcrectTEMP={0,0,600,600};
                                        gameItem testimage=gameItem(renderer, srcrectTEMP,
                                                                    gamemap.mapStack[b].dstrect, "resources/ball.png");
                                        testimage.setMapNumber(this->currentMapCounter);
                                        this->Campaign.gameitem.push_back(testimage);
                                    }
                                    this->type = type_mapeditor ;
                                    break;
                                }
                            }
                        }break;
                        case 2:
                        {
                            //ingameItems tempitems;
                            /*cout<<"Press 1 to create new item or press 2 to load and edit item"<<endl;
                            int tempint;
                            cin>>tempint;
                            switch(tempint){
                                case 1:
                                    tempitems.createItemCViaConsole();
                                    break;
                                case 2:
                                    tempitems.editItemCViaConsole();
                                    break;
                            }*/
                            ItemMenu();
                            this->type = type_mainMenu;
                        }
                            break;
                        case 3: this->type = type_characterEditor ;break;
                        case 4: this->type = type_exit ;break;
                        default: std::cerr << "Error selecting button." << std::endl; break;
                    }
                }
                break;
            }
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
                //TODO: load the default character;
            {
                cout<<"Please enter the name of you character";
                string temp;
                cin>>temp;
                this->Campaign.hero.setName(temp);
                std::ofstream outfile ("resources/save_character/"+temp+".txt");
                outfile<<temp<<endl;
                outfile<<this->Campaign.hero.hitpoint<<endl;
                outfile<<this->Campaign.hero.level<<endl;
                outfile<<this->Campaign.hero.abilityScore[0]<<endl;
                outfile<<this->Campaign.hero.abilityScore[1]<<endl;
                outfile<<this->Campaign.hero.abilityScore[2]<<endl;
                outfile<<this->Campaign.hero.abilityScore[3]<<endl;
                outfile<<this->Campaign.hero.abilityScore[4]<<endl;
                outfile<<this->Campaign.hero.abilityScore[5]<<endl;
                outfile<<this->Campaign.hero.abilityScore[6]<<endl;
                outfile.close();
                break;
            }
            case 1:{
                //TODO get path to character from file and load that
                cout<<"Please enter file of you character";
                string temp;
                cin>>temp;
                cout<<"Please enter file inventory file";
                string temp2;
                cin>>temp2;
                cout<<"Please enter file of you backpack file";
                string temp3;
                cin>>temp3;
                this->Campaign.hero.iniCharacterFromFile(temp,temp2,temp3);
                break;
            }
            default: std::cerr << "Error selecting button." << std::endl; break;
                
        }
        this->type = type_mapSelector;
    }
    SDL_FlushEvents(1025,1026); //Fixes specific bug which would cause things to trigger twice.
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
            case 1:
            {
                cout <<"Please enter the name of new campaign";
                this->Campaign=campaign(renderer);
                string name;
                cin>>name;
                this->Campaign.setName(name);
                cout<<"enter 1 to create a new map or enter 2 to load map"<<endl;
                int flag;
                cin>>flag;
                switch (flag) {
                    case 1:
                    {
                        cout<<"Please enter the width of the new Map"<<endl;
                        int tempw=0;
                        cin>>tempw;
                        cout<<"Please enter the height of the new Map"<<endl;
                        int temph=0;
                        cin>>temph;
                        this->gamemap=gameMap(tempw,temph,this->renderer);
                        this->type = type_mapeditor;
                        break;
                    }
                    case 2:{
                        {
                            cout<<"Please choose maps:"<<endl;
                            string address;
                            cin>>address;
                            std::ifstream inputfile("resources/save_maps/"+address+".txt");
                            int m,n;
                            int a,b;
                            inputfile>>m;
                            inputfile>>n;
                            a=m;
                            b=n;
                            gamemap=gameMap(a*defaultTileSize, b*defaultTileSize, renderer);
                            inputfile>>m;
                            inputfile>>n;
                            a=m;
                            b=n;
                            gamemap.setStart(a);
                            gamemap.setEnd(b);
                            bool flag=true;
                            while(flag){
                                inputfile>>m>>n;
                                a=m;b=n;
                                //cout<<m<<endl;
                                if(a==9999)
                                    break;
                                else if(n==1)
                                    gamemap.mapStack[a].setOccupied();
                            }
                            this->Campaign.gameMapStack.push_back(gamemap);
                            while(!inputfile.eof()){
                                inputfile>>n;
                                b=n;
                                //cout<<b<<endl;
                                SDL_Rect srcrectTEMP={0,0,600,600};
                                gameItem testimage=gameItem(renderer, srcrectTEMP,
                                                            gamemap.mapStack[b].dstrect, "resources/ball.png");
                                testimage.setMapNumber(this->currentMapCounter);
                                this->Campaign.gameitem.push_back(testimage);
                            }
                            this->Campaign.hero.dstrect=this->Campaign.gameMapStack[0].mapStack[this->Campaign.gameMapStack[0].startindex].dstrect;
                            this->type = type_mapeditor ;
                            break;
                            
                        }

                    }
                        break;
                    default:
                        break;
                }
              }
                break;
            case 0:
                {
                    //start Map load code here:
                    cout <<"Please choose the campaign";
                    this->Campaign=campaign(renderer);
                    string name;
                    cin>>name;
                    this->Campaign.setName(name);
                    
                    std::ifstream inputfile ("resources/campaign/"+this->Campaign.getName()+".txt");
                    std::string line;
                    while (std::getline(inputfile, line))
                    {
                        cout<<line;
                        this->Campaign.mapNameStack.push_back(line);
                    }
                    inputfile.close();
                    for(int i=0;i<this->Campaign.mapNameStack.size();i++){
                        inputfile =std::ifstream("resources/save_maps/"+this->Campaign.mapNameStack[i]+".txt");
                        int m,n;
                        int a,b;
                        inputfile>>m;
                        inputfile>>n;
                        a=m;
                        b=n;
                        gamemap=gameMap(a*defaultTileSize, b*defaultTileSize, renderer);
                        inputfile>>m;
                        a=m;
                        gamemap.setStart(a);
                        gamemap.startindex=a;
                        // first map
                        if(this->currentMapCounter==0){
                            this->Campaign.hero.dstrect=gamemap.mapStack[a].dstrect;
                        }
                        inputfile>>n;
                        b=n;
                        // first map
                        if(this->currentMapCounter==0){
                            glowingSquare.dstrect=gamemap.mapStack[b].dstrect;
                        }
                        gamemap.setEnd(b);
                        gamemap.endindex=b;
                        bool flag=true;
                        while(flag){
                            inputfile>>m>>n;
                            a=m;b=n;
                            //cout<<m<<endl;
                            if(a==9999)
                                break;
                            else if(n==1)
                            {
                             gamemap.mapStack[a].setOccupied();   
                            }
                        }
                        if(!gamemap.mapValidateInit())
                        {
                          cout<<"check the map";
                          this->type=type_mainMenu;
                            exit(0);
                          break;
                        }
                        this->Campaign.gameMapStack.push_back(gamemap);
                        while(!inputfile.eof()){
                            inputfile>>n;
                            b=n;
                            cout<<"At "<<b<<"there is a item"<<endl;
                            SDL_Rect srcrectTEMP={0,0,600,600};
                            gameItem testimage=gameItem(renderer, srcrectTEMP,
                                                        gamemap.mapStack[b].dstrect, "resources/ball.png");
                            testimage.setMapNumber(this->currentMapCounter);
                            this->Campaign.gameitem.push_back(testimage);
                        }
                        this->currentMapCounter++;
                    }
                    this->type = type_play;
                    this->currentMapCounter=0;
                    break;
                }
            default: std::cerr << "Error selecting button." << std::endl; break;
        }
    }
    SDL_FlushEvent(1026); //Fixes specific bug which would cause things to trigger twice.
}
void game::mapEditorControlButtonsHandler(){
    SDL_WaitEvent(&e);
    bool inside = false;
    int x, y;
    x = e.motion.x;
    y = e.motion.y;
    
    int i = 0;
    if(e.button.button == SDL_BUTTON_LEFT && e.button.state == SDL_RELEASED){
        for(i = 0; i <this->CampaignEditorButtonStack.size();i++){
            inside = checkifinside(x,y, CampaignEditorButtonStack[i].dstrect);
            if(inside){
                break;
            }
        }
        
    }
    if(inside){
        switch(i){
            case 0:
            {
                cout<<"Please enter the name of the map:";
                string temp;
                cin>>temp;
                std::ofstream outfile ("resources/save_maps/"+temp+".txt");
                
                cout<<"Please enter the start point of the map";
                int temppoint;
                cin >> temppoint;
                this->gamemap.setStart(temppoint);
                this->gamemap.startindex=temppoint;
                cout<<"Please enter the end point of the map";
                cin >> temppoint;
                this->gamemap.setEnd(temppoint);
                this->gamemap.endindex=temppoint;
                if(outfile.is_open()){
                    outfile<<this->gamemap.getNumberHorizontalElements()<<" "<<this->gamemap.getNumberVerticalElements()<<endl;
                    for(int i=0;i<this->gamemap.mapStack.size();i++){
                        if(this->gamemap.mapStack[i].STATE==MAP_START)
                            outfile<<i<<endl;
                    }
                    for(int i=0;i<this->gamemap.mapStack.size();i++){
                        if(this->gamemap.mapStack[i].STATE==Map_END)
                            outfile<<i<<endl;
                    }
                    for(int i=0;i<this->gamemap.mapStack.size();i++){
                        outfile<<i<<" "<<
                        this->gamemap.mapStack[i].isOccupied()<<endl;
                    }
                    outfile<<"9999"<<" "<<"9999"<<endl;
                    for(int j=0;j<this->Campaign.gameitem.size();j++){
                        if(this->Campaign.gameitem[j].getMapNumber()==this->currentMapCounter)
                            outfile<<this->Campaign.gameitem[j].getMapIndex()<<endl;
                    }
                }
                outfile.close();
                
                this->Campaign.mapNameStack.push_back(temp);
                this->Campaign.gameMapStack.push_back(this->gamemap);
                this->numberofMap=this->Campaign.gameMapStack.size();
                
                std::ofstream outfile2 ("resources/campaign/"+this->Campaign.getName()+".txt");
                if(outfile2.is_open()){
                    for(int i=0;i<this->Campaign.mapNameStack.size();i++){
                        outfile2<<this->Campaign.mapNameStack[i]<<endl;
                    }
                }
                outfile2.close();
                this->currentMapCounter=0;
                this->Campaign=campaign(renderer);
                this->type=type_mainMenu;

            }
                break;
            case 1:
            {
                int w=0;
                int h=0;
                
                cout<<"Please enter the name of the map:";
                string temp;
                cin>>temp;
                std::ofstream outfile ("resources/save_maps/"+temp+".txt");
                
                cout<<"Please enter the start point of the map";
                int temppoint;
                cin >> temppoint;
                this->gamemap.setStart(temppoint);
                this->gamemap.startindex=temppoint;
                cout<<"Please enter the end point of the map";
                cin >> temppoint;
                this->gamemap.setEnd(temppoint);
                this->gamemap.endindex=temppoint;
                if(outfile.is_open()){
                    outfile<<this->gamemap.getNumberHorizontalElements()<<" "<<this->gamemap.getNumberVerticalElements()<<endl;
                    for(int i=0;i<this->gamemap.mapStack.size();i++){
                        if(this->gamemap.mapStack[i].STATE==MAP_START)
                            outfile<<i<<endl;
                    }
                    for(int i=0;i<this->gamemap.mapStack.size();i++){
                        if(this->gamemap.mapStack[i].STATE==Map_END)
                            outfile<<i<<endl;
                    }
                    for(int i=0;i<this->gamemap.mapStack.size();i++){
                        outfile<<i<<" "<<
                        this->gamemap.mapStack[i].isOccupied()<<endl;
                    }
                    outfile<<"9999"<<" "<<"9999"<<endl;
                    for(int j=0;j<this->Campaign.gameitem.size();j++){
                        if(this->Campaign.gameitem[j].getMapNumber()==this->currentMapCounter)
                            outfile<<this->Campaign.gameitem[j].getMapIndex()<<endl;
                    }
                }
                outfile.close();
                
                this->Campaign.mapNameStack.push_back(temp);
                this->Campaign.gameMapStack.push_back(this->gamemap);
                this->numberofMap=this->Campaign.gameMapStack.size();
                
                cout<<"Please enter the width new map";
                cin>>w;
                cout<<"Please enter the height new map";
                cin>>h;
                if(w >defaultTileSize and h>defaultTileSize){
                    this->gamemap=gameMap(w,h,renderer);
                }
                this->currentMapCounter++;
                this->testimage.setImage(renderer,"");
            }
                break;
            default: std::cerr << "Error selecting button." << std::endl; break;
                
        }
    }
    SDL_FlushEvents(1025,1026); //Fixes specific bug which would cause things to trigger twice.
}
void game::gamePlayHandler(){
    switch(e.key.keysym.sym){
        case SDLK_0:
        {
            if(e.type == SDL_KEYDOWN){
                this->Campaign.hero.equip();
            }
            break;
        }
        case SDLK_1:
        {
            if(e.type == SDL_KEYDOWN){
                this->Campaign.hero.removeItem();
            }
            break;
        }
    }
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
                if(this->Campaign.hero.dstrect.y > 0){
                    withinMapBounds = true;
                }
                
                //check if next block is occupied
                bool nextIsNotOccupied = false;
                SDL_Rect nextRect = this->Campaign.hero.dstrect; nextRect.y -= defaultTileSize;
                if(! this->Campaign.gameMapStack[this->currentMapCounter].checkifOccpuied(nextRect) ){
                    nextIsNotOccupied = true;
                }
                
                if(withinMapBounds && nextIsNotOccupied){
                    
                    //set next block to occupied (by hero)
                    this->gamemap.setOccpuied(nextRect);
                    //set current block to unoccupied
                    this->gamemap.setOccupied(this->Campaign.hero.dstrect, false);
                    
                    //move hero
                    this->Campaign.hero.dstrect.y -= defaultTileSize;
                }
                
                //set character's facing direction
                this->Campaign.hero.Directioncounter = 3;
            }
            break;
        case SDLK_DOWN: //execute code in next case
        case SDLK_s:
            if(e.type == SDL_KEYDOWN){
                //check if within map bounds
                bool withinMapBounds = false;
                if(this->Campaign.hero.dstrect.y < (this->Campaign.gameMapStack[this->currentMapCounter].getNumberVerticalElements()-1)*defaultTileSize){
                    withinMapBounds = true;
                }
                
                //check if next block is occupied
                bool nextIsNotOccupied = false;
                SDL_Rect nextRect = this->Campaign.hero.dstrect; nextRect.y += defaultTileSize;
                if(! this->Campaign.gameMapStack[this->currentMapCounter].checkifOccpuied(nextRect) ){
                    nextIsNotOccupied = true;
                }
                
                if(withinMapBounds && nextIsNotOccupied){
                    
                    //set next block to occupied (by hero)
                    this->gamemap.setOccpuied(nextRect);
                    //set current block to unoccupied
                    this->gamemap.setOccupied(this->Campaign.hero.dstrect, false);
                    
                    //move hero
                    this->Campaign.hero.dstrect.y += defaultTileSize;
                }
                
                //set character's facing direction
                this->Campaign.hero.Directioncounter = 2;
            }
            break;
        case SDLK_LEFT: //execute code in next case
        case SDLK_a:
            if(e.type == SDL_KEYDOWN){
                
                //check if within map bounds
                bool withinMapBounds = false;
                if(this->Campaign.hero.dstrect.x > 0){
                    withinMapBounds = true;
                }
                
                //check if next block is occupied
                bool nextIsNotOccupied = false;
                SDL_Rect nextRect = this->Campaign.hero.dstrect; nextRect.x -= defaultTileSize;
                if(! this->Campaign.gameMapStack[this->currentMapCounter].checkifOccpuied(nextRect) ){
                    nextIsNotOccupied = true;
                }
                
                if(withinMapBounds && nextIsNotOccupied){
                    
                    //set next block to occupied (by hero)
                    this->gamemap.setOccpuied(nextRect);
                    //set current block to unoccupied
                    this->gamemap.setOccupied(this->Campaign.hero.dstrect, false);
                    
                    //move hero
                    this->Campaign.hero.dstrect.x -= defaultTileSize;
                }
                
                //set character's facing direction
                this->Campaign.hero.Directioncounter = 0;
            }
            break;
        case SDLK_RIGHT: //execute code in next case
        case SDLK_d:
            if(e.type == SDL_KEYDOWN){
                
                //check if within map bounds
                bool withinMapBounds = false;
                if(this->Campaign.hero.dstrect.x < (this->Campaign.gameMapStack[this->currentMapCounter].getNumberHorizontalElements()-1)*defaultTileSize){
                    withinMapBounds = true;
                }
                
                //check if next block is occupied
                bool nextIsNotOccupied = false;
                SDL_Rect nextRect = this->Campaign.hero.dstrect; nextRect.x += defaultTileSize;
                if(! this->Campaign.gameMapStack[this->currentMapCounter].checkifOccpuied(nextRect) ){
                    nextIsNotOccupied = true;
                }
                
                if(withinMapBounds && nextIsNotOccupied){
                    
                    //set next block to occupied (by hero)
                    this->gamemap.setOccpuied(nextRect);
                    //set current block to unoccupied
                    this->gamemap.setOccupied(this->Campaign.hero.dstrect, false);
                    
                    //move hero
                    this->Campaign.hero.dstrect.x += defaultTileSize;
                }
                
                //set character's facing direction
                this->Campaign.hero.Directioncounter = 1;
            }
            break;
    }
    //update move counter if a button was pressed
    if(e.type == SDL_KEYDOWN){
        this->Campaign.hero.movecounter = (this->Campaign.hero.movecounter + 1) % 4;
    }
    
    //select appropriate sprite
    this->Campaign.hero.srcrect.x=this->Campaign.hero.movecounter*this->Campaign.hero.movestep;
    this->Campaign.hero.srcrect.y=this->Campaign.hero.Directioncounter*this->Campaign.hero.movestep;
    
    //if reached end of map
    if(this->Campaign.hero.dstrect.x == this->glowingSquare.dstrect.x &&
       this->Campaign.hero.dstrect.y == this->glowingSquare.dstrect.y){
        this->currentMapCounter++;
        
        if(this->currentMapCounter==this->Campaign.gameMapStack.size()){
            this->type=type_mainMenu;
        }
        else{
            this->Campaign.hero.dstrect=this->Campaign.gameMapStack[this->currentMapCounter].mapStack[this->Campaign.gameMapStack[this->currentMapCounter].startindex].dstrect;
            this->glowingSquare.dstrect=this->Campaign.gameMapStack[this->currentMapCounter].mapStack[this->Campaign.gameMapStack[this->currentMapCounter].endindex].dstrect;
            this->Campaign.hero.level++;
            }
    }
}


void game::ball(){
    int flag=selection();
    SDL_WaitEvent(&e);
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);
    if(flag!=-1&&select){
        x=x/defaultTileSize*defaultTileSize;
        y=y/defaultTileSize*defaultTileSize;
        if(y>defaultTileSize*(this->gamemap.getNumberVerticalElements()-1))
            y=defaultTileSize*(this->gamemap.getNumberVerticalElements()-1);
        this->testimage.dstrect.x=x;
        this->testimage.dstrect.y=y;
        this->testimage.setImage(this->renderer, address2[flag]);
        if(e.button.button == SDL_BUTTON_RIGHT)
        {
            flag=-1;
            select=false;
            this->testimage.setMapNumber(this->currentMapCounter);
            this->testimage.setMapIndex(this->gamemap.setOccpuied(this->testimage.dstrect));
            this->Campaign.gameitem.push_back(this->testimage);
        }
    }
    else if(select&&flag==-1){
        x=x/defaultTileSize*defaultTileSize;
        y=y/defaultTileSize*defaultTileSize;
        if(y>defaultTileSize*(this->gamemap.getNumberVerticalElements()-1))
            y=defaultTileSize*(this->gamemap.getNumberVerticalElements()-1);
        this->testimage.dstrect.x=x;
        this->testimage.dstrect.y=y;
        if(e.button.button == SDL_BUTTON_RIGHT)
        {
            if(!this->gamemap.checkifOccpuied(this->testimage.dstrect)){
                select=false;
                this->testimage.setMapNumber(this->currentMapCounter);
                this->testimage.setMapIndex(this->gamemap.setOccpuied(this->testimage.dstrect));
                this->gamemap.setOccpuied(this->testimage.dstrect);
                this->Campaign.gameitem.push_back(this->testimage);
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
    if(y > defaultTileSize*(this->gamemap.getNumberVerticalElements()-1) && (e.button.button == SDL_BUTTON_LEFT) ) //500
    {
        //For tracing: cout<<x/defaultTileSize;
        select = true;
        return x/defaultTileSize;
    }
    else
        return -1;
}
