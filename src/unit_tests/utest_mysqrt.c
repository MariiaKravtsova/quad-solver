
#include "utest.h"
#include "../mysqrt/mysqrt.h"

int main(int argc, char *argv[]){

	// Open file to log results
	char * filename = "unit_tests/test_log.txt";
	FILE * tlog = NULL;
    tlog = fopen(filename, "a");
    if (tlog == NULL)
    {
        printf("ERROR: failed to open log file");
        return -1;
    } else fprintf(tlog, "Starting Unit Tests: mysqrt\n");


	// Declare variables
	double result = 0;
	double value;
	int eCount = 0;

	// TEST 1 - negative input
	value = -1.234;
	result = mysqrt(value);
	if(result < 0){
		fprintf(tlog,"Test 1 Failed: '-1.234'\n");
		eCount++;
	} 


	// Close log file
	fprintf(tlog, "Error Count: %d\n",eCount);
	fprintf(tlog, "End of Unit Tests: mysqrt\n\n");
    fclose(tlog);

}
