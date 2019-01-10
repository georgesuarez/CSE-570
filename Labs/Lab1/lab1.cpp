#include <iostream>
#include <string>
#include <vector>

#define ACCEPTING_STATE 3
#define STATES 4
#define SYMBOLS 2

typedef int State;

enum Alphabet
{
    a,
    b
};

static int transitionTable[STATES][SYMBOLS] = {
    {1, 0},
    {1, 2},
    {1, 3},
    {1, 0}};

State getInitialState()
{
    return 0;
}

bool isFinalState(State s)
{
    return (s == ACCEPTING_STATE) ? true : false;
}

State getTransition(State s, char input)
{
    // Not in the language
    if (input != 'a' && input != 'b')
    {
        return -1;
    }

    // Determine what state to return depending on the current state
    switch (s)
    {
    case 0:
        if (input == 'a')
            return transitionTable[s][0];
        else if (input == 'b')
            return transitionTable[s][1];
        break;
    case 1:
        if (input == 'a')
            return transitionTable[s][0];
        else if (input == 'b')
            return transitionTable[s][1];
        break;
    case 2:
        if (input == 'a')
            return transitionTable[s][0];
        else if (input == 'b')
            return transitionTable[s][1];
        break;
    case 3:
        if (input == 'a')
            return transitionTable[s][0];
        else if (input == 'b')
            return transitionTable[s][1];
        break;
    default:
        return 0;
        break;
    }

    return -1;
}

int main()
{

    std::string testString, currentString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, testString);

    std::cout << '\n';

    State state = getInitialState();

    for (int i = 0; i < testString.length(); i++)
    {
        if (testString.empty() || testString.length() < 3)
        {
            std::cerr << "Not a valid string" << '\n';
            return EXIT_FAILURE;
        }

        char input = testString[i];

        currentString += input;

        state = getTransition(state, input);

        std::cout << "Checking string: " << currentString << '\n';
        std::cout << "In state: " << state << "\n\n";
    }

    if (isFinalState(state))
    {
        std::cout << "\033[32mACCEPTED\033" << '\n';
    }
    else
    {
        std::cout << "\033[31mREJECTED\033" << '\n';
    }

    return 0;
}
