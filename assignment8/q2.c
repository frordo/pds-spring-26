
#include <stdio.h>
#include <stdlib.h>

int** allocateptr(int m, int n);
void freeptr(int m, int** a);

int main(){
	//declaring variables
	int m, n, k;
	int **a, **ker, **res;
	printf("Enter the image size: ");
	scanf("%d%d",&m, &n);

	a = allocateptr(m, n); //malloc'ing image array

	//getting array input
	printf("\nEnter the image matrix:\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	//declaring kernel array
	printf("\nEnter the kernel size: ");
	scanf("%d",&k);

	while (k%2 == 0){
		printf("Enter odd integer\n");
		scanf("%d", &k);
	}

	ker = allocateptr(k, k); //malloc'ing kernel 
	
	//getting kernel input
	printf("\nEnter the kernel:\n");
	for (int i = 0; i < k; i++){
		for (int j = 0; j < k; j++){
			scanf("%d", &ker[i][j]);
		}
	}

	res = allocateptr(m, n); //malloc'ing result array

	int mid = k/2, s = 0, kersum = 0;

	//iterate over all elements, calculate its result and store in res
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			s = kersum = 0;
			
			/*Iterate though kernel, lining up middle of kernel with a[i][j]
			x, y -> -k/2..k/2
			If i + x and j + y are in the image, add to filter result
			*/

			for (int x = -mid; x <= mid; x++){
				for (int y = -mid; y <= mid; y++){
					if ((0 <= i + x && i + x < m) && (0 <= j+y && j+y < n)){
						s += a[i+x][j+y] * ker[mid+x][mid+y];
						kersum += ker[mid+x][mid+y];
					}
				}
			}
			res[i][j] = (int) ((float) s)/((float) kersum) + 0.5; //rounding to nearest int by adding 0.5 and truncating
		}
	}

	//print the reuslt
	printf("\nFiltered Image:\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("%2d ", res[i][j]);
		}
		printf("\n");
	}

	//freeing the memory
	freeptr(m, a);
	freeptr(m, res);
	freeptr(k, ker);

	return 0;
}


int** allocateptr(int m, int n){
	int ** a;
	//malloc'ing and checking for errors
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
	return a;
}

void freeptr(int m, int** a){
	for (int i = 0; i < m; i++){
		free(a[i]);
	}
	free(a);
}

