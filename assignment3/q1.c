#include <stdio.h>

int main(){
	//getting user input
	int n;
	printf("Enter an integer between 1 and 9: "); //prompting user for input
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){//looping n times, one for each row

		//printing the number i, i times
		for (int j = 0; j < i; j++){
			printf("%d ",i); //printing number and leaving space for next number
		}

		//each line has 2n total characters, of which 2i are numbers, so rest (2n - 2i) are spaces
		for (int j = 0; j < 2*(n-i); j++){
			printf("  "); //spaces to continue the pattern
		}

		//printing the number i, i times
		for (int j = 0; j < i; j++){
			printf("%d ",i); //printing number and leaving space for before number
		}
	
	printf("\n");
	}
	return 0;
}
