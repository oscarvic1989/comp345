//
//  Dice.hpp
//  COMP 345 Assignment 1
//
//  Created by Nelson Frank on 2016-10-02.
//

#ifndef Dice_hpp
#define Dice_hpp

#include <iostream>

//only one dice object is to be initialized
//if multiple dice are initialized in the same second then they get the same seed and produce identical results
class Dice{
private:
    int roll(int n, int d, int z);
public:
    Dice();
    int roll(std::string s);
};


#endif /* Dice_hpp */
