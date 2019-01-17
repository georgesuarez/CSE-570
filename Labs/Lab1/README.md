# Lab 1

DFAs are specified by a set of states (among them one starting and one
or more accepting), and transitions between pairs of states which are labeled
by a symbol of some alphabet. DFAs are typically given in one of two formats:

1. A transition diagram (that is a directed graph), and
2. A transition table.

Both representations are equivalant to each other.

## Exercise:
Write the program simulates the DFA in the book (pg. 141) in the language of your choice, but limited to something could run on the machines in the lab.

_Accepts L = (a|b)* abb_

The input to the DFA should be a string; in the course of processing this string character-by-character, the DFA will undergo the specified state transitions. The DFA accepts the string if it is in an accepting state when it has consumed its' input; otherwise it rejects the string.

## Deliverables:
**Program source code with internal documentation**

**Test results : Use strings that are in L, and strings not in L**

## Extra Credit:
Extend Lab 1 to read a text input and accept every instance of text that satisfies DFA1 or DFA2, ignoring all other text. It should output the position of each string found, and which DFA it satisfies. Take DFA1 to be the one you wrote for the original lab, DFA2 is a regular expression of your choice, using the same alphabet



