#include <stdio.h>
#define MAX_SIZE 30 //maximum size of 30 is given

int main(){
	int n, isDuplicate = 0;;
	float sum = 0; //declaring variables, sum is a float
	printf("Enter the number of elements: "); //prompting user input
	scanf("%d", &n);

	float a[MAX_SIZE];
	printf("Enter the elements of the array: "); //getting user input for array
	for (int i = 0; i < n; i++){
		scanf("%f", &a[i]);
	}

	printf("Sum of unique elements ( "); //printing out first part of output

	for (int i = 0; i < n; i++){
		isDuplicate = 0;
		//checking if a number is duplicate by comparing with rest of array
		for (int j = 0; j < n; j++){
			if ((a[i] == a[j]) && (i != j)){
				//checking if any other element of array is same as a[i] and marking it as duplicate
				isDuplicate = 1;
				break;
			}
		}
		if (!isDuplicate){
			//if number is not duplicate, print it and add it to the sum
			printf("%f ", a[i]);
			sum += a[i];
		}
	}
	
	printf(") is %f\n", sum); //printing the sum
	return 0;
}
