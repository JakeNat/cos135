#include <stdio.h>

int main() {
	int width;

	printf("Enter width = ");
	scanf("%d", &width);

	int length;

	printf("Enter length = ");
	scanf("%d", &length);

	int area;
	area = width * length;
	
	printf("Area of the rectangle = %d", area);
}
