
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 501
#define MAXNAME 101

//defining struct 
typedef struct stud {
	int roll;
	char name[MAXNAME];
	float marks;
} student;

int main(){
	//getting size of structure array
	int n, j = 0;
	printf("Enter number of students: ");
	scanf("%d", &n);
	char x;
	student s[MAXLEN];

	//getting details of students
	for (int i = 0; i < n; i++){
		printf("Enter details for student %d:\n", i+1); //i+1 as student number is one-indexed
		printf("Roll: ");
		scanf("%d", &s[i].roll);

		printf("Name: ");
		getchar(); //absorb the newline character
		//getting string with spaces as input
		j = 0;
		while ((x = getchar()) != '\n'){
			s[i].name[j++] = x;
		}
		s[i].name[j] = '\0'; //terminating string with null char

		printf("Marks: ");
		scanf("%f", &s[i].marks);
		printf("\n");
	}

	printf("All Students:\n");

	int maxi = 0; //index of max element
	for (int i = 0; i<n; i++){
		printf("Roll: %d, Name: %s, Marks: %f\n", s[i].roll, s[i].name, s[i].marks); //printing student details
		if (s[i].marks > s[maxi].marks) 
			maxi = i; //finding topper's roll number
	}

	printf("Topper: %s (%f)\n\n", s[maxi].name, s[maxi].marks); //printing topper details

	printf("Enter roll to update: "); //updating roll number
	int upd, found = 0, index;
	scanf("%d", &upd);

	//checking if roll is present
	for (int i = 0; i < n; i++){
		if (s[i].roll == upd){
			found = 1;
			index = i;
		}
	}

	if (found){
		//if roll is present update it
		printf("Enter new marks: ");
		float mark;
		scanf("%f", &mark);
		s[index].marks = mark;
	}

	else
		printf("Student not found\n"); //roll no is not present

	//get input of threshold
	float th;
	found = 0;
	printf("\nEnter threshold: ");
	scanf("%f", &th);

	for (int i = 0; i < n; i++){
		if (s[i].marks > th) found = 1; //check if threshold is satisfied
	}

	printf("\n");
	printf("Students scoring above %f:\n", th);
	
	if (found){
		for (int i = 0; i < n; i++){
			if (s[i].marks > th) printf("%s ", s[i].name); //if greater than threshold, print names
		}
	}
	else 
		printf("No students found"); //no students above threshold
	printf("\n");

	return 0;
}
