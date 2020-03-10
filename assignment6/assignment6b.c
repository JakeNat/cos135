// Name: Jake Natalizia
// Date: March 5, 2020
// Description: 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 20

// Checks if password length is 8 or over
int lengthCheck(char *password) {
	if ((strlen(password)-1) >= 8)
		return 1;
	else
		return 0;
}

// Checks for at least one uppercase and one lowercase letters
int caseCheck(char *password) {
	// Variables for keeping track of upper/lower case
	int upperFound, lowerFound;
	
	for (int i = 0; i <= strlen(password)-1; i++) {
		if (isupper(password[i])) {
			upperFound = 1;
			continue;
		}
		else if (islower(password[i])) {
			lowerFound = 1;
			continue;
		}
	}
	// If upper AND lowercase letter are found, return 1
	if (upperFound + lowerFound == 2)
		return 1;
	else
		return 0;
}

// Checks for at least one digit
int digitCheck(char *password) {
	for (int i = 0; i <= strlen(password)-1; i++) {
		if (!isdigit(password[i])) {
			return 1;
			break;
		}
		else
			return 0;
	}
	return 0;
}

// Checks for at least one of the special characters
int specialCharCheck(char *password) {
	int exclamationCheck, atCheck, poundCheck, dollarCheck = 0;

	// Checks if any of the special characters are used
	for (int i = 0; i <= strlen(password)-1; i++) {
		if (password[i] == '!') {
			exclamationCheck = 1;
			break;
		}
		else if (password[i] == '@') {
			atCheck = 1;
			break;
		}
		else if (password[i] == '#') {
			poundCheck = 1;
			break;
		}
		else if (password[i] == '$') {
			dollarCheck = 1;
			break;
		}
		else {
			exclamationCheck = 0;
			atCheck = 0;
			poundCheck = 0;
			dollarCheck = 0;
		}
	}
	// If at least one of the special characters is used
	if ((exclamationCheck == 1) || (atCheck == 1) || (poundCheck == 1) || (dollarCheck == 1))
		return 1;
	else
		return 0;
}

int main() {
	// Initializing variables
	char password[MAX];
	int validPassword = 0;

	// Get password from user
	printf("Please enter your preferred password: ");
	fgets(password, MAX, stdin);

	// Error Messages
	if ((lengthCheck(password) == 0) || (caseCheck(password) == 0) || (digitCheck(password) == 0) || (specialCharCheck(password) == 0)) {
		printf("Invalid Password:\n");
		if (lengthCheck(password) == 0) {
			printf("Your password should contain at least 8 characters.\n");
		}
		if (caseCheck(password) == 0) {
			printf("Your password should contain at least 1 uppercase AND lowercase letter.\n");
		}
		if (digitCheck(password) == 0) {
			printf("Your password should contain at least 1 digit.\n");
		}
		if (specialCharCheck(password) == 0) {
			printf("Your password should contain at least 1 special character: \"! @ # $\".\n");
		}
	}
	else {
		printf("Valid Password\n");
		validPassword = 1;
	}

	// Check if password is valid
	if (validPassword == 1) {
		// Encrypt password (increase ASCII value by 1)
		for (int i = 0; i <= strlen(password)-1; i++) {
			++password[i];
		}
		printf("Your encrypted password is %s\n",password);
	}
	return 0;
}
