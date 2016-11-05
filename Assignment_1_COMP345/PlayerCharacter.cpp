/**
 *Wan Lan He - 29469419 - part 1
 * Project Dungeons and Dragons
 * Create a fighter character
 * PlayerCharacter.cpp 
 */
 
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "PlayerCharacter.h"
#include "Observer.h"
#include "Subject.h"
 
using namespace std;
 
PlayerCharacter::PlayerCharacter(){
    currentHitPoints=10;  
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
 
int PlayerCharacter::getStrength() const {
    return abilityScores[0];
}
 
int PlayerCharacter::getDexterity() const {
    return abilityScores[1];
}
 
int PlayerCharacter::getConstitution() const {
    return abilityScores[2];
}
 
int PlayerCharacter::getIntelligence() const {
    return abilityScores[3];
}
 
int PlayerCharacter::getWisdom() const {
    return abilityScores[4];
}
 
int PlayerCharacter::getCharisma() const {
    return abilityScores[5];
}
 
int PlayerCharacter::getCurrentHitPoints(){
    return currentHitPoints;
}
 
//!Implementation of current hit points minus the damage
//@return int new value for the current hit points
void PlayerCharacter::hit(int damage){
    currentHitPoints = currentHitPoints-damage; 
    notify();
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
 
 
int PlayerCharacter::genRandNumb(int min, int max){
    return rand() % (max - min + 1) + min;
}
 
 
void PlayerCharacter::notify(){
        cout <<"\nCharacter's proprities changed";
    }
 
 
//display character's info
void PlayerCharacter::characterData(){
    string charName;
    string charType;
    int level;
    int item;
     
    cout << "Welcome to Dungeon and Dragons" << endl;
    cout << "It 's time to create a character" << endl;
     
    cout << "Enter your character's name: " << endl;
    cin >> charName;
     
    cout << "Enter your character's class: " << endl;
    cin >> charType;
     
    cout << "Enter your level" << endl;
    cin >> level;
     
    cout << "Your character must wear at least one item listed: " << endl;
    cout << "1.armor - 2.shield - 3.weapon - 4.boots - 5.rings - 6.helmet" << endl;
    cin >> item;
    switch(item){
        case 1: cout << "Armor"; break;
        case 2: cout << "Shield"; break;
        case 3: cout << "Weapon"; break;
        case 4: cout << "Boots"; break;
        case 5: cout << "Rings"; break;
        case 6: cout << "Helmet"; break;
        default: break;
    }
    notify();
}