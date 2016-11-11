/**
 *Wan Lan He - 29469419 - part 1 - part 2
 * Project Dungeons and Dragons
 * Create a character, add Observer function
 * PlayerCharacter.h 
 */
  
#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include <iostream>
#include <list>
#include <string>
#include "Observer.h"
#include "Subject.h"
using namespace std;
  
class PlayerCharacter: public Subject{ 
      
public:
    PlayerCharacter(); //default constructor
    ~PlayerCharacter(); //deconstructor
    PlayerCharacter(int level);
    PlayerCharacter(string charName, string charType, int level);
    PlayerCharacter(int,int,int,int,int,int);
    
    bool validateNewCharacter();
    void characterData();
    void characterInfo();
    void characterCreate();
      
    string getCharName();
    string getCharType() const;
    int getLevel() const; //
    
    //! getters for ability scores
    int str, dex, cons, intel, wis, chari;
    int getStrength() const;
    int getDexterity() const;
    int getConstitution() const;
    int getIntelligence() const;
    int getWisdom() const;
    int getCharisma() const;
    
    //setters
    void setStrength(int);
    void setDexterity(int);
    void setConstitution(int);
    void setIntelligence(int);
    void setWisdom(int);
    void setCharisma(int);
 
    int getCurrentHitPoints();
    int getAbilityMod(int); // ability modifiers
    int getHitPoints();  //hit points based on const and level
    int attackBonus(); //based on level and strength/dex
    int armorClass(); //based on dex modifier
    int damageBonus(); //based strength modifier
    int multipleAttacks();
    int itemEnhancement(); 
     
    void levelUp();
    void hit(int hitDamage);
    void equip(const string item);
    virtual void notify();
     
    
    int rollStats();
    int setAbilityScore();
    
    private:     
    int genRandNumb(int, int);
    int genRandNumb(int); 
    int abilityScores[6];
    int currentHitPoints;
    string charType; 
     
};
 
struct Item{
    string armor;
    string belt;
    string boots;
    string helmet;
    string ring;
    string shield;
    string weapon;
};
 
      
  
#endif /* PLAYERCHARACTER_H */