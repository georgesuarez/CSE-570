#include <iostream>
#include <string>

#define ACCEPTING_STATE 3
#define STATES 4
#define SYMBOLS 2

typedef int State;

// Transition table for DFA1: L = (a|b)* abb
static int transitionTable1[STATES][SYMBOLS] = {{1, 0}, {1, 2}, {1, 3}, {1, 0}};

// Transition table for DFA2: L = (a|b)* bba
static int transitionTable2[STATES][SYMBOLS] = {{0, 1}, {0, 2}, {3, 2}, {0, 1}};

// Initial starting state for both DF1 and DF2
State getInitialState()
{
    return 0;
}

// Returns true if the final state is in accepting state
bool isFinalState(State state)
{
    return (state == ACCEPTING_STATE) ? true : false;
}

// Determines what state to transition to given an input
int getTransition(char input)
{
    // Not in the language
    if (input != 'a' && input != 'b')
    {
        return -1;
    }

    switch (input)
    {
    case 'a':
        return 0;
        break;
    case 'b':
        return 1;
        break;
    default:
        return -1;
        break;
    }
}

int main()
{
    std::string language1 = "(a|b)* abb";
    std::string language2 = "(a|b)* bba";

    std::string testString, currentString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, testString);

    if (testString.empty() || testString.length() < 3)
    {
        std::cerr << "Not a valid string" << '\n';
        return EXIT_FAILURE;
    }

    std::cout << '\n';

    State state1 = getInitialState();
    State state2 = getInitialState();

    for (int i = 0; i < testString.length(); i++)
    {
        char input = testString[i];

        currentString += input;

        int transition = getTransition(input);

        state1 = transitionTable1[state1][transition];
        state2 = transitionTable2[state2][transition];
    }

    if (isFinalState(state1) && isFinalState(state2))
    {
        std::cout << "\033[32mACCEPTED in both languages at position: " << currentString << '\n';
    }
    else if (!isFinalState(state1) && isFinalState(state2))
    {
        std::cout << "\033[32m"
                  << "ACCEPTED for the language: " << language2 << '\n';
        std::cout << "\033[31m"
                  << "REJECTED for the language: " << language1 << '\n';
        std::cout << "Position of the string: " << currentString << '\n';
    }
    else if (isFinalState(state1) && !isFinalState(state2))
    {
        std::cout << "\033[32mACCEPTED for the language: " << language1 << '\n';
        std::cout << "\033[31mREJECTED for the language: " << language2 << '\n';
        std::cout << "Position of the string: " << currentString << '\n';
    }
    else
    {
        std::cout << "\033[31mREJECTED for both languages" << '\n';
        std::cout << "Position of the string: " << currentString << '\n';
    }

    return EXIT_SUCCESS;
}
