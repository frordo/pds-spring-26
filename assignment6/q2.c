
#include <stdio.h>
#define MAXSIZE 6 //4 digits + '-' + '\0' => size is 6

int stringToInt(char s[]); //declaring function

int main(){
	//getting user input
	char s[MAXSIZE];
	printf("Enter the number (as string): ");
	scanf("%s", s);
	int n = stringToInt(s);
	printf("The number is: %d\n", n);
	return 0;
}

int stringToInt(char s[]){
	//declaring variables
	int n        = 0;
	int i        = 0;
	int negative = 1;

	//if number is negative, multiply n by -1 when returning
	if (s[0] == '-'){
		negative = -1;
		i++;
	}
	//iterate through s and add digits
	while (s[i] != '\0'){
		n*=10;
		n+= s[i++] - '0';
	}

	return negative*n;
}
