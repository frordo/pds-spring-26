#include <stdio.h>

int main(){
	long long int n; //long long for no overflow
	printf("Enter the number: "); //prompting user input
	scanf("%lld", &n);

	int c = 0, temp = n;
	//getting length of number
	while (temp){
		temp/=10; //dividing until temp is zero
		c++;
	}

	int a[c]; //storing the number in an array for easy access
	for (int i = 0; i < c; i++){
		a[i] = n%10; //getting digits
		n/=10;
	}

	int max = 0, len = 1, flag = -1; //declaring variables
	//flag = 0 -> previous check was a_i-1 < a_i (increasing)
	//flag = 1 -> previous check was a_i-1 > a_i (decreasing)

	for (int i = 1; i < c; i++){

		if (a[i-1] == a[i]) continue; //if element is equal skip it
		if (a[i-1] > a[i]) flag = 1; 
		if (a[i-1] < a[i]) flag = 0; //setting flag to correct value
		len = 2; //starting from 2 as there are already two elements (i-1 and i)

		for (int j = i+1; j < c; j++){
			if (len >= max){
				max = len; //updating max length
				if (j == c-1) max++; //as we do not update max for last element
			}
			if (a[j-1] == a[j]) break; //skip equal elements
			if (a[j-1] > a[j] && flag == 1) break; //wrong flag, same comparison as previous
			if (a[j-1] < a[j] && flag == 0) break; //wrong flag, same comparison as previous

			if (a[j-1] > a[j] && flag == 0){
				len++; //incrementing length
				flag = 1; //flipping flag variable
			}

			if (a[j-1] < a[j] && flag == 1){
				len++; //incrementing length
				flag = 0; //flipping flag variable
			}
		}
	}

	printf("Maximum length of valid alternating run is %d.\n", max); //printing output
	return 0;
}
