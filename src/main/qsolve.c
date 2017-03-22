// FILE: qsolve.c

#include "qsolve.h"

#ifdef LOG
static FILE *fp ;
#endif

int main(int argc, char *argv[]){

	// set up logging
	#ifdef LOG
	fp = fopen("log.txt", "w");
	fprintf(fp,"Opening the log file. \n");
	fprintf(fp,"Running the main function in qsolve.c\n");
	#endif

	// declare variables
	double a, b, c;
	double nums[3];
	double roots[2];
	
	// get input
	#ifdef LOG
	fprintf(fp,"Grabbing input \n");
	#endif

	char * inLine = malloc(100);
	size_t inSize = 100;

	// process input ...
	if(input(inLine, inSize)==0){
		#ifdef DEBUG
		printf("input(0): %s\n", inLine);
		#endif

		// parse and validate input
		#ifdef LOG
		fprintf(fp,"Parsing line and checking for valid input\n");
		#endif
	
		if (parse(inLine,nums) == 0){
			#ifdef DEBUG
			printf("a: %f\n",nums[0]);
			printf("b: %f\n",nums[1]);
			printf("c: %f\n",nums[2]);
			#endif

			#ifdef LOG
			fprintf(fp,"Solving quadratic function \n");
			#endif

			solve(nums,roots);
			output((float) roots[0], (float) roots[1]);

		}
		#ifdef LOG
		fprintf(fp,"Closing Log File\n");
		fclose(fp);
		#endif

	} 


}

void solve(double nums[], double roots[]){

	#ifdef LOG
	fprintf(fp,"Inside the solve function \n");
	#endif
	
	#ifdef DEBUG
		printf("nums[0]: %f\n",nums[0]);
		printf("nums[1]: %f\n",nums[1]);
		printf("nums[2]: %f\n",nums[2]);
	#endif

	double tmp = (nums[1] * nums[1]) - (4 * nums[0] * nums[2]);
	tmp = mysqrt(tmp);
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

