// FILE: io.c

#include "../main/main.h"

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

void output(float root1, float root2){

	if(root1 != root1){
		printf("ROOT1: COMPLEX\n");
	} else printf("ROOT1: %f\n", root1);
	
	if(root2 != root2){
		printf("ROOT2: COMPLEX\n");
	} else printf("ROOT2: %f\n", root1);
}