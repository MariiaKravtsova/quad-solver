/**@file adder.c
 * @brief A simple adder
 * @date 3/20/14
 * @author Owen Watson
 *
 * ##Description
 * This is the fucntion declaration for add. The fucntion adds two numbers 
 * together and returns the results. Quite possibly the most interesting code
 * in the world.
 *
 */

#include <stdio.h>
#include "lib.h"

/**
 * @brief Brief Description: main function runs the adder
 * 
 * ##Description
 * This is the amazing add fucntion in action.  It takes two integer terms
 * (e.g 4 and 7) and adds them together. This produces the sum of those two
 * terms! Science at it's finest.
 *
 * @param argc (argument count) the number of arguments entered
 * @param argv (argument vector) an array of pointer to arrays of char objects
 *
 * @return zero... unless error occurs
 */
int main(int argc, char** argv)
{
	printf("3+4=%d\n",add(3,4));
	return 0;
}