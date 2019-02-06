/*
 * Name: George Suarez
 * Class: CSE 570 Compilers
 * Instructor: Dr. Ernesto Gomez
 * Term: Winter 2019
**/
#include "Parser.h"
#include <iostream>

int main()
{
    std::string grammer = "g417";

    Parser *parser = new Parser(grammer);

    parser->parse();

    parser->printProductions();

    parser->printFirst();

    std::cout << '\n';

    parser->printFollow();

    delete parser;
}
