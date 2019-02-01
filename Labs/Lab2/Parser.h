#pragma once
#ifndef PARSER_H
#define PARSER_H

#include "Utility.h"
#include <string>
#include <map>
#include <set>
#include <fstream>

class Parser
{
  public:
    Parser(std::string &grammerFile);

    void parse();
    void computeFirst();
    void computeFollow();

    void printFirst() const;
    void printFollow() const;
    void printProductions() const;

  private:
    std::string grammer;

    std::set<std::string> productions;
    std::set<char> nonTerminals;
    std::map<char, std::set<char> > first;
    std::map<char, std::set<char> > follow;

    Utility util;

    bool changed;
};

#endif // PARSER_H