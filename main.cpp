#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

#include "Symbol.h"
#include "Road.h"

/**
 *
 * @param word char*, representing the word that we verify
 * @param roads is a matrix that represents all the roads from all the symbols
 * @param start the start symbol
 * @param current_letter_index the letter in word that we verify
 * @return true/false if the word belongs or not to the grammar
 */


bool CheckWord(char *word, Road **roads ,Symbol start, int current_letter_index) {
    if (current_letter_index == strlen(word) && start.showFinal()) return true;

    if (current_letter_index == strlen(word) && !start.showFinal()) return false;

    if (current_letter_index <= strlen(word) && start.showNumberOfRoads() == 0) return false;

    for (int i = 0; i < start.showNumberOfRoads(); i++) {
        if (roads[start.showIndex()][i].showLetter() == word[current_letter_index])
            if (CheckWord(word, roads, roads[start.showIndex()][i].showNextSymbol(),  current_letter_index + 1)) return true;

    }

    return false;
}

// lamda este #
int main()
{

    std::ifstream f("../date.txt" );

    unsigned int number_of_symbols;
    f >> number_of_symbols;
    std::cout << number_of_symbols;

    char word[21];
    f >> word;
    std::cout << word;

    Road **roads;

    roads = new Road *[number_of_symbols];

    std::vector<Symbol> symbols;
    symbols.resize(number_of_symbols);


    for(int index = 0; index < number_of_symbols; index++)
    {

        int number_of_roads = 0;
        f >> number_of_roads;

        int final;
        f >> final;

        if(final) symbols[index].setFinal(true);
        else symbols[index].setFinal(false);

        symbols[index].setNumberOfRoads(number_of_roads);
        roads[index] = new Road [number_of_roads];
    }

    for(int symbol_index = 0; symbol_index < number_of_symbols; symbol_index++)
    {
        symbols[symbol_index].setIndex(symbol_index);
        for(int road_index = 0; road_index < symbols[symbol_index].showNumberOfRoads(); road_index++ )
        {
            char road_letter;
            f >> road_letter;

            roads[symbol_index][road_index].setLetter(road_letter);

            int next_symbol;
            f >> next_symbol;

            roads[symbol_index][road_index].setNextSymbol(symbols[next_symbol]);

        }
    }


    if (word[0] == '#')
    {
        std::cout << symbols[0].showFinal();
        if (symbols[0].showFinal()) std::cout << "Cuvantul apartine alfabetului";
        else std::cout << "Cuvantul nu apartine alfabetului";
    }
    else if(CheckWord(word,roads,symbols[0],0)) std::cout << "Cuvantul apartine gramaticii.";
    else std::cout << "Cuvantul nu apartine gramaticii.";


    return 0;
}