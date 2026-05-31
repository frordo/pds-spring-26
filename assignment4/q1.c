int main(){
	//declaring variables and array
	int n, i, j, x, y, gcd=0, max=0, temp = 0, max1, max2;
	int a[MAX_SIZE];

	//getting user input
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("Enter the array elements: ");
	for (int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}

	//to get all possible pairs, use two loops
	for (i = 0; i<n; i++){
		for (j = i+1; j<n; j++){
			//as gcd(x,y) = gcd(y,x), need to check every pair only once, hence j = i+1
			x = a[i];
			y = a[j];

			//computing gcd(x, y) using Euclid's Division Algorithm
			while (x%y){
				temp = y;
				y = x%y;
				x = temp;
			}
			gcd = y;

			if (gcd > max) {
				//storing maximum gcd and the pair that gave maximal gcd
				max = gcd;
				max1 = a[i];
				max2 = a[j];
			}
		}
	}
	//printing output 
	printf("Pair: %d %d\n", max1, max2);
	printf("Maximum GCD: %d\n", max);
	return 0;
}
