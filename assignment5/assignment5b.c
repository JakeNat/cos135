// Name: Jake Natalizia
// Date: March 1, 2020

#include <stdio.h>

int main() {
	int input = 0;
	
	printf("Input a number larger than 1: ");
	scanf("%d",&input);

	if (input > 1) {
		int i, sum = 0;

		for (i = 2; i <= input; i+=2) {
			sum += i;
		}
		printf("Sum of even numbers between 1 and %d: %d",input,sum);
	}
	
	return 0;
}
