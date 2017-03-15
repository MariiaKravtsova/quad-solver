// FILE: qsolve.c

#include "qsolve.h"

int main(int argc, char *argv[]){
	double a, b, c;
	double nums[3];
	double roots[2];
	
	// get input
	char * inLine = malloc(100);
	size_t inSize = 100;

	if(input(inLine, inSize)==0){
		#ifdef DEBUG
		printf("input(0): %s\n", inLine);
		#endif

		// parse and validate input
	
		if (parse(inLine,nums) == 0){
			#ifdef DEBUG
			printf("a: %f\n",nums[0]);
			printf("b: %f\n",nums[1]);
			printf("c: %f\n",nums[2]);
			#endif
			solve(nums,roots);
			output((float) roots[0], (float) roots[1]);

		}

	} 


}

void solve(double nums[], double roots[]){

	#ifdef DEBUG
		printf("nums[0]: %f\n",nums[0]);
		printf("nums[1]: %f\n",nums[1]);
		printf("nums[2]: %f\n",nums[2]);
	#endif

	double tmp = (nums[1] * nums[1]) - (4 * nums[0] * nums[2]);
	tmp = sqrt(tmp);
	tmp = fabs(tmp);
	#ifdef DEBUG
		printf("tmp: %f\n",tmp);
	#endif

	roots[0] = (-nums[1]+tmp)/(2*nums[0]);
	roots[1] = (-nums[1]-tmp)/(2*nums[0]);
	#ifdef DEBUG
		printf("roots[0]: %f\n",roots[0]);
		printf("roots[1]: %f\n",roots[1]);
	#endif

}