#include <stdio.h>

int main(){
	float rate, principal, final_amt;

	rate = 12;
	principal = 100000;
	//years = 3;

	//compound interest formula
	final_amt = principal*(1+rate/100)*(1+rate/100)*(1+rate/100);
	printf("The total amount is: %f\n",final_amt);
	return 0;
}
