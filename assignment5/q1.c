#include <stdio.h>

//declaring functions
int reverse(int N);
int reverse_recursive(int N);

int main (){
	//prompting and receiving user input
	int n;
	printf("Please provide the positive integer to be reversed: ");
	scanf("%d", &n);

	//computing reverse using both functions
	int a = reverse_recursive(n);
	int b = reverse(n);

	//printing to console
	printf("The reverse of %d using ‘‘reverse_recursive’’ is: %d\n", n, a);
	printf("The reverse of %d using ‘‘reverse’’ is: %d\n", n, b);
	return 0 ;
}

int reverse(int N){
	int temp = 0; //storing reversed number
	while (N){
		temp*=10;
		temp+=(N%10); //adding last digit of n to temp
		N/=10; //removing units place from n
	}
	return temp;
}
int reverse_recursive(int N){
	if (N < 10) return N; //base case: reverse of single digit number is itself
	int c = 0;
	int temp = N; //using temp variable as we require n later

	//finding number of digits
	while (temp){
		c++;
		temp /= 10;
	}

	//finding place value of leftmost digit
	int x = 1;
	for (int i = 0; i < c - 1; i++){
		x*=10;
	}

	//recursion: reverse(abcd) = reverse(abc) + 1000*d = dcba
	//N%10 -> gives unit digit
	//N/10 -> gives remaining digits
	return reverse_recursive(N/10) + (N%10)*x;
}
