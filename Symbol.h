//
// Created by Adelin on 4/27/2018.
//

#ifndef LFA_HOMEWORK2_SYMBOL_H
#define LFA_HOMEWORK2_SYMBOL_H
#include "Road.h"
#include <iostream>
#include <vector>

class Symbol {
    char _name;
    int _number_of_roads;
public:
    Symbol();
    ~Symbol();
    void setName(char);
    char showName();
    void setNumberOfRoads(int);
    int showNumberOfRoads();
};


#endif //LFA_HOMEWORK2_SYMBOL_H
