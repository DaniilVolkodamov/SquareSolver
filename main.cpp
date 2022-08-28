#include <stdio.h>
#include "SqrEqSolver.h"

int main()
{
    printf("Square equation solver.\n");
    printf("To solve your square equation enter 1.\n");
    printf("To start tests enter 2.\n");
    printf("To start tests from a file enter 3.\n");
    printf("To start random test enter 4.\n");
    printf("To stop the program enter any other value.\n");

    SqrEqSolverMode();

    return 0;
}
