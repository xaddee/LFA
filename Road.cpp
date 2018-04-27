//
// Created by Adelin on 4/27/2018.
//

#include "Road.h"

Road::Road()
{

}

Road::~Road()
{

}

void Road::setLetter(char letter)
{
    _letter = letter;
}

char Road::showLetter()
{
    return _letter;
}

void Road::setNextSymbol(Symbol next)
{
   _next_symbol = next;
}

Symbol Road::showNextSymbol()
{
    return _next_symbol;
}