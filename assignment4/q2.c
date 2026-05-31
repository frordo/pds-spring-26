int main(){
	//declaring variables
	int n;
	int a[MAX_SIZE];

	//getting user input
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	printf("Enter the array elements: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int longestLength = 0, isContiguous=0, cnt = 0, i, j;

	//require two loops to access all contiguous subarrays
	for (i = 0; i<n; i++){
		cnt = 1; //temporary variable for count, starting from one
		for (j = i+1; j<n; j++){
			if (a[j] % a[j-1] == 0){
				//if divisible subarray, increment count
				cnt++;
				isContiguous = 1; //as there is a divisible subarray, setting flag variable to 1
				if (cnt > longestLength) longestLength = cnt; //updating maximum length
			}
			else{
				break; //if subarray does not satisfy condition, goto next subarray
			}
		}
	}

	if (!isContiguous) longestLength = 0; //if there are no contiguous subarrays that satisfy, print 0
	printf("The longest subarray length is %d\n", longestLength); //printing output
	return 0;
}
