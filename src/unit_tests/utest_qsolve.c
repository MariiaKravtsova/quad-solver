
#include "utest.h"
#include "../qsolve/qsolve.h"

int main(int argc, char *argv[]){

	// Open file to log results
	char * filename = "unit_tests/test_log.txt";
	FILE * tlog = NULL;
    tlog = fopen(filename, "a");
    if (tlog == NULL)
    {
        printf("ERROR: failed to open log file");
        return -1;
    } else fprintf(tlog, "Starting Unit Tests: qsolve\n");


	// Declare variables
	double result = 0;
	double nums[3];
	double roots[2];
	int eCount = 0;

	// TEST 1 - good input
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 1;
	result = qsolve(nums,roots);;
	if(result != 0){					// check result flag
		fprintf(tlog,"Test 1 Failed: result flag '1 2 1'\n");
		eCount++;
	} 
	if((roots[0] > -0.9999) || (roots[0] < -1.0001)){					// check result flag
		fprintf(tlog,"Test 1 Failed: bad root: %f (should be -1)\n", roots[0]);
		eCount++;
	} 
	if((roots[1] > -0.9999) || (roots[1] < -1.0001)){					// check result flag
		fprintf(tlog,"Test 1 Failed: bad root: %f (should be -1)\n", roots[1]);
		eCount++;
	} 

	// TEST 2 - bad input - complex roots
	nums[0] = 1;
	nums[1] = 1;
	nums[2] = 1;
	result = qsolve(nums,roots);;
	if(result != -1){					// check result flag
		fprintf(tlog,"Test 2 Failed: result flag '1 1 1'\n");
		eCount++;
	} 
	


	// Close log file
	fprintf(tlog, "Error Count: %d\n",eCount);
	fprintf(tlog, "End of Unit Tests: qsolve\n\n");
    fclose(tlog);

}
