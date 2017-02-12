#include <stdio.h>
#include <math.h>
#include "../main/quadSolver.h"


// Check if values are exactly equal
#define assert_eql(str,a,b) {
  if( a != b ) {
    printf("error %d: %s, %f != %f\n",
              __LINE__ , str ,  a , b );
  }
}
// Check floating point values are equal after being machine rounding
#define assert_eqld(str,a,b) {
  if( a - b > 0 ) {
    printf("error %d: %s, %f != %f\n",
              __LINE__ , str ,  a , b );
  }
}
// Check to see if the value is not a number
#define assert_nan(str,a) {
  if(!isnan(a)) {
    printf("error %d: %s, %f != nan\n",
              __LINE__ , str ,  a);
  }
}
// Check to see if the value is infinity
#define assert_inf(str,a) {
  if(!isinf(a)) {
    printf("error %d: %s, %f != inf\n",
              __LINE__ , str ,  a);
  }
}

int main(int *argc, char **argv)
{
    double a,b,c,x1, x2;
    double ret;

  //Base case
  a = 2.0;
  b = 2.0;
  c = 0.0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eql("x2",x2,-1.0);
  assert_eql("x1",x1,0.0);

  //Base case
  a = 4.0;
  b = -1.0;
  c = -3.0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eql("x1",x1,1.0);
  assert_eql("x2",x2,-0.75);

  //Base case
  a = 4.0;
  b = 5.0;
  c = 1.0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eql("x1",x1,-0.25);
  assert_eql("x2",x2,-1.0);


  // zero
  a = 4;
  b = 2;
  c = 0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eql("x1",x1,0.0);
  assert_eql("x2",x2,-.5);


  // zero
  a = 0;
  b = 0;
  c = 0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_nan("x1",x1);
  assert_nan("x2",x2);


  // zero
  a = 8;
  b = 2;
  c = 0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eql("x1",x1,0.0);
  assert_eql("x2",x2,-0.35);


  // floating point
  a = 2.5;
  b = 4;
  c = -3;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eqld("x1",x1,0.6081824);
  assert_eqld("x2",x2, -1.2331824);


  // floating point
  a = 1.5;
  b = 4;
  c = 2;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eqld("x1",x1,-0.66666666);
  assert_eql("x2",x2, -2.0);


	// floating point
  a = -4.5;
  b = 4.3;
  c = 7.8;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eqld("x1",x1,-0.922795297);
  assert_eqld("x2",x2, 1.878351);


	// floating point
	a = -2;
  b = 5.2;
  c = -2;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eqld("x1",x1, 0.469338);
  assert_eqld("x2",x2, 2.1306624);


	// floating point
	a = 2.2;
  b = -3.2;
  c = 0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_eqld("x1",x1, 1.4545455);
  assert_eql("x2",x2, 0.0);


  // nan
	a = sqrt (-1);
  b = 2;
  c = 0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,3.0);
  assert_nan("x1", x1);
  assert_nan("x2", x2);


  // nan
	a = sqrt (-1);
  b = sqrt (-1);
  c = sqrt (-1);
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,3.0);
  assert_nan("x1", x1);
  assert_nan("x2", x2);


	// nan
	a = 9;
  b = 32;
  c = 62;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,2.0);
  assert_nan("x1", x1);
  assert_nan("x2", x2);


	// nan
	a = 4;
  b = 3;
  c = 6;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,2.0);
  assert_nan("x1", x1);
  assert_nan("x2", x2);


	//nan
	a = 2;
  b = sqrt (-1);
  c = 0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret, 3.0);
  assert_nan("x1", x1);
  assert_nan("x2", x2);


	//infinity
	a = 2;
  b = INFINITY;
  c = 0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,4.0);
  assert_nan("x1", x1);
  assert_inf("x2", x2);



	//infinity
	a = INFINITY;
  b = INFINITY;
  c = 0;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_nan("x1", x1);
  assert_nan("x2", x2);


	//infinity
	a = 23;
  b = 23;
  c = INFINITY;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,2.0);
  assert_nan("x1", x1);
  assert_nan("x2", x2);


  //infinity
	a = INFINITY;
  b = INFINITY;
  c = INFINITY;
  ret = qsolv(a,b,c, &x1, &x2);
  assert_eql("ret",ret,0.0);
  assert_nan("x1", x1);
  assert_nan("x2", x2);

  return 0;
}
