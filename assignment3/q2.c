#include <stdio.h>

int main(){
	//getting user input
	printf("Enter non-negative integer r: "); //prompting user for input
	int r;
	scanf("%d",&r);

	printf("x, y, z values are: ");
	for (int x = 0; x<=r;x++){
		//all possible values for x are 0, 1, 2... r, since y and z are nonnegative
		for (int y = 0; y<=r-x; y++){
			//possible values for y are 0, 1, 2... r-x as x + y <= r since z is nonnegative
			printf("(%d, %d, %d) ", x,y,r-x-y); //as y<=r-x, r-x-y>=0 and (r-x-y)+x+y = r therefore it is a valid nonnegative solution
		}
	}
	printf("\n");
	return 0;
}
