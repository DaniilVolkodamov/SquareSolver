#include <stdio.h>
#include <math.h>
#include "SqrEqSolver.h"

int isDoubleEq(double arg1, double arg2)
{
    if (fabs(arg1 - arg2) < SMALL_NUMBER)
        return 1;
    return 0;
}
int isDoubleZero(double arg)
{
    return isDoubleEq( arg, 0);
}

void CleaningBuffer()
{
    while (getchar() != '\n')
        continue;
}

int TestSqrEq()
{
    int okTests = 0;
    double discr = 0, x1 = 0, x2 = 0;
    int nRoots = 0;
    okTests += OneSqrEqTest(0, 0, 0, INF_ROOTS, 0, 0);
    okTests += OneSqrEqTest(0, 0, -4, 0, 0, 0);
    okTests += OneSqrEqTest(0, -8, 0, 1, 0, 0);
    okTests += OneSqrEqTest(0, 5, -5, 1, 1, 1);
    okTests += OneSqrEqTest(174, 0, 0, 1, 0, 0);
    okTests += OneSqrEqTest(1, 0, -4, 2, -2, 2);
    okTests += OneSqrEqTest(8, 4, 0, 2, -0.5, 0);
    okTests += OneSqrEqTest(1, -14, 48, 2, 6, 8);
    okTests += OneSqrEqTest(1, 6, 9, 1, -3, -3);
    okTests += OneSqrEqTest(1, 1, 1, 0, 0, 0);
    okTests += OneSqrEqTest(2, -3, 1, 2, 0.5, 1);
    okTests += OneSqrEqTest(-1, -15, -50, 2, -10, -5);
    okTests += OneSqrEqTest(1, 2, 5, 0, 0, 0);
    okTests += OneSqrEqTest(0, 10, -8, 1, 0.8, 0.8);
    okTests += OneSqrEqTest(1, -8, 16, 1, 4, 4);
    okTests += OneSqrEqTest(0, -2, -6, 1, -3, -3);
    okTests += OneSqrEqTest(1, -16, 63, 2, 7, 9);
    okTests += OneSqrEqTest(7, 5, 6, 0, 0, 0);
    okTests += OneSqrEqTest(-1, -4, -4, 1, -2, -2);
    okTests += OneSqrEqTest(-0, -0, -0, INF_ROOTS, 0, 0);
    okTests += OneSqrEqTest(5, 1, -4, 2, -1, 0.8);
    okTests += OneSqrEqTest(0.5, -3, 4.5, 1, 3, 3);
    okTests += OneSqrEqTest(-0, -0, 154, 0, 0, 0);
    okTests += OneSqrEqTest(0, 12, 600, 1, -50, -50);
    okTests += OneSqrEqTest(-0, 963, -0, 1, 0, 0);
    printf("Successfully completed tests: %d/%d.\n", okTests, 25);
    return okTests;
}
int OneSqrEqTest(double a_test, double b_test, double c_test, int nRoots_test, double x1_test, double x2_test)
{
    double discr = 0, x1 = 0, x2 = 0;
    int nRoots = 0;
    SolveSolution(a_test, b_test, c_test, &discr, &x1, &x2, &nRoots);
    if (!(nRoots == nRoots_test && isDoubleEq(x1, x1_test) && isDoubleEq(x2, x2_test)))
    {
        printf("Failed: coefficients: a = %lg, b = %lg, c = %lg, nRoots = %d, x1 = %lg, x2 = %lg\n" \
        "Expected: nRoots = %d, x1 = %lg, x2 = %lg\n", a_test, b_test, c_test, nRoots, x1, x2, nRoots_test, x1_test, x2_test);
        return 0;
    }
    return 1;
}

