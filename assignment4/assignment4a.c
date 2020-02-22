#include <stdio.h>

int addition(int x, int y) {
	int sum = x + y;
	return sum;
}

int subtraction(int x, int y) {
	int difference = x - y;
	return difference;
}

int multiplication(int x, int y) {
	int product = x * y;
	return product;
}

float division(float x, float y) {
	float quotient = x / y;
	return quotient;
}

int main() {
	float x;
	float y;
	
	printf("Enter the first number (X) = ");
	scanf("%f", &x);

	printf("Enter the second number (Y) = ");
	scanf("%f", &y);

	int add = addition(x,y);
	int sub = subtraction(x,y);
	int mult = multiplication(x,y);
	float div = division(x,y);

	printf("X + Y = %d\n", add);
	printf("X - Y = %d\n", sub);
	printf("X * Y = %d\n", mult);
	printf("X / Y = %.2f\n", div);
}
