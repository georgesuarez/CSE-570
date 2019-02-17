/*
 * Name: George Suarez
 * Class: CSE 570 Compilers
 * Instructor: Dr. Ernesto Gomez
 * Term: Winter 2019
**/
#include "Parser.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "usage: ./main <filename>\n";
        return 0;
    }

    std::string grammer = argv[1];

    Parser *parser = new Parser(grammer);

    parser->parse();

    parser->printCanonicalSet();


    delete parser;

    return 0;
}
