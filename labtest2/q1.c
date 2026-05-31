
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 50 // given maximum size is 50

// defining struct
struct country
{
	char name[MAXSIZE];
	char capital[MAXSIZE];
	float area;
};

// declaring functions
void print_country_info(struct country countries[], int n);
int count_smaller_countries(struct country countries[], float A, int n);
void find_capital(struct country countries[], char c[], int n);

int main()
{
	// getting N as input
	int N;
	printf("Enter the number of countries: ");
	scanf("%d", &N);

	// allocating memory dynamically
	struct country *countries = (struct country *)malloc(N * sizeof(struct country));

	// getting input of countries
	printf("\nEnter details of countries:\n\n");
	for (int i = 0; i < N; i++)
	{
		printf("Name: ");
		scanf("%s", countries[i].name);
		printf("Capital: ");
		scanf("%s", countries[i].capital);
		printf("Area: ");
		scanf("%f", &countries[i].area);
		printf("\n");
	}

	// printing out country info
	print_country_info(countries, N);

	// comparing area
	float A;
	printf("\nEnter area to be compared: ");
	scanf("%f", &A);
	int x = count_smaller_countries(countries, A, N);
	printf("Number of countries smaller than %.2f (in 1000 sq. km) is %d.\n", A, x);

	// finding capital
	char c[MAXSIZE];
	printf("Enter country to find: ");
	scanf("%s", c);
	find_capital(countries, c, N);

	free(countries); // freeing memory
	return 0;
}

void print_country_info(struct country countries[], int n)
{
	/*prints country information in format name | capital | area*/
	for (int i = 0; i < n; i++)
	{
		printf("%s | %s | %.2f\n", countries[i].name, countries[i].capital, countries[i].area);
	}
}

int count_smaller_countries(struct country countries[], float A, int n)
{
	/*Returns the number of countries having area less than A in array*/
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (countries[i].area < A)
			count++; // if area less than A increment count
	}
	return count;
}

void find_capital(struct country countries[], char c[], int n)
{
	/*Checks if country c is in the array, and prints capital if it is present, unknown country otherwise*/
	int found = 0;
	int foundindex = 0;

	// checking all elements in array
	for (int i = 0; i < n; i++)
	{
		if (strcmp(countries[i].name, c) == 0)
		{
			// strings match
			found = 1;
			foundindex = i; // storing index where found
			break;
		}
	}

	if (!found)
	{
		// Country not found
		printf("Unknown country\n");
	}
	else
	{
		// output the capital
		printf("Capital is %s\n", countries[foundindex].capital);
	}
}
