
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

int hasOnlyATCG(char s[]);

int main()
{
	char s[MAXSIZE], target[MAXSIZE]; // s is the genetic string

	// prompt until correct input is given (only A,T,C,G)
	do
	{
		printf("Enter Genetic String (only A, T, C, G): ");
		scanf("%s", s);
	} while (!hasOnlyATCG(s));

	do
	{
		printf("Enter Target Signature (only A, T, C, G): ");
		scanf("%s", target);
	} while (!hasOnlyATCG(target));
	printf("\n");

	// using string lib to find length
	int l1 = strlen(s);
	int l2 = strlen(target);
	int matches = 0;
	int matchcount = 0;

	for (int i = 0; i < l1; i++)
	{
		matches = 0;
		for (int j = 0; j < l2; j++)
		{
			// sliding the window of target across s and comparing element by element
			if (s[i + j] == target[j])
				matches++; // counting number of matches for current iteration
		}
		if (matches == l2)
		{
			// if all characters match
			matchcount++;
			printf("Match found at index %d (0 mutations)\n", i);
		}
		else if (matches == l2 - 1)
		{
			// all except one character matched => 1 mutation
			matchcount++;
			printf("Match found at index %d (1 mutation)\n", i);
		}
	}

	// printing output
	printf("Total matches found: %d\n", matchcount);
	return 0;
}

int hasOnlyATCG(char s[])
{
	/*Checks if given string has only A, T, C and G. Returns 0 if no, 1 if yes*/
	int i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == 'A' || s[i] == 'T') || (s[i] == 'C' || s[i] == 'G'))
			i++;
		else
			return 0;
	}
	return 1;
}