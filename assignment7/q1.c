
#include <stdio.h>
#include <stdlib.h>

int main(){
	//getting user input
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int *a = (int *) malloc(n*sizeof(int)); //mallocing the array

	printf("Enter elements: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	printf("\nElements: ");
	int m = a[0];
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
		if (a[i] > m) m = a[i]; //keeping track of maximum index
	}

	printf("\nMaximum element: %d\n", m); //printing max element
	int s, fi, found = 0;

	printf("\nEnter number to search: ");
	scanf("%d", &s);

	//checking if s is in the list
	for (int i = 0; i < n; i++){
		if (a[i] == s){
			fi = i;
			found = 1; 
			break;
		}
	}

	if (found){
		printf("Found at position %d", fi + 1); //position is 1-indexed so fi+1
	}
	else 
		printf("Not found");
	printf("\n");

	free (a); //freeing allocated memory
	return 0;
}
