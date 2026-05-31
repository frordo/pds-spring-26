
#include <stdio.h>
#include <stdlib.h>

int columncheck(int i1, int i2, int j, int **a);

int main(){
	//declaring variables
	int m, n;
	int **a;
	printf("Enter the number of rows and columns: ");
	scanf("%d%d",&m, &n);

	//malloc'ing array
	a = (int **) malloc(m*sizeof(int *));
	if (a == NULL){
		printf("Error in allocating\n");
		exit(1);
	}

	for (int i = 0; i < m; i++){
		a[i] = (int *) malloc(n*sizeof(int));
		if (a[i] == NULL){
			printf("Error in allocating\n");
			exit(1);
		}
	}

	//getting array input
	printf("\nEnter the image as matrix:\n");
	for (int i = 0; i 	< m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	//inputting threshold
	int t;
	printf("\nEnter the threshold T: ");
	scanf("%d", &t);

	//converting to binary image and printing
	printf("\nBinary image:\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			//if above threshold 1 else 0
			if (a[i][j] >= t){
				a[i][j] = 1;
			}
			else{
				a[i][j] = 0;
			}
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	int max_area = 0; //maximum achieved area
	int max_w, cur, x; //max width

	//loop through all pairs of rows
	for (int i1 = 0; i1 < m; i1++){
		for (int i2 = i1; i2 < m; i2++){

			//i2 = i1 to check single row rectangles
			max_w = cur = 0;
			/*finding the maximum width of columns having only 1's, as per the hint
			max_w -> max width
			cur -> current width*/
			for (int j = 0; j < n; j++){
				if (columncheck(i1, i2, j, a)){
					cur += 1;
					if (cur > max_w) max_w = cur;
				}

				else{
					cur = 0;
				}
			}
			x = (i2 - i1 + 1)*(max_w); //compute current area by height*width, height = i2-i1+1
			if (x > max_area) max_area = x; //update max area when required
		}
	}

	printf("\nLargest Rectangle Area: %d\n", max_area); //print maximum area

	//free the memory
	for (int i = 0; i < m; i++){
		free(a[i]);
	}
	free(a);

	return 0;
}

int columncheck(int i1, int i2, int j, int **a){
	/*Given a binary array a, check if the values a[i1..i2][j] are made of only one's*/
	int s = 1;
	for (int i = i1; i <= i2; i++){
		s = s && a[i][j]; //if a[i][j] is zero s will stay zero
	}
	return s;
}
