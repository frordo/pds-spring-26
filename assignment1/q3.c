#include <stdio.h>

int main(){
	float x1, y1, x2, y2;
	float m, n;
	float px, py;

	//getting user input
	printf("Enter coordinates of A (x1 y1): ");
	scanf("%f %f", &x1, &y1);

	printf("Enter coordinates of B (x2 y2): ");
	scanf("%f %f", &x2, &y2);

	printf("Enter the ratio m and n (m n): ");
	scanf("%f %f", &m, &n);

	//section formula
	px = (m*x2 + n*x1)/(m+n);
	py = (m*y2 + n*y1)/(m+n);

	printf("The coordinates of point P are: (%f, %f)\n", px, py);

	return 0;
}
