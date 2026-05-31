
#include <stdio.h>
#define MAXSIZE 6 //4 digits, minus sign, \0 -> 6 characters 

char* intToString(int n, char s[]); //declaring function

int main(){
	int n;
	printf("Enter the number: ");
	scanf("%d", &n); //getting user input

	char s[MAXSIZE]; //declaring string and calling function
	intToString(n, s);
	printf("The number as string is: %s\n", s); //printing output
	return 0;
}

char* intToString(int n, char s[]){
	int i = 0; 

	if (n < 0){
		s[i++] = '-';
		n = -n;
		//if n is negative, add a minus sign and move i
	}

	int temp = n;

	//moving i to position after number
	while (temp){
		i++;
		temp/=10;
	}

	s[i] = '\0'; //adding null character

	//going in reverse and writing into s
	while (n && i >= 0){
		s[--i] = '0' + n%10; //converting int to str
		n/=10;
	}

	return s; 
}
