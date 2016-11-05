/**
 *Wan Lan He - 29469419 - part 1
 * Project Dungeons and Dragons
 * Create a fighter character
 * PlayerCharacter.h 
 */
 
#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include <iostream>
#include <list>
#include "Observer.h"
#include "Subject.h"
using namespace std;
 
class PlayerCharacter: public Subject{ 
     
    enum Item {
    armor,
    shield,
    weapon,
    boots,
    rings,
    helmet,
    };
     
public:
    PlayerCharacter(); //default constructor
    //~PlayerCharacter(); //deconstructor
    PlayerCharacter(string charName, string charType, int level);
    bool validateNewCharacter();
    void characterData();
    
     
    string getCharName();
    string getCharType() const;
    int getLevel() const;
     
    //getters for ability scores
    int getStrength() const;
    int getDexterity() const;
    int getConstitution() const;
    int getIntelligence() const;
    int getWisdom() const;
    int getCharisma() const;
     
    int getCurrentHitPoints();
    int getAbilityMod(int); // ability modifiers
    int getHitPoints();  //hit points based on const and level
    int attackBonus(); //based on level and strength/dex
    int armorClass(); //based on dex modifier
    int damageBonus(); //based strength modifier
     
    void hit(int hitDamage);
    void equip(Item&);
    virtual void notify();
     
private:    
    int genRandNumb(int, int);
    int level;
    int abilityScores[6];
    int currentHitPoints;
    string charType;
  
};
     
 
#endif /* PLAYERCHARACTER_H */