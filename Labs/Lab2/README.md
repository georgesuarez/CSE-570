# Lab 2

## Program Description:
This program is designed to find all sets of FIRST(X) and FOLLOW(X)
given a grammar. The program uses the algorithm that was given in the
CSE 570/670 website. FIRST and FOLLOW are maps that uses the non-terminal
as a key which contains the set that is produced by their respective
algorithms. The parsing of the grammar initially maps the terminals to FIRST, and
then it parses the productions which gets stored into a set. 


## Running the program:
Compile the program by entering
	
	`make main`

and then to execute the program

	`./main <filename>`

## Example:
###Input:
`./main g419`

### Output:
```The productions in g419 are:
E->E+T
E->T
F->(E)
F->i
S->E
T->F
T->T*F

FIRST = 
( -> { ( }
) -> { ) }
* -> { * }
+ -> { + }
E -> { ( i }
F -> { ( i }
S -> { ( i }
T -> { ( i }
i -> { i }

FOLLOW = 
E -> { ) + }
F -> { ) * + }
S -> { $ }
T -> { ) * + } ```
