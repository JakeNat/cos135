#include <stdio.h>

int main() {
	float tempInF;
	
	printf("Enter temperature in Fahrenheit = \n");
	scanf("%f", &tempInF);
	printf("Value of F: %.3f\n", tempInF); 

	float tempInC;
	tempInC = (tempInF - 32) * 5/9;
	printf("Value of C: %.3f\n", tempInC);
}
