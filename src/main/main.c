// FILE: main.c

#include "main.h"

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

		while(parse(inLine,nums) != 0){
			printf("Invalid Input - please re-enter\n");
			input(inLine, inSize);
		}
	
		#ifdef DEBUG
		printf("a: %f\n",nums[0]);
		printf("b: %f\n",nums[1]);
		printf("c: %f\n",nums[2]);
		#endif

		#ifdef LOG
		fprintf(fp,"Solving quadratic function \n");
		#endif

		int result = qsolve(nums,roots);

		if(result==0){
			output((float) roots[0], (float) roots[1]);
		} else if (result == -1){
			printf("Invalid Output - square of negative\n");
		} else printf("Invalid Output\n");
		

		

		#ifdef LOG
		fprintf(fp,"Closing Log File\n");
		fclose(fp);
		#endif

	} 


}



