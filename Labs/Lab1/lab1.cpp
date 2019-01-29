/*
 * Name: George Suarez
 * Lab: 1
 * Class: CSE 570 Compilers
 * Term: Winter 2019
 * Instructor: Ernesto Gomez
**/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ACCEPTING_STATE 3
#define STATES 4
#define SYMBOLS 2

typedef int State;

// Transition table for DFA1: L = (a|b)* abb
static int transitionTable1[STATES][SYMBOLS] = {{1, 0}, {1, 2}, {1, 3}, {1, 0}};

// Transition table for DFA2: L = (a|b)* bba
static int transitionTable2[STATES][SYMBOLS] = {{0, 1}, {0, 2}, {3, 2}, {0, 1}};

// Initial starting state for both DFA1 and DFA2
State getInitialState()
{
    return 0;
}

// Checks if a given state is in its' accepting state
// Returns a true if state == 3, otherwise false
bool isFinalState(State state)
{
    return (state == ACCEPTING_STATE) ? true : false;
}

// Determines what the transition code is given an character as input
int getTransition(char input)
{
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
    const string language1 = "(a|b)* abb"; // Language for DFA1
    const string language2 = "(a|b)* bba"; // Language for DFA2

    string testString, currentString;

    vector<string> acceptedStringsDFA1;
    vector<string> acceptedStringsDFA2;

    vector<pair<int, int>> validPositionsForDFA1;
    vector<pair<int, int>> validPositionsForDFA2;

    getline(cin, testString);

    if (testString.empty() || testString.length() < 3)
    {
        cerr << "Not a valid string" << '\n';
        return EXIT_FAILURE;
    }

    cout << '\n';

    cout << "The input string entered: " << testString << '\n';

    State state1 = getInitialState();
    State state2 = getInitialState();

    int startingPosForDFA1 = 0, startingPosForDFA2 = 0;
    int currentPosForDFA1 = 0;
    int currentPosForDFA2 = 0;
    int endPosForDFA1 = 0;
    int endPosForDFA2 = 0;

    for (size_t i = 0; i < testString.length(); i++)
    {
        char input = testString[i];

        int transition = getTransition(input);

        if (transition == -1)
        {
            state1 = 0;
            state2 = 0;
            startingPosForDFA1 = i + 1;
            startingPosForDFA2 = i + 1;
        }
        else
        {
            currentString += input;

            state1 = transitionTable1[state1][transition];
            state2 = transitionTable2[state2][transition];

            switch (state1)
            {
            case 0:
                startingPosForDFA1 = i;
                break;
            case 1:
            case 2:
                currentPosForDFA1 = i + 1;
                break;
            case 3:
                endPosForDFA1 = currentPosForDFA1;
                break;
            }

            switch (state2)
            {
            case 0:
                startingPosForDFA2 = i;
                break;
            case 1:
            case 2:
                currentPosForDFA2 = i + 1;
                break;
            case 3:
                endPosForDFA2 = currentPosForDFA2;
                break;
            }
        }

        if (isFinalState(state1))
        {
            validPositionsForDFA1.push_back(make_pair(startingPosForDFA1, endPosForDFA1));
            acceptedStringsDFA1.push_back(currentString);
            state1 = getInitialState();
        }
        else if (isFinalState(state2))
        {
            validPositionsForDFA2.push_back(make_pair(startingPosForDFA2, endPosForDFA2));
            acceptedStringsDFA2.push_back(currentString);
            state2 = getInitialState();
        }
    }

    if (acceptedStringsDFA1.empty() && acceptedStringsDFA2.empty())
    {
        cout << "\033[31mREJECTED for both languages" << '\n';
        return EXIT_FAILURE;
    }

    vector<pair<int, int> >::iterator it;

    if (!validPositionsForDFA1.empty() && !acceptedStringsDFA1.empty())
    {
        cout << "\033[32mValid position(s) for the language: " << language1 << " are in: " << '\n';
        for (it = validPositionsForDFA1.begin(); it != validPositionsForDFA1.end(); ++it)
        {
            pair<int, int> tmp = *it;
            cout << tmp.first << '-' << tmp.second << '\n';
        }
        cout << "\n\n";
    }

    if (!validPositionsForDFA2.empty() && !acceptedStringsDFA2.empty())
    {
        cout << "\033[32mValid positions for the language: " << language2 << " are in: " << '\n';
        for (it = validPositionsForDFA2.begin(); it != validPositionsForDFA2.end(); ++it)
        {
            pair<int, int> tmp = *it;
            cout << tmp.first << '-' << tmp.second << '\n';
        }
        cout << "\n\n";
    }

    if (!acceptedStringsDFA1.empty())
    {
        cout << "\033[32mACCEPTED string(s) for " << language1 << ":" << '\n';
        for (size_t i = 0; i < acceptedStringsDFA1.size(); i++)
        {
            cout << acceptedStringsDFA1[i] << ' ';
        }
        cout << "\n\n";
    }
    else
    {
        cout << "\033[31mNo valid string(s) was accepted in the language: " << language1 << '\n';
    }

    if (!acceptedStringsDFA2.empty())
    {
        cout << "\033[32mACCEPTED string(s) for " << language2 << ":" << '\n';
        for (size_t i = 0; i < acceptedStringsDFA2.size(); i++)
        {
            cout << acceptedStringsDFA2[i] << ' ';
        }
        cout << "\n\n";
    }
    else
    {
        cout << "\033[31mNo valid string(s) was accepted in the language: " << language2 << '\n';
    }

    return 0;
}
