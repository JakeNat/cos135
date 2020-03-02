// Name: Jake Natalizia
// Date: March 1, 2020

#include <stdio.h>

int main() {
	char input;

	while (input != '-') {
		printf("Enter a letter (press \'-\' to quit): ");
		scanf(" %c", &input);

		
		if ((input > 'a' && input < 'e') || (input > 'e' && input < 'i') || (input > 'i' && input < 'o') || (input > 'o' && input < 'u')) {
			printf("%c is a consonant.\n",input);
		}
		else  if ((input == 'A' || input == 'a') || (input == 'E' || input == 'e') || (input == 'I' || input == 'i') || (input == 'O' || input == 'o') || (input == 'U' || input == 'u')){
			printf("%c is a vowel.\n",input);
		}
		else if (input == '-') {
			break;
		}
		else {
			printf("%c is not a letter in the alphabet.\n",input);
		}
		continue;
	}
	return 0;
}
