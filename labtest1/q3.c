#include <stdio.h>
#define MAX_SIZE 100 //maximum size is given to be 100

int main(){
	int n, i = 0, temp; //declaring variables
	printf("Enter number of elements: "); //prompting user input
	scanf("%d", &n);

	int a[MAX_SIZE];
	printf("Enter elements of array: "); //prompting array input 

	while (i < n){
		scanf("%d", &temp);
		if (temp == 1 || temp == 2 || temp == 3){
			//if number is 1, 2, or 3 allowing
			a[i] = temp;
			i++;
		}
		else{
			printf("Enter 1, 2, or 3: ");
			//asking user to input correct numbers
		}
	}

	int oneIndex = -1, twoIndex = -1, threeIndex = -1;
	int longestOne = 0, longestTwo = 0, longestThree = 0; //declaring variables

	for (int i = 0; i < n; i++){
		temp = 1;
		for (int j = i+1; j < n; j++){
			if (a[i] == a[j]){
				temp++; //checking if consecutive number is equal
			}
			if (a[i] == 1 && temp >= longestOne){
					//setting index of longest sequence of ones
					longestOne = temp;
					oneIndex = i;
				}
			if (a[i] == 2 && temp >= longestTwo){
				//setting index of longest sequence of twos
				longestTwo = temp;
				twoIndex = i;
			}
			if (a[i] == 3 && temp >= longestThree){
				//setting index of longest sequence of threes
				longestThree = temp;
				threeIndex = i;
			}

			if (a[i] != a[j]){
				temp = 0;
				break;
			}
		}
	}

	//checking singleton elements
	for (int i = 0; i < n; i++){
		if (threeIndex == -1 && a[i] == 3) threeIndex = i;
		if (twoIndex == -1 && a[i] == 2) twoIndex = i;
		if (oneIndex == -1 && a[i] == 1) oneIndex = i;
	}
	
	//printing output
	printf("Start of the longest consecutive sequence of 1: %d\n", oneIndex);
	printf("Start of the longest consecutive sequence of 2: %d\n", twoIndex);
	printf("Start of the longest consecutive sequence of 3: %d\n", threeIndex);

	return 0;
}
