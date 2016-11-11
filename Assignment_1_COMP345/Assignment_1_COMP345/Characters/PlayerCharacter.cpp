/**
 *Wan Lan He - 29469419 - part 1 - part 2
 * Project Dungeons and Dragons
 * Create a character, add Observer function
 * PlayerCharacter.cpp 
 */
  
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include "PlayerCharacter.h"
#include "Observer.h"
#include "Subject.h"
  
using namespace std;

  
PlayerCharacter::PlayerCharacter(){
    currentHitPoints=10; 
}
 
namespace {
    PlayerCharacter * pc;
}
  
//! Implementation of the verification of a newly created Character
//! @return bool value, true of the character is valid (stats should be in the 3-18 range for a new character), false if invalid. 
bool PlayerCharacter:: validateNewCharacter(){
    for (int i = 0; i <= 5; i++)
    if (abilityScores[i]<3 || abilityScores[i]>18)
        return false;
    return true;
        notify();
}

int PlayerCharacter::setAbilityScore() {
    int abilityScores[6];
    for(int i=0; i<6; i++){
        abilityScores[i]=rollStats();
    }
    pc->notify();
}

//getters for the ability scores
int PlayerCharacter::getStrength() const {
    return str;
    pc->notify();
}
  
int PlayerCharacter::getDexterity() const {
    return dex;
    pc->notify();
}
  
int PlayerCharacter::getConstitution() const {
    return cons;
    pc->notify();
}
  
int PlayerCharacter::getIntelligence() const {
    return intel;
    pc->notify();
}
  
int PlayerCharacter::getWisdom() const {
    return wis;
    pc->notify();
}
  
int PlayerCharacter::getCharisma() const {
    return chari;
    pc->notify();
}
 

//setters
void PlayerCharacter::setCharisma(int chari){
    this->chari=chari;
}

void PlayerCharacter::setConstitution(int cons){
    this->cons=cons;
}

void PlayerCharacter::setDexterity(int dex){
    this->dex=dex;
}

void PlayerCharacter::setIntelligence(int intel){
    this->intel=intel;
}

void PlayerCharacter::setStrength(int str){
    this->str=str;
}

void PlayerCharacter::setWisdom(int wis){
    this->wis=wis;
}



int PlayerCharacter::getCurrentHitPoints(){
    return currentHitPoints;
}
  
//!Implementation of current hit points minus the damage
//@return int new value for the current hit points
void PlayerCharacter::hit(int damage){
    currentHitPoints = currentHitPoints-damage; 
    pc->notify();
}
  
  
//!Implementation to get the ability modifier
//@return int value ability score modifier, take one int parameter
int PlayerCharacter::getAbilityMod(int abilityScore) {
    return floor((abilityScore/2) - 5);
    notify();
}
  
//!Implementation of the attack bonus based on the level and the strength modifier
//@return int value attack bonus
int PlayerCharacter::attackBonus() {
    int attackBonus;
    attackBonus = level + getAbilityMod(getStrength());
    return attackBonus;
    notify();
}
  
//!Implementation of the hit points based on the level and the constitution modifier
//@return int value for the hit points
int PlayerCharacter::getHitPoints(){
    int hitPoints;
    hitPoints = level + getAbilityMod(getConstitution());
    return hitPoints;
    notify();
}
  
//!Implementation of the armor based the dexterity modifier
//@return int value for the armor
int PlayerCharacter::armorClass(){
    int armorClass;
    armorClass = getAbilityMod(getDexterity());
    return armorClass;
    notify();
}
  
//!   
int PlayerCharacter::genRandNumb(int min, int max){
    return rand() % (max - min + 1) + min;
}

int PlayerCharacter::genRandNumb(int numb){
    return rand() % (numb)+1;
}

int PlayerCharacter::rollStats(){
    int dropLowest = genRandNumb(6);
    int sum = dropLowest;
    int next;
    
    for(int i=0; i<=3; i++){
        if((next=genRandNumb(6)) < dropLowest){
            dropLowest = next;
        }
        sum=sum+next;
    }
    return sum-dropLowest;
}
  
void PlayerCharacter::notify(){
        cout <<"\nCharacter's proprities changed";
    }
  
void PlayerCharacter::characterCreate(){
    genRandNumb(3, 18);  
    getHitPoints();
    attackBonus();
    armorClass();
    notify();
     
} 
 
void PlayerCharacter::equip(string equip){
    Item items;
    cout << "Character equipped with items" << endl;
    if(equip=="armor"){
        items.armor=equip;
        cout << "ARMOR" << endl;
    }else if (equip=="belt"){
        items.belt=equip;
        cout << "BELT" << endl;
    }else if (equip=="boots"){
        items.boots=equip;
        cout << "BOOTS" << endl;
    }else if (equip=="helmet"){
        items.helmet=equip;
        cout << "HELMET" << endl;
    }else if (equip=="ring"){
        items.ring=equip;
        cout << "RING" << endl;
    }else if (equip=="shield"){
        items.shield=equip;
        cout << "SHIELD" << endl;
    }else if (equip=="weapon"){
        items.weapon=equip;
        cout << "WEAPON" << endl;
    }
    notify(); 
}
 
void PlayerCharacter::characterData(){
    string charName;
    string charType;
    int level;
    string item;
      
    cout << "Welcome to Dungeon and Dragons" << endl;
    cout << "It 's time to create a character" << endl;
      
    cout << "Enter your character's name: " << endl;
    cin >> charName;
      
    cout << "Enter your character's class: " << endl;
    cin >> charType;
      
    cout << "Enter your level" << endl;
    cin >> level;
      
    cout << "Character can wear any items listed: armor, belt, boots, helmet, ring, shield, weapon"<< endl;
    cin >> item;
    pc->equip(item);
    
    cout << "Level" << getLevel() << endl;
    cout << "Strength" << getStrength() << endl;
    cout << "Dexterity" << getDexterity() << endl;
    cout << "Constitution" << getConstitution() << endl;
    cout << "Intelligence" << getIntelligence() << endl;
    cout << "Wisdom" << getWisdom() << endl;
    cout << "Charisma" << getCharisma() <<endl;
    cout << "HitPoints" << getHitPoints() << endl;
    
    notify();
}

