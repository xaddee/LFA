#include <iostream>
#include <vector>
#include <fstream>

#include "Symbol.h"
#include "Road.h"


bool CheckWord()
{

}

Symbol FindSymbolByName(char name)
{

}

// lamda este ~

//o sa creez o matrice de drumuri. indexul reprezinta din ce symbol plec. si dupa obiectul drum ne spune unde mergem
int main()
{

    std::ifstream f(" ../date.txt" );

    unsigned int number_of_symbols;
    f >> number_of_symbols;

    Road **roads;

    roads = new Road*[number_of_symbols];

    std::vector<Symbol> symbols;
    symbols.resize(number_of_symbols);


    for(int index = 0; index < number_of_symbols; index++)
    {
        char symbol_name;
        f >> symbol_name;
        int number_of_roads;
        f >> number_of_roads;

        symbols[index].setNumberOfRoads(number_of_roads);
        symbols[index].setName(symbol_name);

        roads[index] = new Road[number_of_roads];
    }

    for(int symbol_index = 0; symbol_index < number_of_symbols; symbol_index++)
    {
        for(int index = 0; index < symbols[symbol_index].showNumberOfRoads(); index++ )
        {
            char road_letter;
            f >> road_letter;

            roads[symbol_index][index].setLetter(road_letter);

            int check = 0; // folosim variabila check sa vedem daca mai merge si in alt simbol sau se opreste 1 => merge
            f >> check;

            if(check)
            {
                char next_symbol_name;
                f >> next_symbol_name;

                Symbol next = FindSymbolByName(next_symbol_name);
                roads[symbol_index][index].setNextSymbol(next);
            }


        }
    }

    return 0;
}