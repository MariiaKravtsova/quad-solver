#include "parse.h"

int main(int argc, char * argv[]){
	char* str = "1 2 3";
	double a, b, c;

	parse(&a,&b,&c,str);
}

int parse(double* a, double* b, double*c, char* str){
	char* token;
	token = strtok(str," ");
	
}