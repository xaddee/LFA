//
// Created by Adelin on 4/27/2018.
//

#include "Symbol.h"
Symbol::Symbol()
{

}

Symbol::~Symbol()
{

}

void Symbol::setNumberOfRoads(int number)
{
    _number_of_roads =  number;
}

int Symbol::showNumberOfRoads()
{
    return _number_of_roads;
}

int Symbol::showIndex()
{
    return _index;
}

void Symbol::setIndex(int index)
{
    _index = index;
}

void Symbol::setFinal(bool value)
{
    _final = value;
}

bool Symbol::showFinal()
{
    return _final;
}