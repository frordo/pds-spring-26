
#include <stdio.h>
#define MAXSIZE 101

int get_nth_word(char* str, int n, char* result);

int main(){
	//getting user input
	int n;
	char s[MAXSIZE];

	printf("Enter the sentence: ");
	fgets(s, sizeof(s), stdin); //using fgets due to spaces present

	printf("Enter the value of n: ");
	scanf("%d", &n);

	char result[MAXSIZE]; //as input for get_nth_word

	if (get_nth_word(s, n, result) == -1){
		//word not found
		printf("Invalid n value.\n" );
	} 
	else printf("Word No. %d of the sentence is: %s\n", n, result);
	return 0;
}

int get_nth_word(char* str, int n, char* result){

	int i = 0;

	//counting number of spaces in sentence
	int c = 0; 
	while (str[i] != '\0'){
		if ((str[i] == ' ' || str[i] == ',') && (str[i+1] != ' ' && str[i+1] != ',')) 
			c++; 
		i++;
		if (c == n-1) break; //number of words - 1 = number of spaces
	}

	int k = 0;
	//copying words into result
	while (str[i] != ' ' && str[i] != '\0'){
		if (str[i] == '.'){
			i++;
			continue; //'.' should not be part of word
		}
		result[k++] = str[i++];
	}
	result[k] = '\0';
	if (c < n - 1) return -1; //nth word not found
	return 0;
}
