// Name: Jake Natalizia
// Date: March 3, 2020
// Description: Outputs Fibonacci sequence up to an inputted number.


#include <stdio.h>

// Generates the nth fib number (input being n)
int fib(int x) {
	if (x <= 1)
		return x;
	return fib(x-1) + fib(x-2);
}

int main() {
	// Stores user input
	int userInput = -1;

	// Input validation for positive number
	while (userInput < 0) {
		printf("Enter a number: ");
		scanf("%d",&userInput);

		if (userInput < 0) {
			printf("Please enter a positive integer.\n");
			continue;
		}
	}

	printf("Fibonacci Series: ");
	printf("0, ");

	// Prints fib number if said number is less than input
	for (int i = 0; ++i;) {
		if (fib(i) <= userInput)
			printf("%d, ",fib(i));
		else
			break;
	}
}
