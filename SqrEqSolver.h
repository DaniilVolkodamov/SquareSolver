#ifndef UNTITLED3_SQREQSOLVER_H
#define UNTITLED3_SQREQSOLVER_H
#define SMALL_NUMBER 1e-15
#define ASSERT(condition) \
{ \
if (!(condition)) \
printf("Error in %s, in line %d, in file %s, in function %s\n", #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__); \
}

enum NUMBERS
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS,
};

int isDoubleEq(double arg1, double arg2);
int isDoubleZero(double arg);

void CleaningBuffer();

int TestSqrEq();
int OneSqrEqTest(double a_test, double b_test, double c_test, int nRoots_test, double x1_test, double x2_test);

int LinNumOfRoots(double b, double c);
int SqrNumOfRoots(double discr);

void LinearSolver(double b, double c, double *x1, double *x2);
void SquareSolver(double a, double b, double discr, double *x1, double *x2);

void SqrEqSolverMode();

int SolverInput(double *a, double *b, double *c);
int SolveSolution(double a, double b, double c, double *discr, double *x1, double*x2, int *nRoots);
void SolverOutput(double x1, double x2, int nRoots);

#endif //UNTITLED3_SQREQSOLVER_H
