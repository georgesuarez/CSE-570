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
