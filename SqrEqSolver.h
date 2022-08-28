#ifndef UNTITLED3_SQREQSOLVER_H
#define UNTITLED3_SQREQSOLVER_H
#define SMALL_NUMBER 1e-15
#define NUMBER_OF_TESTS 25
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


/**
 * @brief Checks if two doubles are equal.
 * @param arg1 First number.
 * @param arg2 Second number.
 * @return 1 if doubles are equal and 0 if not.
 */
int isDoubleEq(double arg1, double arg2);

/**
 * @brief Checks if double number is equal zero.
 * @param arg Double number.
 * @return 1 if double equal zero and 0 if not.
 */
int isDoubleZero(double arg);


/**
 * @brief Clears the buffer.
 */
void CleaningBuffer();


/**
 * @brief Runs 25 tests and displays error information.
 * @return Number of successfully passed tests.
 */
int TestSqrEq();

/**
 * @brief Runs 25 tests from a file and displays error information.
 * @return Number of successfully passed tests.
 */
int FTestSqrEq();

/**
 * @brief Runs one test.
 * @detailed Solves the equation by given coefficients and compares the result with the correct answer.
 * @param a_test First coefficient of the quadratic equation.
 * @param b_test Second coefficient of the quadratic equation.
 * @param c_test Third coefficient of the quadratic equation.
 * @param nRoots_test Correct number of roots.
 * @param x1_test Correct first root.
 * @param x2_test Correct second root.
 * @throw Failed, Expected If the results do not match the correct answer, function displays error information.
 * @return 1 if number of roots and their values match the correct ones and 0 if not.
 */
int OneSqrEqTest(double a_test, double b_test, double c_test, int nRoots_test, double x1_test, double x2_test);


/**
 * @brief Finds number of roots of a linear equation.
 * @param b First coefficient of the linear equation.
 * @param c Second coefficient of the linear equation.
 * @return Number of roots.
 */
int LinNumOfRoots(double b, double c);

/**
 * @brief Finds number of roots of a quadratic equation.
 * @param discr Discriminant value.
 * @return Number of roots.
 */
int SqrNumOfRoots(double discr);


/**
 * @brief Solves the linear equation
 * @param b First coefficient of the linear equation.
 * @param c Second coefficient of the linear equation.
 * @param x1 Linear equation root.
 */
void LinearSolver(double b, double c, double *x1);

/**
 * @brief Solves the quadratic equation
 * @param a First coefficient of the quadratic equation.
 * @param b Second coefficient of the quadratic equation.
 * @param c Third coefficient of the quadratic equation.
 * @param discr Discriminant value.
 * @param x1 First root.
 * @param x2 Second root.
 */
void SquareSolver(double a, double b, double c, double discr, double *x1, double *x2);


/**
 * @brief Allows the user to select the mode of the program.
 * @detailed Function asks for some value: 1 - solves the user equation, 2 - runs tests,
 * 3 - runs tests from a file, 4 - runs random test, any other value - stops the program.
 */
void SqrEqSolverMode();


/**
 * @brief Gets 3 doubles for a, b, c coefficients.
 * @detailed Gives the user 5 attempts to enter. If all are unsuccessful, the program stops.
 * @param a First coefficient of the quadratic equation.
 * @param b Second coefficient of the quadratic equation.
 * @param c Third coefficient of the quadratic equation.
 * @return 1 if the input is successful and 0 if not.
 */
int SolverInput(double *a, double *b, double *c);

/**
 * @brief Determines the form of the equation and solves it.
 * @param a First coefficient of the quadratic equation.
 * @param b Double coefficient of the quadratic equation.
 * @param c Third coefficient of the quadratic equation.
 * @param discr Discriminant.
 * @param x1 First root.
 * @param x2 Second root.
 * @param nRoots Number of roots.
 * @throw FormatError If the entered values are not numbers.
 */
void SolveSolution(double a, double b, double c, double *discr, double *x1, double*x2, int *nRoots);

/**
 * @brief Prints the number of roots and their values.
 * @param x1 First root.
 * @param x2 Second root.
 * @param nRoots Number of roots.
 */
void SolverOutput(double x1, double x2, int nRoots);


/**
 * @brief Runs the solution of an equation with random coefficients and displays the number of roots and their values.
 */
void RandomTest();


/**
 * @brief Informs the user that the program is working correctly/incorrectly
 * @param TestsNumber The number of correctly completed tests.
 * @return 1 if all tests are correct and 0 if not.
*/
int TestDiagnostics(int TestsNumber);
#endif //UNTITLED3_SQREQSOLVER_H
