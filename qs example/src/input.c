#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define BUFFER_SIZE 512

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

// Prototype for qsolver's validateInput method
Terms validateInput(char *aInput, char *bInput, char *cInput);
Roots eqnControl(long double a, long double b, long double c);
FILE* openLog(char *fileName);

/*
 * Contains the logic for user input, casting from user input buffer arrays
 * into long doubles, and provides logic to break the while loop when an 'X'
 * is entered. After the input is cast, it sends the long double terms to the
 * eqnControl() function.
 */
int main(int argc, char *argv[])
{	
	FILE *logger;
	// Check for -l flag, that is argv[1]
	if (argc == 2)
	{
		// If 0, -l flag is true, so turn on logging
		if (strcmp("-l", argv[1]) == 0)
			logger = (FILE*)openLog("inputLog.txt");
	}

	char aInput[BUFFER_SIZE];
	char bInput[BUFFER_SIZE];
	char cInput[BUFFER_SIZE];
	printf("Enter 'X' to quit\n");	

	while (1)
	{
		printf("Enter the a term:\n>");
		fgets(aInput, sizeof (aInput), stdin);
		
		printf("Enter the b term:\n>");
		fgets(bInput, sizeof (bInput), stdin);
		

		printf("Enter the c term:\n>");
		fgets(cInput, sizeof (cInput), stdin);
		
		Terms terms;
		terms = validateInput(aInput, bInput, cInput);
		Roots returnRoot;

		if (terms.input = 1)
		{
			if (aInput[0] == 'x' || aInput[0] == 'X')
				break;
			else if (bInput[0] == 'x' || bInput[0] == 'X')
				break;
			else if (cInput[0] == 'x' || cInput[0] == 'X')
				break;
			else
			{
				returnRoot = eqnControl(terms.a, terms.b, terms.c);

				printf("X1: %.8Lf\n", returnRoot.x1);
				printf("X2: %.8Lf\n", returnRoot.x2);
			}
		}
		else
			printf("No valid doubles could be read from input!\n");
	}

	if (strcmp("-l", argv[1]) == 0)
			closeLog(*logger);
	return 0;
}