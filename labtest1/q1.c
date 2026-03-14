#include <stdio.h>

int main(){
	int n, a, b; //declaring variables
	printf("Enter the number: ");
	scanf("%d", &n); //getting user input

	char Type = 'O'; //default answer value, we will update only if required

	b = n%10; //getting units digit
	n = n/10;
	a = n; //getting tens digit

	int isPrime = 1; //flag variable

	for (int i = 2; i*i <= a+b; i++){
		if ((a+b)%i == 0){
			isPrime = 0; //if number is composite, setting isPrime to zero
		}
	}
	if (a+b == 1) isPrime = 0; //as 1 is not a prime

	if (isPrime){
		Type = 'P';
	}
	else if ((a*b > 0) && (a%b==0 || b%a==0)){
		//if both numbers are not zero their product is greater than zero
		//either number should divide the other
		//AND of both conditions should be true
		Type = 'D';
	}
	else if ((a*a + b*b)%10 == 0){
		//checking if a squared + b squared is divisible by 10
		Type = 'S';
	}

	printf("The classification is Type %c\n", Type); //printing the answer to console
	return 0;
}
