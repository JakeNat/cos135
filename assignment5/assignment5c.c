// Name: Jake Natalizia
// Date: March 1, 2020
// Description: Virtual storefront, input an amount to buy, get an itemized receipt

#include <stdio.h>
#include <string.h>

void center(char* str, int width) {
	int offset = (width - strlen(str)/2);
	for (int i = 0; i < offset; i++) {
		printf(" ");
	}
	printf("%s\n", str);
}

int main() {
	// Initialization
	char storeName[20];
	int chocBags;
	int toffBags;
	float chocPrice = 15.50;
	float toffPrice = 6.90;

	// User Input
	printf("Enter store name: ");
	fgets(storeName, 20, stdin);

	printf("Enter number of chocolate bags: ");
	scanf("%d",&chocBags);

	printf("Enter number of toffee bags: ");
	scanf("%d",&toffBags);

	// Totals + Discounts
	float chocTotal = chocPrice * chocBags;
	float toffTotal = toffPrice * toffBags;

	// Chocolate Discount
	float chocAfterDiscount = 0;

	if (chocBags > 5) {
		if (chocBags % 5 == 0) {
			chocAfterDiscount = chocTotal - (chocTotal * 0.1);
		}
		else if (chocBags % 5 != 0) {
			int temp = chocBags / 5;
			int tempBagPrice = ((temp * 5) * chocPrice);
			tempBagPrice = tempBagPrice - (tempBagPrice * 0.1);
			temp = chocBags % 5;
			int remainingBags = chocPrice * temp;
			
			chocAfterDiscount = tempBagPrice + remainingBags;
		}
	}
	else if (chocBags <= 5) {
		chocAfterDiscount = chocTotal;
	}

	// Toffee Discount
	float toffAfterDiscount;
	
	if (toffBags > 2) {
		toffAfterDiscount = toffTotal - (toffTotal * 0.05);
	}
	else if (toffBags <= 2) {
		toffAfterDiscount = toffTotal;
	}

	// Total Discount
	float grandTotal = chocAfterDiscount + toffAfterDiscount;
	float grandTotalAfterDiscount;

	if (grandTotal > 100) {
		grandTotalAfterDiscount = grandTotal - (grandTotal * 0.1);
	}
	else if (grandTotal <= 100) {
		grandTotalAfterDiscount = grandTotal;
	}
		
	
	// Receipt Output
	printf("\n");
	center("Welcome to",15);
	center(storeName,15);
	printf("Chocolates\tx%d\t$%.2f\n",chocBags,chocTotal);
	printf("     after discount\t$%.2f\n",chocAfterDiscount);
	printf("\n");
	printf("Toffees   \tx%d\t$%.2f\n",toffBags,toffTotal);
	printf("     after discount\t$%.2f\n",toffAfterDiscount);
	printf("\n");
	printf("Total after discount\t$%.2f\n",grandTotal);
	printf("  after 10%% discount\t$%.2f\n",grandTotalAfterDiscount);

	return 0;
}
