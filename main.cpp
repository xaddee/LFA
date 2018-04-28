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
 * @param start the starting symbol
 * @param current_letter_index the letter in word that we verify
 * @return true/false if the word belongs or not to the grammar
 */


bool CheckWord(char* word, Road **roads ,Symbol start, int current_letter_index)
{
    if (current_letter_index == strlen(word)  && start.showFinal()) return true;

    if (current_letter_index == strlen(word)  && !start.showFinal()) return false;

    if (current_letter_index <= strlen(word) && start.showNumberOfRoads() == 0) return false;

    for (int i = 0; i < start.showNumberOfRoads(); i++)

        if (roads[start.showIndex()][i].showLetter() == word[current_letter_index])

               if (CheckWord(word, roads, roads[start.showIndex()][i].showNextSymbol(), current_letter_index + 1)) return true;

    return false;
}

/**
 *
 * @param maximum the maximum length of the word
 * @param roads is a matrix that represents all the roads from all the symbols
 * @param start the starting symbol
 * @param current_index the number of letters generated
 * @param word the generated word
 */

void GenerateWords(int maximum, Road **roads, Symbol start,int current_index,char * word)
{
    if(current_index == maximum )
    {
        std::cout << word << " ";
        return;
    }

    for(int i = 0; i < start.showNumberOfRoads(); i++)
    {
        word[current_index] = roads[start.showIndex()][i].showLetter();
        GenerateWords(maximum, roads, roads[start.showIndex()][i].showNextSymbol(),current_index+1,word);
    }
    //return;
}

// lamda este #
int main()
{

    std::ifstream f("../date.txt" );

    unsigned int number_of_symbols;
    f >> number_of_symbols;

    Road **roads;

    roads = new Road *[number_of_symbols];

    std::vector<Symbol> symbols;
    symbols.resize(number_of_symbols);


    for(int symbol_index = 0; symbol_index < number_of_symbols; symbol_index++)
    {

        int number_of_roads = 0;
        f >> number_of_roads;

        int final;
        f >> final;

        if(final) symbols[symbol_index].setFinal(true);
        else symbols[symbol_index].setFinal(false);

        symbols[symbol_index].setNumberOfRoads(number_of_roads);

        roads[symbol_index] = new Road [number_of_roads];
        symbols[symbol_index].setIndex(symbol_index);
    }

    for(int symbol_index = 0; symbol_index < number_of_symbols; symbol_index++)
    {

        for(int road_index = 0; road_index < symbols[symbol_index].showNumberOfRoads(); road_index++ )
        {
            char road_letter;
            f >> road_letter;

            roads[symbol_index][road_index].setLetter(road_letter);

            int next_symbol;
            f >> next_symbol;

            roads[symbol_index][road_index].setNextSymbol(symbols[next_symbol]);
            Symbol next = roads[symbol_index][road_index].showNextSymbol();

        }
    }

    std::cout << "Generare cuvant sau verificare? (1/0)?";
    int x;
    std::cin >> x;

    if(!x)
    {
        int number_of_words;
        std::cout << "Introduceti numarul de cuvinte de verificat (maxim 21 caractere): ";
        std::cin >> number_of_words;

        char words[number_of_words][21];

        for (int word_index = 0; word_index < number_of_words; word_index++) {
            std::cout << "Introduceti cuvantul " << word_index << ": ";
            std::cin >> words[word_index];
        }

        for(int word_index = 0; word_index < number_of_words; word_index++)
        {
            if (words[word_index] == "#")
            {
                if (symbols[0].showFinal())
                    std::cout << "Cuvantul apartine gramaticii. \n";
                else
                    std::cout << "Cuvantul nu apartine gramaticii. \n";
            }
            else
            if (CheckWord(words[word_index], roads, symbols[0], 0))
            {
                std::cout << "Cuvantul apartine gramaticii.\n";
            }
            else
            {
                std::cout << "Cuvantul nu apartine gramaticii.\n";
            }
    }
    }
    else
    {
        std::cout << "Introduceti lungimea maxima: ";
        int maximum;
        std::cin >> maximum;

        char word[maximum];

        GenerateWords(maximum, roads, symbols[0],0,word);

    }

    return 0;
}