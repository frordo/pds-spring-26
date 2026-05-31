#include <stdio.h>
#define MAXSIZE 100

//declaring function
int canReach(int arr[], int visited[], int n, int current);

int main (){
	//prompting and getting user input
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	//getting array input
	int a[MAXSIZE];
	printf("Enter the integers separated by space: ");
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	//initialising visited array to zeros (no element visited yet)
	int visited[MAXSIZE] = {0};

	if (canReach(a, visited, n, 0)){
		//if last index is reachable
		printf("Result: The last index is reachable.\n");	
	}
	else{
		//if last index is not reachable
		printf("Result: The last index is not reachable.\n");
	}

	return 0;
}

int canReach(int arr[], int visited[], int n, int current){
	if (current == n - 1){
		//base case: if current index is last index, last index is reachable => return 1
		return 1;
	}

	visited[current] = 1; //marking that current element has been visited

	//using notation of the question
	int i = current; 
	int k = arr[i];  

	//we will check all possibilities, going forward or backwards
	int forward = 0;
	int backward = 0;

	/*checking if forward jump can reach the last index
	check if already visited to avoid infinite recusrsion*/
	if (i + k < n && !visited[i + k]){
		forward = canReach(arr, visited, n, i + k);
	}

	/*checking if backward jump can reach the last index
	check if already visited to avoid infinite loop*/
	if (i - k >= 0 && !visited[i - k] ){
		backward = canReach(arr, visited, n, i - k);
	}

	//if reachable from forward or backward, return 1 as last index is reachable
	if (forward == 1 || backward == 1){
		return 1;
	}

	//not reachable from current node (as we have tried all possibilities ie forward and backward)
	return 0;
}
