//
//  Dice.cpp
//  COMP 345 Assignment 1
//
//  Created by Nelson Frank on 2016-10-02.
//

#include "Dice.hpp"
#include <sstream>
#include <regex>

Dice::Dice(){
    srand((unsigned)time(0));
}
int Dice::roll(int n, int d, int z){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += rand() % d + 1;
    }
    sum += z;
    
    return sum;
}
int Dice::roll(std::string s){
    //verify string with regex: xdy(+z)
    bool match = regex_match(s, std::regex("^\\d+d\\d+(?:\\+\\d+)?$"));
    
    if(!match){
        return -1; //return of -1 signifies incorrect input;
    }
    int x,y,z;
    
    //since we know that the input follows a strict pattern, we don't need to be careful extracting the ints;
    std::stringstream *sstream = new std::stringstream(s);
    std::string temp;
    getline(*sstream, temp, 'd');
    x = stoi(temp);
    getline(*sstream, temp, '+');
    y = stoi(temp);
    if(getline(*sstream,temp)){
        z = stoi(temp);
    }
    else{
        z = 0;
    }
    delete sstream;
    
    //allow only specific dice rolls, return -1 on not allowed die
    switch(y){
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
        case 20:
        case 100: return roll(x,y,z); break;
        default: return -1; break;
    }
}
