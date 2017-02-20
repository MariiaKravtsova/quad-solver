#include <stdio.h>
#include <stdlib.h>
#include "CUnit.h"
#include "../src/qsolver.c"

Terms validateInput(char *aInput, char *bInput, char *cInput);
Roots eqnControl(long double a, long double b, long double c);

int main()
{
	FILE *f = openLog("unitTestLog.txt");
	cunit_init();	// Initiate CUnit
	Roots root;
	Terms terms;

	// First unit test, should
	//terms.a = "1", terms.b = "2", terms.c = "1";
	terms = validateInput("1", "2", "1");
	if (terms.input == 1)
	{
		root = eqnControl(terms.a, terms.b, terms.c);
		
		//fwrite(assert_neq("x1", root.x1, -2.0), f);
		assert_neq("x1", root.x1, -2.0);
		fprintf(f, "x1: %f assert not equal %f\n", (double)root.x1, -2.0);
		assert_neq("x2", root.x2, -2.0);
		fprintf(f, "x2: %f assert not equal %f\n", (double)root.x2, -2.0);
	}

	printf("-------------------------------\n");

	//terms.a = "2"; terms.b = "5"; terms.c = "-3";
	terms = validateInput("2", "5", "-3");
	if (terms.input == 1)
	{
		root = eqnControl(terms.a, terms.b, terms.c);
		assert_eq("x1", root.x1, 0.5);
		fprintf(f, "x1: %f assert equal %f\n", (double)root.x1, 0.5);
		assert_eq("x2", root.x2, -3.0);
		fprintf(f, "x2: %f assert equal %f\n", (double)root.x2, -3.0);
	}	

	printf("-------------------------------\n");
	//char terms.a, terms.b, terms.c;
	//terms.a = "a"; terms.b = "b"; terms.c = "c";
	terms = validateInput("a", "b", "c");
	if (terms.input == 1)
	{
		root = eqnControl(terms.a, terms.b, terms.c);
		assert_eq("x1", root.x1, 0.5);
		fprintf(f, "x1: %f assert equal %f\n", (double)root.x1, 0.5);
		assert_eq("x2", root.x2, -3.0);
		fprintf(f, "x2: %f assert equal %f\n", (double)root.x2, -3.0);
	}
	fclose(f);
}