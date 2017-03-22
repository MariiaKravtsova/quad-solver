// FILE: qsolve.c

#include "qsolve.h"

int qsolve(double nums[], double roots[]){

	#ifdef LOG
	fprintf(fp,"Inside the solve function \n");
	#endif

	#ifdef DEBUG
		printf("nums[0]: %f\n",nums[0]);
		printf("nums[1]: %f\n",nums[1]);
		printf("nums[2]: %f\n",nums[2]);
	#endif

	int result = 0;

	double tmp = (nums[1] * nums[1]) - (4 * nums[0] * nums[2]);
	tmp = mysqrt(tmp);

	if(tmp<0) result = -1; // flag square of negative

	tmp = fabs(tmp);
	#ifdef DEBUG
		printf("tmp: %f\n",tmp);
	#endif

	roots[0] = -(nums[1]+tmp)/(2*nums[0]);
	roots[1] = -(nums[1]-tmp)/(2*nums[0]);
	#ifdef DEBUG
		printf("roots[0]: %f\n",roots[0]);
		printf("roots[1]: %f\n",roots[1]);
	#endif

	return result;

}