#include "parse.h"

int parse(char * line, double nums[]){
	char* token;
	char* temp;
	int result = 0;
	token = strtok(line," ");
	int count=-1;
	//nums=malloc(sizeof(double)*3);

	while(token != NULL){
		count++;
		nums[count] = atof(token);
		if (nums[count]  != nums[count]) result = -1; // check for NaN
		
		token = strtok(NULL," ");
	}
	#ifdef DEBUG
		printf("nums[0]: %f\n",nums[0]);
		printf("nums[1]: %f\n",nums[1]);
		printf("nums[2]: %f\n",nums[2]);
	#endif

	if (count < 0) result = -2;
	if (count > 2) result = -3;

	return result;
}