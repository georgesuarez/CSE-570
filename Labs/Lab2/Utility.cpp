#include "Utility.h"

#include <set>

#define EPLISON 'e'

bool Utility::hasEplison(std::set<char> &s)
{
    return s.find(EPLISON) != s.end();
}

std::set<char> Utility::setUnion(std::set<char> &s1, std::set<char> &s2)
{
    std::set<char> result;
    result.insert(s1.begin(), s1.end());
    result.insert(s2.begin(), s2.end());
    return result;
}

bool Utility::isNonTerminal(char input)
{
    return isalpha(input) && isupper(input);
}