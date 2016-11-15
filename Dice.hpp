//
//  Dice.hpp
//  COMP 345 Assignment 1
//
//  Created by Nelson Frank on 2016-10-02.
//
/*! \brief Dice Class.
 *
 * 1) game rules involved:
 * Dice are rolled. The dice are limited to d4,d6,d8,d10,d12,d20, and d100
 * 2) description of design
 * Dice class provides static methods and is not designed to be initialized.
 * a private method is used that can roll any number of any kind of dice
 * a public method takes a string as input and uses the private method to roll dice given proper input
 * the public method matches the input string to a pattern to ensure that it is correct
 * it then extracts the integers from the string
 * it then rolls the dice if they are allowed, returning -1 otherwise
 * 2) libraries used in the code
 * 1 <regex> This library allows for the use of regular expressions that validate the string input.
 * 2 <sstream> This library provides the ability to treat strings like streams which makes it easier to separate the chars from the ints
 * 3 <random> This library was included because the rand() method was insufficient. seeding the rand method with time(0) meant that all calls to rand() within the same second would have the same seed. <random> provides a better means to seed a random generator. Additionally, the mersenne algorithm for pseudo-random number generations provides a better number distribution than the implementation of rand(). This generator was also availble in <random>.
 */
#ifndef Dice_hpp
#define Dice_hpp

#include <iostream>

//only one dice object is to be initialized
//if multiple dice are initialized in the same second then they get the same seed and produce identical results
class Dice{
private:
    static int roll(int n, int d, int z);
public:
    //Dice(); not used
    //! Rolls dice according to string input. Returns -1 for invalid input.
    static int roll(std::string s);
};


#endif /* Dice_hpp */
