#include <stdio.h>
int main(){
	int m1, m2; //getting user input
	printf("Enter the two test marks: ");
	scanf("%d %d", &m1, &m2);

	float avg = (m1+m2)/2; 
	//exception
	if (m1 < 30 || m2<30){
		printf("The student fails\n");
	}
	//condition 1 (average atleast 50)
	else if (avg >= 50){
		printf("The student passes\n");
	}
	//condition 2 (both at least 60)
	else if (m1>=60 && m2>=60){ 
		printf("The student passes\n");
	}
	else{
		printf("The student fails\n");
	}
	return 0;
}
