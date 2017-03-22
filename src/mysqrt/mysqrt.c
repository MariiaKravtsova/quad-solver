// FILE: mysqrt.c
#include <math.h>

#include "../main/main.h"

double mysqrt(double value){
	double answer = 0;
	if(value < 0) answer = -1; // return -1 for negative value
	else answer = sqrt(value);
	return answer;
}