#include <stdio.h>

int main() {

	char storeName[50];
	float itemOne;
	float itemTwo;
	float itemThree;
	float itemFour;
	float itemFive;


	printf("Enter store name = ");
	fgets(storeName, 20, stdin);
	
	// Item One
	printf("Enter price for item 1 = $");
	scanf("%f", &itemOne);
	// Item Two
	printf("Enter price for item 2 = $");
	scanf("%f", &itemTwo);
	// Item Three
	printf("Enter price for item 3 = $");
	scanf("%f", &itemThree);
	// Item Four
	printf("Enter price for item 4 = $");
	scanf("%f", &itemFour);
	// Item Five
	printf("Enter price for item 5 = $");
	scanf("%f", &itemFive);

	float itemTotal = itemOne + itemTwo + itemThree + itemFour + itemFive;
	float tax = itemTotal * .1;
	float grandTotal = itemTotal + tax;

	printf("\tWelcome to\n");
	printf("\t %s", storeName);
	printf("\n");
	printf("Item 1 \t\t $%.2f\n", itemOne);
	printf("Item 2 \t\t $%.2f\n", itemTwo);
	printf("Item 3 \t\t $%.2f\n", itemThree);
	printf("Item 4 \t\t $%.2f\n", itemFour);
	printf("Item 5 \t\t $%.2f\n", itemFive);
	printf("\n");
	printf("Item total: \t $%.2f\n", itemTotal);
	printf("\n");
	printf("GST: \t\t $%.2f\n", tax);
	printf("Total: \t\t $%.2f\n", grandTotal);
	

	
}
