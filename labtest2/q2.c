

#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 20

void printmatrix(float arr[][MAXROWS], int n);

int main()
{
	// getting n input
	int n;
	printf("Enter the number of rows (even number): ");
	scanf("%d", &n);

	float a[MAXROWS][MAXROWS]; // original matrix
	float p[MAXROWS][MAXROWS]; // pooled matrix

	printf("\nEnter the elements of the matrix:\n"); // getting input
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%f", &a[i][j]);
		}
	}
	float m = a[0][0];
	// filling pooled matrix
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			/*(i, j) of pooled matrix corresponds to 2x2 subarray starting at
			(2i, 2j) in the original matrix.
			Finding the maximum element and assigning it to p[i][j]*/

			m = a[2 * i][2 * j];
			if (m < a[2 * i + 1][2 * j])
				m = a[2 * i + 1][2 * j];
			if (m < a[2 * i][2 * j + 1])
				m = a[2 * i][2 * j + 1];
			if (m < a[2 * i + 1][2 * j + 1])
				m = a[2 * i + 1][2 * j + 1];
			// finding max

			p[i][j] = m;
		}
	}

	// printing out the matrices
	printf("\nThe original matrix:\n");
	printmatrix(a, n);
	printf("\nThe pooled matrix:\n");
	printmatrix(p, n / 2);

	return 0;
}

void printmatrix(float arr[][MAXROWS], int n)
{
	/* Prints the given matrix nicely */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3.2f\t", arr[i][j]); // using vertical tab. 2 decimal places
		}
		printf("\n");
	}
}