int LinNumOfRoots(double b, double c)
{
    if (isDoubleZero(b))
    {
        if (isDoubleZero(c))
        {
            return INF_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
    else
    {
        return ONE_ROOT;
    }
}
int SqrNumOfRoots(double discr)
{
    if (discr < 0)
    {
        return NO_ROOTS;
    }
    else if (isDoubleZero(discr))
    {
        return ONE_ROOT;
    }
    else
    {
        return TWO_ROOTS;
    }
}

void LinearSolver(double b, double c, double *x1, double *x2)
{
    ASSERT(x1);
    ASSERT(x2);

    if (isDoubleZero(b) == 0)
    {
        *x1 = -c/b;
        *x2 = -c/b;
    }
}
void SquareSolver(double a, double b, double discr, double *x1, double *x2)
{
    ASSERT(x1);
    ASSERT(x2);

    if (discr < 0)
    {
        *x1 = *x2 = NO_ROOTS;
    }
    else if (isDoubleZero(discr))
    {
        *x1 = *x2 = (-b + sqrt(discr))/(2*a);
    }
    else
    {
        double discr_sqrt = sqrt(discr), a_double = 2*a;
        *x1 = (-b - discr_sqrt)/a_double;
        *x2 = (-b + discr_sqrt)/a_double;
        if (*x1 > *x2)
        {
            double temp = *x1;
            *x1 = *x2;
            *x2 = temp;
        }
    }
}

void SqrEqSolverMode()
{
    printf("Square equation solver.\n");
    while (1 > 0)
    {
        double a = 0, b = 0, c = 0, discr = 0, x1 = 0, x2 = 0;
        int nRoots = 0;
        int ModeSelection = 0;
        printf("To solve your square equation enter 1.\n");
        printf("To start tests enter 2.\n");
        printf("To stop the program enter any other value.\n");
        if (scanf("%d", &ModeSelection) != 1)
        {
            CleaningBuffer();
            printf("Program ended");
            break;
        }
        else if (ModeSelection == 1)
        {
            CleaningBuffer();
            if (SolverInput(&a, &b, &c) == 0)
                break;

            SolveSolution(a, b, c, &discr, &x1, &x2, &nRoots);

            SolverOutput(x1, x2, nRoots);
            continue;
        }
        else if (ModeSelection == 2)
        {
            CleaningBuffer();
            if (TestSqrEq() == 25)
            {
                printf("The program works correctly.\n");
                printf("\n");
                continue;
            }
            else
            {
                printf("The program does not works correctly.\n");
                printf("Try to use it later.\n");
                printf("\n");
                break;
            }
        }
        else
            CleaningBuffer();
            printf("Program ended");
        break;
    }
}

int SolverInput(double *a, double *b, double *c)
{
    ASSERT(a);
    ASSERT(b);
    ASSERT(c);
    int i;
    printf("Enter coefficients:\n");
    for (i = 0; i < 5; i++) {
        if (scanf("%lg %lg %lg", a, b, c) != 3)
        {
            printf("Format error.\n");
            CleaningBuffer();
            if (i < 4)
                printf("Enter coefficients again:\n");
        }
        else
        {
            if (isfinite(*a) && isfinite(*b) && isfinite(*c))
            {
                CleaningBuffer();
                return 1;
            }
            else
            {
                printf("Format error.\n");
                CleaningBuffer();
                if (i < 4)
                    printf("Enter coefficients again:\n");
                continue;
            }
        }
    }
    return 0;
}
int SolveSolution(double a, double b, double c, double *discr, double *x1, double *x2, int *nRoots)
{
    ASSERT(discr);
    ASSERT(x1);
    ASSERT(x2);
    ASSERT(nRoots);
    if (isDoubleZero(a))
    {
        *nRoots = LinNumOfRoots(b, c);
        LinearSolver(b, c, x1, x2);
    }
    else
    {
        *discr = b * b - 4 * a * c;
        *nRoots = SqrNumOfRoots(*discr);
        SquareSolver(a, b, *discr, x1, x2);
    }
}
void SolverOutput(double x1, double x2, int nRoots)
{
    switch (nRoots)
    {
        case NO_ROOTS :
            printf("No roots\n");
            break;
        case ONE_ROOT :
            printf("1 root: %lg\n", x1);
            break;
        case TWO_ROOTS :
            printf("2 roots: %lg %lg\n", x1, x2);
            break;
        case INF_ROOTS :
            printf("Any root\n");
            break;
        default:
            break;
    }
    printf("\n");
}
