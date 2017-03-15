// FILE: qsolve.h

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../parse/parse.h"

//#define DEBUG
#define LOG

// prototypes
int input(char * line, size_t size);
//int parse(char * line, double * a, double * b, double * c);
//int parse(char * line, double nums[]);
void solve(double nums[], double roots[]);
void output(float root1, float root2);