
#include "utest.h"
#include "../parse/parse.h"

int main(int argc, char *argv[]){

	// Open file to log results
	char * filename = "unit_tests/test_log.txt";
	FILE * tlog = NULL;
    tlog = fopen(filename, "a");
    if (tlog == NULL)
    {
        printf("ERROR: failed to open log file");
        return -1;
    } else fprintf(tlog, "Starting Unit Tests: parse\n");


	// Declare variables
	int result = 0;
	double nums[3];
	int eCount = 0;

	// TEST 1 - NaN
	char in1[] = "1 b 3\0";
	result = parse(in1, nums);
	if(result != -1){
		fprintf(tlog,"Test 1 Failed: '1 b 3'\n");
		eCount++;
	} 

	// TEST 2 - not enough data
	char in2[] = "1 2\0";
	result = parse(in2, nums);
	if(result != -2){
		fprintf(tlog,"Test 2 Failed: '1 2'\n");
		eCount++;
	} 

	// TEST 3 - too much data
	char in3[] = "1 2 3 4\0";
	result = parse(in3, nums);
	if(result != -3){
		fprintf(tlog,"Test 2 Failed: '1 2 3 4'\n");
		eCount++;
	} 

	// Close log file
	fprintf(tlog, "Error Count: %d\n",eCount);
	fprintf(tlog, "End of Unit Tests: parse\n\n");
    fclose(tlog);

}
