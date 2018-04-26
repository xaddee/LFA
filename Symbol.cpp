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

void Symbol::setName(char name)
{
    _name = name;
}

char Symbol::showName()
{
    return _name;
}