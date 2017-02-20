#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define BUFFER_SIZE 512

/*
 *	@file quadratic.c
 *	@date 2-19-14
 *	@brief Contains main logic for solving quadratic function.
 */

// Used to return the roots for the quadratic equation
typedef struct 
{
	long double	x1;
	long double	x2;
} Roots;

typedef struct
{
	long double a;
	long double b;
	long double c;
	int input;
} Terms;

/*
 * Calculates the square root term of the quadratic equation, and returns
 * it as a long double. 
 * @param a
 * @param b
 * @param c
 */
long double calcSqrt(long double a, long double b, long double c)
{
	return sqrt((b*b) - (4 * a * c));
} 

/*
 * Calculates the entire equation, using the square root value that comes
 * from the calcSqrt() function.
 * @param root
 * @param b
 * @param c
 */
long double eqn(long double root, long double a, long double b)
{
	return ( ( (b * -1) + root) / (2 * a));
}

/*
 * Takes all three terms from the main function, finds the square root term
 * using the calcSqrt() function, checks if the sqaure root term is Not a 
 * Number, and if not, it sends both the positive and negative versions of 
 * the equation to the eqn() function.
 * @param a
 * @param b
 * @param c
 */
Roots eqnControl(long double a, long double b, long double c)
{
	long double sqRoot;
	Roots returnRoot;
	sqRoot = calcSqrt(a, b, c);

	if (isnan(sqRoot))
		printf("Not a Number\n");
	else if (isinf(sqRoot))
		printf("Infinite\n");
	else
	{
		returnRoot.x1 = eqn(sqRoot, a, b);
		returnRoot.x2 = eqn((sqRoot * -1), a, b);
	}
	return returnRoot;
}

/*
 * Validates the input values, they must be doubles.
 * @param aInput
 * @param bInput
 * @param bInput
 */
Terms validateInput(char *aInput, char *bInput, char *cInput)
{
	Terms terms;
	sscanf(aInput, "%Lf", &terms.a);
	sscanf(bInput, "%Lf", &terms.b);
	sscanf(cInput, "%Lf", &terms.c);

	// Validate input 
	if (terms.a != HUGE_VAL && terms.a != -HUGE_VAL &&
		terms.b != HUGE_VAL && terms.b != -HUGE_VAL &&
		terms.c != HUGE_VAL && terms.c != -HUGE_VAL)
	{
		terms.input = 1;
		return terms;
	}
	else
	{
		terms.input = -1;
		return terms;
	}
}

FILE* openLog(char *fileName)
{
	FILE *logFile = fopen(fileName, "rw+");
	if (logFile == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	else
		return logFile;
}

void closeLog(FILE *logFile)
{
	fclose(logFile);
}