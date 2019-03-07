# Lab 3

## Program Description
This program reads a grammer and finds the canonical LR(0) sets
of that grammer.

## Running the program
Simply compile the program by doing,

```make main```

then run the program by doing

```./main <filename>```

## Example
### Input

```./main g419 ```

### Output

```
Item: 0
Symbol: 
Production: [3] = E->.E+T
Production: [3] = E->.T
Production: [3] = F->.(E)
Production: [3] = F->.i
Production: [3] = S->.E
Production: [3] = T->.F
Production: [3] = T->.T*F

Item: 1
Symbol: (
Production: [3] = E->.E+T
Production: [3] = E->.T
Production: [3] = F->.(E)
Production: [3] = F->.i
Production: [3] = T->.F
Production: [3] = T->.T*F
Production: [4] = F->(.E)

Item: 2
Symbol: E
Production: [4] = E->E.+T
Production: [4] = S->E.

Item: 3
Symbol: F
Production: [4] = T->F.

Item: 4
Symbol: T
Production: [4] = E->T.
Production: [4] = T->T.*F

Item: 5
Symbol: i
Production: [4] = F->i.

Item: 6
Symbol: E
Production: [4] = E->E.+T
Production: [5] = F->(E.)

Item: 7
Symbol: +
Production: [3] = F->.(E)
Production: [3] = F->.i
Production: [3] = T->.F
Production: [3] = T->.T*F
Production: [5] = E->E+.T

Item: 8
Symbol: *
Production: [3] = F->.(E)
Production: [3] = F->.i
Production: [5] = T->T*.F

Item: 9
Symbol: )
Production: [6] = F->(E).

Item: 10
Symbol: T
Production: [4] = T->T.*F
Production: [6] = E->E+T.

Item: 11
Symbol: F
Production: [6] = T->T*F.

```