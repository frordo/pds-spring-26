#include <stdio.h>

int main(){
	float x;
	float sinx, cosx, sin2x;

	printf("The value of x (in radian): ");
	scanf("%f", &x);
	float y = 2*x;

	//using series expansion for 4 terms
	sinx = x - x*x*x / 6 + x*x*x*x*x/120 - x*x*x*x*x*x*x/5040;
	cosx = 1 - x*x / 2 + x*x*x*x/24 - x*x*x*x*x*x/720;
	sin2x = y - y*y*y / 6 + y*y*y*y*y/120 - y*y*y*y*y*y*y/5040; //as y = 2x

	printf("The value of sin(x) is %f\n", sinx); //(a) part
	printf("The value of cos(x) is %f\n", cosx);
	printf("The value of sin(2x) using formula 2sin(x)cos(x) is %f\n", 2*sinx*cosx); //(b) 
	printf("The value of sin(2x) using series is %f\n", sin2x); //(c)

	return 0;
}
