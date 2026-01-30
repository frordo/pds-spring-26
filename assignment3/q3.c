#include <stdio.h>

int main(){
	//getting user input (number of terms in fibonacci sequence)
	int n;
	printf("Enter the number of terms: "); //prompting user
	scanf("%d", &n);

	int f0 = 0, f1 = 1; //initial conditions for fibonacci sequence, ie first two terms are 0 and 1
	int f = 0;
	for (int i = 0; i<n-2; i++){//looping n-2 times as 0 and 1 are first two terms, n terms in total
		f = f0 + f1; //using recurrence formula for fibonacci sequence f_n = f_(n-1) + f_(n-2)
		f0 = f1; 
		f1 = f; //assigning values to be used in next iteration. (f0, f1) becomes (f1, f0+f1)

		for (int i = f0 + 1; i < f1; i++){
			//i goes from one fibonacci number to the next, both excluded as we do not want to print them
			printf("%d\t",i); //printing with tab spacing
		}
	}
	printf("\n");
	return 0;
}
