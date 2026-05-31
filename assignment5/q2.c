#include <stdio.h>
#define MAXSIZE 100

//declaring function
int MaxMinDiff(int arr[], int n);

int main (){
	//prompting and receiving user input
	int n;
	printf("Enter the number of integers: ");
	scanf("%d", &n);

	//declaring array and getting array input
	int a[MAXSIZE];
	printf("Enter the integers separated by space: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	//printing output
	printf("Difference between max and min: %d\n", MaxMinDiff(a, n));
	return 0;
}

int MaxMinDiff(int arr[], int n){
	//declaring variable
	int max = arr[0];
	int min = arr[0];

	for (int i = 0; i < n; i++){
		//update min or max if new min or max is found
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}

	return max - min; //return difference of max and min
}
