#include <stdio.h>
#include <math.h>
#include "SqrEqSolver.h"
#include <cstdlib>

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

    okTests += OneSqrEqTest(  0,   0,   0, INF_ROOTS,    0,   0);
    okTests += OneSqrEqTest(  0,   0,  -4,  NO_ROOTS,    0,   0);
    okTests += OneSqrEqTest(  0,  -8,   0,  ONE_ROOT,    0,   0);
    okTests += OneSqrEqTest(  0,   5,  -5,  ONE_ROOT,    1,   0);
    okTests += OneSqrEqTest(174,   0,   0,  ONE_ROOT,    0,   0);
    okTests += OneSqrEqTest(  1,   0,  -4, TWO_ROOTS,   -2,   2);
    okTests += OneSqrEqTest(  8,   4,   0, TWO_ROOTS, -0.5,   0);
    okTests += OneSqrEqTest(  1, -14,  48, TWO_ROOTS,    6,   8);
    okTests += OneSqrEqTest(  1,   6,   9,  ONE_ROOT,   -3,  -3);
    okTests += OneSqrEqTest(  1,   1,   1,  NO_ROOTS,    0,   0);
    okTests += OneSqrEqTest(  2,  -3,   1, TWO_ROOTS,  0.5,   1);
    okTests += OneSqrEqTest( -1, -15, -50, TWO_ROOTS,  -10,  -5);
    okTests += OneSqrEqTest(  1,   2,   5,  NO_ROOTS,    0,   0);
    okTests += OneSqrEqTest(  0,  10,  -8,  ONE_ROOT,  0.8,   0);
    okTests += OneSqrEqTest(  1,  -8,  16,  ONE_ROOT,    4,   4);
    okTests += OneSqrEqTest(  0,  -2,  -6,  ONE_ROOT,   -3,   0);
    okTests += OneSqrEqTest(  1, -16,  63, TWO_ROOTS,    7,   9);
    okTests += OneSqrEqTest(  7,   5,   6,  NO_ROOTS,    0,   0);
    okTests += OneSqrEqTest( -1,  -4,  -4,  ONE_ROOT,   -2,  -2);
    okTests += OneSqrEqTest( -0,  -0,  -0, INF_ROOTS,    0,   0);
    okTests += OneSqrEqTest(  5,   1,  -4, TWO_ROOTS,   -1, 0.8);
    okTests += OneSqrEqTest(0.5,  -3, 4.5,  ONE_ROOT,    3,   3);
    okTests += OneSqrEqTest( -0,  -0, 154,  NO_ROOTS,    0,   0);
    okTests += OneSqrEqTest(  0,  12, 600,  ONE_ROOT,  -50,   0);
    okTests += OneSqrEqTest( -0, 963,  -0,  ONE_ROOT,    0,   0);

    printf("Successfully completed tests: %d/%d.\n", okTests, NUMBER_OF_TESTS);

    return okTests;
}

int FTestSqrEq()
{
    int okTests = 0, i = 0;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int nRoots = 1;

    FILE *tests = 0;
        tests = fopen("C:/Projects/SquareEquationSolver/Project/SqrEqTests.txt", "r");
    for (i = 0; i < 25; i++)
    {
        fscanf(tests, "%lg %lg %lg %d %lg %lg", &a, &b, &c, &nRoots, &x1, &x2);
        okTests += OneSqrEqTest(a, b, c, nRoots, x1, x2);
    }
    fclose(tests);

    printf("Successfully completed tests: %d/%d.\n", okTests, NUMBER_OF_TESTS);

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
        "Expected: nRoots = %d, x1 = %lg, x2 = %lg\n",\
         a_test, b_test, c_test, nRoots, x1, x2, nRoots_test, x1_test, x2_test);
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


void LinearSolver(double b, double c, double *x1)
{
    ASSERT(x1);

    if (isDoubleZero(b) == 0)
    {
        *x1 = -c/b;
    }
}

void SquareSolver(double a, double b, double c, double discr, double *x1, double *x2)
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

    while (1 > 0)
    {
        double a = 0, b = 0, c = 0, discr = 0, x1 = 0, x2 = 0;
        int nRoots = 0;
        int ModeSelection = 0;

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
            if (TestDiagnostics(TestSqrEq()))
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (ModeSelection == 3)
        {
            CleaningBuffer();
            if (TestDiagnostics(FTestSqrEq()))
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (ModeSelection == 4)
        {
            CleaningBuffer();
            RandomTest();

            continue;
        }
        else
            CleaningBuffer();
            printf("Program ended.");

        break;

    }
}


int SolverInput(double *a, double *b, double *c)
{
    ASSERT(a);
    ASSERT(b);
    ASSERT(c);

    int i = 0;

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

void SolveSolution(double a, double b, double c, double *discr, double *x1, double *x2, int *nRoots)
{
    ASSERT(discr);
    ASSERT(x1);
    ASSERT(x2);
    ASSERT(nRoots);

    if (isDoubleZero(a))
    {
        *nRoots = LinNumOfRoots(b, c);
        LinearSolver(b, c, x1);
    }
    else
    {
        *discr = b * b - 4 * a * c;
        *nRoots = SqrNumOfRoots(*discr);
        SquareSolver(a, b, c, *discr, x1, x2);
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
    }

    printf("\n");
}


void RandomTest()
{
    double a = rand(), b = rand(), c = rand(), discr = 0, x1 = 0, x2 = 0;
    int nRoots = 0;

    printf("Coefficients: %lg %lg %lg\n", a, b, c);

    SolveSolution(a, b, c, &discr, &x1, &x2, &nRoots);
    SolverOutput(x1, x2, nRoots);
}


int TestDiagnostics(int TestsNumber)
{
    if (TestsNumber == NUMBER_OF_TESTS)
    {
        printf("The program works correctly.\n");
        printf("\n");

        return 1;
    }
    else
    {
        printf("The program does not works correctly.\n");
        printf("Try to use it later.\n");
        printf("\n");

        return 0;
    }
}
