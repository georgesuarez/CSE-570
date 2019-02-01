#include "Parser.h"
#include "Utility.h"

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>

#define EPLISON 'e'

Parser::Parser(std::string &grammerFile) : grammer(grammerFile){};

void Parser::parse()
{
    std::ifstream inputGrammerFile;

    inputGrammerFile.open(grammer.c_str());

    if (!inputGrammerFile.is_open())
    {
        std::cerr << "Error: " << grammer << " not found." << '\n';
        exit(-1);
    }

    std::string input = "";

    int productionsPositionInTheGrammer = 0;

    while (inputGrammerFile >> input)
    {
        if (input == "$") // End of non-terminals
        {
            productionsPositionInTheGrammer = inputGrammerFile.tellg();
            break;
        }
        else
        {
            // Add FIRST(X) = {X}
            first[input[0]].insert(input[0]);
        }
    }

    inputGrammerFile.seekg(productionsPositionInTheGrammer);
    input.clear();

    // Now add the productions
    while (inputGrammerFile >> input)
    {
        productions.insert(input);
    }

    // Do not need the $ in our productions
    // since we just want the productions
    productions.erase(productions.find("$"));

    for (auto p : productions)
    {
        std::string currProd = p;
        char nonTerminal = currProd[0];
        nonTerminals.insert(nonTerminal);

        std::string rhs = currProd.substr(3);
        size_t index = 0;
        while (index < rhs.length())
        {
            if (rhs[index] == EPLISON)
            {
                first[nonTerminal].insert(EPLISON);
            }
            index++;
        }
    }

    computeFirst();
    computeFollow();
}

void Parser::computeFirst()
{
    do
    {
        changed = false;

        // Go through productions
        for (auto p : productions)
        {
            std::string currProduction = p;
            char nonTerminal = currProduction[0];
            std::string rhs = currProduction.substr(3);

            for (size_t i = 0; i < rhs.length();)
            {
                std::set<char> temp = first[rhs[i]];

                if (util.hasEplison(temp))
                {
                    temp.erase(temp.find(EPLISON));
                    std::set<char> unionSet = util.setUnion(first[nonTerminal], temp);

                    for (auto s : unionSet)
                    {
                        auto checkInsert = first[nonTerminal].insert(s);

                        // Check if a set in FIRST has been changed after inserting
                        // a new nonTerminal key
                        if (checkInsert.second)
                        {
                            changed = true;
                        }
                    }

                    i++;
                }
                else
                {
                    std::set<char> unionSet = util.setUnion(first[nonTerminal], temp);

                    for (auto s : unionSet)
                    {
                        auto checkInsert = first[nonTerminal].insert(s);

                        if (checkInsert.second)
                        {
                            changed = true;
                        }
                    }
                    break;
                }
                // i > k
                if (i >= rhs.length())
                {
                    auto checkInsert = first[nonTerminal].insert(EPLISON);

                    if (checkInsert.second)
                    {
                        changed = true;
                    }
                }
                i++;
            }
        }
    } while (changed);
}

void Parser::computeFollow()
{
    do
    {
        changed = false;
        for (auto p : productions)
        {
            std::string currProduction = p;
            char nonTerminal = currProduction[0];
            std::string rhs = currProduction.substr(3);

            for (size_t i = 0; i < rhs.length();)
            {
                if (util.isNonTerminal(rhs[i]) && i < rhs.length() - 1)
                {
                    std::set<char> temp = first[rhs[i + 1]];
                    if (util.hasEplison(temp))
                    {
                        std::set<char> nonTerminalFollowSet = follow[nonTerminal];
                        for (auto n : nonTerminalFollowSet)
                        {
                            auto checkInsert = follow[rhs[i]].insert(n);
                            if (checkInsert.second)
                            {
                                changed = true;
                            }
                        }
                    }
                    for (auto t : temp)
                    {
                        auto checkInsert = follow[rhs[i]].insert(t);
                        if (checkInsert.second)
                        {
                            changed = true;
                        }
                    }
                }
                else if (util.isNonTerminal(rhs[i]) && i == rhs.length() - 1)
                {
                    std::set<char> temp = follow[nonTerminal];
                    for (auto t : temp)
                    {
                        auto checkInsert = follow[rhs[i]].insert(t);
                        if (checkInsert.second)
                        {
                            changed = true;
                        }
                    }
                }
                i++;
            }
        }
    } while (changed);
}

void Parser::printFirst() const
{
    std::cout << "FIRST = " << '\n';
    for (auto f : first)
    {
        std::cout << "[" << f.first << "] = ";
        for (auto s : f.second)
        {
            std::cout << "{ " << s << " }";
        }
        std::cout << '\n';
    }
}

void Parser::printFollow() const
{
    std::cout << "FOLLOW = " << '\n';
    for (auto f : follow)
    {
        std::cout << "[" << f.first << "] = ";
        for (auto s : f.second)
        {
            std::cout << "{ " << s << " }";
        }
        std::cout << '\n';
    }
}

void Parser::printProductions() const
{
    std::cout << "The productions in G: " << '\n';
    for (auto p : productions)
    {
        std::cout << p << '\n';
    }
    std::cout << '\n';
}