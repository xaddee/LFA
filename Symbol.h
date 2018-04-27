//
// Created by Adelin on 4/27/2018.
//

#ifndef LFA_HOMEWORK2_SYMBOL_H
#define LFA_HOMEWORK2_SYMBOL_H

#include <iostream>
#include <vector>

class Symbol {
    int _number_of_roads;
    int _index;
    bool _final;
public:
    Symbol();
    ~Symbol();

    void setNumberOfRoads(int);
    int showNumberOfRoads();

    void setIndex(int);
    int showIndex();

    bool showFinal();
    void setFinal(bool);
};


#endif //LFA_HOMEWORK2_SYMBOL_H
