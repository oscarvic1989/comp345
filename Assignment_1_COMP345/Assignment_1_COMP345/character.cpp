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
