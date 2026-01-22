#include <stdio.h>
int main(){
	//getting user input
	int d, m, y;
	printf("Enter the date: ");
	scanf("%d", &d);
	printf("Enter the month: ");
	scanf("%d", &m);	
	printf("Enter the year: ");
	scanf("%d", &y);
	
	//checking months: jan, mar, may, jul, aug, oct, dec
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){ 
		//checking for more than 31 days or less than 1 day
		if (d > 31 || d<1){
			printf("The date is invalid (0)"); 
		}
		else{
			printf("The date is valid (1)");
		}
	}
	//checking months: apr, jun, sep, nov
	else if (m == 4 || m == 6 || m == 9 || m == 11){
		//checking for more than 30 days or less than 1 day
		if (d > 30 || d<1){
			printf("The date is invalid (0)"); 
		}
		else{
			printf("The date is valid (1)");
		}
	}
	//checking feb
	else if (m == 2){
		//checking leap year
		if ((y%400 == 0) || ((y%4 == 0) && (y%100 != 0))){
			//checking for more than 29 days (leap year) or less than 1 day
			if (d > 29 || d<1){
				printf("The date is invalid (0)"); 
			}
			else{
				printf("The date is valid (1)");
			}
		}
		else{
			//checking for more than 28 days (not leap year) or less than 1 day
			if (d > 28 || d<1){
				printf("The date is invalid (0)"); 
			}
			else{
				printf("The date is valid (1)");
			}
		}
	}
	//month has to be a number from 1 to 12
	else{
		printf("Input correct m"); 
	}
	printf("\n");
	return 0;
}
