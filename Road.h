//
// Created by Adelin on 4/27/2018.
//

#ifndef LFA_HOMEWORK2_ROAD_H
#define LFA_HOMEWORK2_ROAD_H

#include "Symbol.h"

class Road {
    char  _letter;
    Symbol _next_symbol;

public:
    Road();
    ~Road();

    void setLetter(char);
    char showLetter();

    void setNextSymbol(Symbol);
    Symbol showNextSymbol();



};


#endif //LFA_HOMEWORK2_ROAD_H
