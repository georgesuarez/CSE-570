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
ID: 0
Symbol: 
Production: [3] = E->E+T
Production: [3] = E->T
Production: [3] = F->(E)
Production: [3] = F->i
Production: [3] = T->F
Production: [3] = T->T*F

ID: 1
Symbol: E
Production: [4] = E->E+T

ID: 2
Symbol: F
Production: [4] = T->F

ID: 3
Symbol: T
Production: [4] = E->T
Production: [4] = T->T*F

ID: 4
Symbol: i
Production: [4] = F->i

ID: 5
Symbol: +
Production: [5] = E->E+T
Production: [3] = F->(E)
Production: [3] = F->i
Production: [3] = T->F
Production: [3] = T->T*F

ID: 6
Symbol: *
Production: [3] = F->(E)
Production: [3] = F->i
Production: [5] = T->T*F

ID: 7
Symbol: T
Production: [6] = E->E+T
Production: [4] = T->T*F

ID: 8
Symbol: F
Production: [6] = T->T*F
```