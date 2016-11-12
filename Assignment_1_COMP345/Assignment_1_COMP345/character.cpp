//
//  character.cpp
//  Assignment_1_COMP345
//
//  Created by oscar on 2016-11-02.
//  Copyright © 2016 oscar. All rights reserved.
//

#include "character.hpp"

character::character(){
    
}
void character::characterEdit(){
    bool flag=true;
    while(flag){
        cout<<"Please choose which value you wish to change:"<<endl;
        cout<<"<0>Name"<<endl;
        cout<<"<1>Hitpoint"<<endl;
        cout<<"<2>level"<<endl;
        cout<<"<3>Strength"<<endl;
        cout<<"<4>Dexerity"<<endl;
        cout<<"<5>Constitution"<<endl;
        cout<<"<6>Intelligence"<<endl;
        cout<<"<7>Wisdon"<<endl;
        cout<<"<8>Charisma"<<endl;
        int temppointer;
        cin>>temppointer;
        switch (temppointer) {
            case 0:
                cout<<"Please enter new name:"<<endl;
                cin>>this->name;
                cout<<"New name is :"<<this->name<<endl;
                break;
            case 1:
                cout<<"Please enter value of hitpoint:"<<endl;
                cin>>this->hitpoint;
                cout<<"New value is :"<<this->hitpoint<<endl;
                break;
            case 2:
                cout<<"Please enter new level:"<<endl;
                cin>>this->level;
                cout<<"New value is :"<<this->level<<endl;
                break;
            case 3:
                cout<<"Please enter new value:"<<endl;
                cin>>this->abilityScore[0];
                cout<<"New value is :"<<this->level<<endl;
                break;
            case 4:
                cout<<"Please enter new value:"<<endl;
                cin>>this->abilityScore[1];
                cout<<"New value is :"<<this->level<<endl;
                break;
            case 5:
                cout<<"Please enter new value:"<<endl;
                cin>>this->abilityScore[2];
                cout<<"New value is :"<<this->level<<endl;
                break;
            case 6:
                cout<<"Please enter new value:"<<endl;
                cin>>this->abilityScore[3];
                cout<<"New value is :"<<this->level<<endl;
                break;
            case 7:
                cout<<"Please enter new value:"<<endl;
                cin>>this->abilityScore[4];
                cout<<"New value is :"<<this->level<<endl;
                break;
            case 8:
                cout<<"Please enter new value:"<<endl;
                cin>>this->abilityScore[5];
                cout<<"New value is :"<<this->level<<endl;
                break;
            default:
                break;
        }
        cout<<"Enter 1 to continue , 2 to save and exit"<<endl;
        int hahaha;
        cin>>hahaha;
        if(hahaha==2)
            flag=false;
    }
    cout<<"Saving..."<<endl;
    std::ofstream outfile ("resources/save_character/"+this->name+".txt");
    outfile<<this->name<<endl;
    outfile<<this->hitpoint<<endl;
    outfile<<this->level<<endl;
    outfile<<this->abilityScore[0]<<endl;
    outfile<<this->abilityScore[1]<<endl;
    outfile<<this->abilityScore[2]<<endl;
    outfile<<this->abilityScore[3]<<endl;
    outfile<<this->abilityScore[4]<<endl;
    outfile<<this->abilityScore[5]<<endl;
    outfile<<this->abilityScore[6]<<endl;
    cout<<"Done"<<endl;
    outfile.close();
}
character::character(SDL_Renderer *renderer){
    this->dstrect={0,0,50,50};
    this->srcrect={movecounter*movestep,Directioncounter*movestep,128,128};
    this->image = IMG_Load("resources/hero.png");
    this->texture=SDL_CreateTextureFromSurface(renderer, this->image);
    loadItemContainer("worn.txt", *InventoryPane);
    loadItemContainer("backpack.txt", *backPack);
    iniAblility();
}
void character::iniAblility(){
    for(int i=0;i<InventoryPane->getItems().size();i++){
        for(int j=0;j<InventoryPane->getItems()[i].getEnhances().size();j++)
        {
            switch (InventoryPane->getItems()[i].getEnhances()[j].getType()) {
                case STRENGTH:
                    abilityScore[0]+=InventoryPane->getItems()[i].getEnhances()[j].getBonus();
                    break;
                case DEXTERITY:
                    abilityScore[1]+=InventoryPane->getItems()[i].getEnhances()[j].getBonus();
                    break;
                case CONSTITUTION:
                    abilityScore[2]+=InventoryPane->getItems()[i].getEnhances()[j].getBonus();
                    break;
                case INTELLIGENCE:
                    abilityScore[3]+=InventoryPane->getItems()[i].getEnhances()[j].getBonus();
                    break;
                case WISDOM:
                    abilityScore[4]+=InventoryPane->getItems()[i].getEnhances()[j].getBonus();
                    break;
                case CHARISMA:
                    abilityScore[5]+=InventoryPane->getItems()[i].getEnhances()[j].getBonus();
                    break;
                case ARMOR_CLASS:
                    abilityScore[0]+=InventoryPane->getItems()[i].getEnhances()[j].getBonus();
                    break;
                case ATTACK_BONUS:
                    hitpoint+=InventoryPane->getItems()[i].getEnhances()[j].getBonus();
                    break;
                case DAMAGE_BONUS:
                    hitpoint+=InventoryPane->getItems()[i].getEnhances()[j].getBonus();
                    break;
                default:
                    break;
            }
        }
    }
}
void character::setName(string a){
    this->name=a;
}
void character::equip(){
    cout<<"Current InventoryPane :"<<endl;
    displayIC(*this->InventoryPane);
    cout<<"Please choose which you wish to equip?"<<endl;
    displayIC(*this->backPack);
    int temppointer;
    cin>>temppointer;
    Item tempitem=backPack->getItems()[temppointer];
    Item tempitem2=this->InventoryPane->Equip(tempitem);
    backPack->getItems()[temppointer].setName(tempitem2.getName());
    backPack->getItems()[temppointer].setEnhances(tempitem2.getEnhances());
    cout<<"Now InventoryPane :"<<endl;
    displayIC(*this->InventoryPane);
    cout<<"Now backpack"<<endl;
    displayIC(*this->backPack);
    saveIC("worn.txt", *this->InventoryPane);
    saveIC("backpack.txt", *this->backPack);
    iniAblility();
}
void character::iniCharacterFromFile(string name,string b,string c){
    std::ifstream inputfile ("resources/campaign/"+name+".txt");
    string line;
    inputfile>>line;
    this->name=line;
    inputfile>>this->hitpoint>>this->level>>this->abilityScore[0]>>this->abilityScore[1]
    >>this->abilityScore[2]>>this->abilityScore[3]>>this->abilityScore[4]>>this->abilityScore[5];
    inputfile.close();
    loadItemContainer(b, *InventoryPane);
    loadItemContainer(c, *backPack);
    iniAblility();
};
void character::removeItem(){
    cout<<"Press 1 to remove item from backpack; Press 2 to remove item from InventoryPane:"<<endl;
    int temp;
    cin>>temp;
    switch(temp){
        case 1:
            cout<<"Please choose which you wish to remove?"<<endl;
            displayIC(*this->backPack);
            cin>>temp;
            backPack->getItems().erase(backPack->getItems().begin() + temp);
            cout<<"Now backpack "<<endl;
            displayIC(*this->backPack);
            saveIC("backpack.txt", *this->backPack);
            break;
        case 2:
            cout<<"Please choose which you wish to remove?"<<endl;
            displayIC(*this->InventoryPane);
            cin>>temp;
            InventoryPane->getItems()[temp].setName("N/A");
            
            for(int i=0;i<InventoryPane->getItems()[temp].getEnhances().size();i++){
                InventoryPane->getItems()[temp].getEnhances()[i].setBonus(0);
            }
            cout<<"Now InventoryPane "<<endl;
            displayIC(*this->InventoryPane);
            saveIC("worn.txt", *this->InventoryPane);
            displayIC(*this->InventoryPane);
            iniAblility();
            break;
        default:
            break;
    }
};
