#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG
#define LOG

// prototypes
int input(char * line, size_t size);
//int parse(char * line, double * a, double * b, double * c);
int parse(char * line, double nums[]);
void solve(double nums[], double roots[]);
void output(float root1, float root2);

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

int input(char * line, size_t size){

	printf("Enter Input (a b c): ");

	// line = malloc(100);
	// size_t size = 100;
	int result = -1;

	if (fgets(line, size, stdin) == NULL) result = -1;
	else if (line[strlen(line)-1] != '\n') result = -1;
	else {
		line[strlen(line)-1] = '\0';
		result = 0;

		#ifdef DEBUG
		printf("line: %s\n", line);
		#endif
	}
	return result;
}

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

void output(float root1, float root2){

	if(root1 != root1){
		printf("ROOT1: COMPLEX\n");
	} else printf("ROOT1: %f\n", root1);
	
	if(root2 != root2){
		printf("ROOT2: COMPLEX\n");
	} else printf("ROOT2: %f\n", root1);
}