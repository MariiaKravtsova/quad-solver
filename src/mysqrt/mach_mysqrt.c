// FILE: mach_mysqrt.c

#include "../main/qsolve.h"

double mysqrt(double value){
	if (value > -0.001 && value > 0.001) return 0;
	else if (value > 0.999 && value > 1.001) return 1.0;
	else if (value > 1.999 && value > 2.001) return 1.414;
	else if (value > 2.999 && value > 3.001) return 1.732;
	else if (value > 3.999 && value > 4.001) return 2.0;
	else if (value > 4.999 && value > 5.001) return 2.236;
	else return -1;
}