#include <stdio.h>
#define MAX_SIZE 1000

int main(){
	//getting number of elements as user input
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	int a[MAX_SIZE], x;

	//getting array as user input
	printf("Enter the array elements: ");
	int evenCount = 0, oddCount = 0, i;
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
		//counting number of even and odd elements
		if (a[i]%2 == 0){
			evenCount++;
		}
		else{
			oddCount++;
		}
	}

	//rotating array to left if even count is greater than odd count
	if (evenCount > oddCount){
		x = a[0]; //storing the first element as it will get overwritten
		for (i = 1; i < n; i++){
			a[i-1] = a[i]; //shifting to the left 
		}
		a[n-1] = x; //moving the first element to last position
	}

	//rotating array to right otherwise
	else{
		x = a[n-1]; //storing the last element as it will get overwritten
		//looping for right to left as we will overwrite the right element
		for (i = n-2; i >= 0; --i){
			a[i+1] = a[i]; //shifting to the right
		}
		a[0] = x; //moving the last element to first position
	}

	//printing the modified array
	printf("Modified array: ");
	for (i = 0; i<n; i++){
		printf("%d ", a[i]);
	}

	//printing newline
	printf("\n");
	return 0;
}
