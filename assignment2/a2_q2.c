#include <stdio.h>

int main(){
	//getting user input
	float units;
	int tariff;
	printf("Enter the units: ");
	scanf("%f", &units);	
	printf("Enter the tariff code: ");
	scanf("%d", &tariff);

	printf("Bill amount: ");
	//domestical
	if (tariff == 1){
		//first 100 units cost 3
		if (units <= 100){
			printf("%f",units*3); 
		}
		else{
			printf("%f", (units-100)*5 + 100*3); //first 100 units cost 100*3, remaining cost 5 each
		}
	}
	//commerical
	else if (tariff == 2){
		printf("%f", 7*units); //all units cost 7
	}
	//agricultural
	else if (tariff == 3){
		if (units <= 200){
			printf("0"); //first 200 units are free
		}
		else{
			printf("%f", (units-200)*2); //remaining units cost 2 each
		}
	}
	//industrial
	else if (tariff == 4){
		if (units <= 500){
			printf("%f",units*6); //first 500 units cost 6
		}
		else{
			printf("%f", (units-500)*8 + 500*6); //first 500 units cost 500*6, remaining cost 8 each
		}
	}
	//incorrect tariff code
	else{
		printf("-1");
	}
	printf("\n");
	return 0;
}
