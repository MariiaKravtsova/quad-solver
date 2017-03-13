#include "fp_spike.h"

float test1(float a, float b){
	return a * b;
}

float test2(float a, float b){
	double aD = (double) a;
	double bD = (double) b;
	double answer = aD * bD;
	return answer;
}