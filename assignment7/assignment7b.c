// Name: Jake Natalizia
// Date: March 24, 2020
// Description: Apply matrix multiplication to a virtual storefront

#include <stdio.h>
#include <ctype.h>

int main() {
    // Initializing variables
    int sat_bagel = 0,sat_flatbread = 0,sat_muffin = 0,sun_bagel = 0,sun_flatbread = 0,sun_muffin = 0;
    // Get sales input for each item
    while (sat_bagel==0 && sat_flatbread==0 && sat_muffin==0 && sun_bagel==0 && sun_flatbread==0 && sun_muffin==0) {
        printf("Enter number of Bagel sales on Saturday: ");
        scanf("%d",&sat_bagel);
        printf("Enter number of Flatbread sales on Saturday: ");
        scanf("%d",&sat_flatbread);
        printf("Enter number of Muffin sales on Saturday: ");
        scanf("%d",&sat_muffin);
        printf("Enter number of Bagel sales on Sunday: ");
        scanf("%d",&sun_bagel);
        printf("Enter number of Flatbread sales on Sunday: ");
        scanf("%d",&sun_flatbread);
        printf("Enter number of Muffin sales on Sunday: ");
        scanf("%d",&sun_muffin);

        if (!isdigit(sat_bagel)) {
            printf("Input must be a number.");
            continue;
        }
    }

    // Matrix of bakery item prices
    printf("Bakery Prices:\n");
    int m1[1][3];
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 3; j++) {
            // Enter price values
            if (j == 0)
                m1[i][j] = 3;
            else if (j == 1)
                m1[i][j] = 4;
            else if (j == 2)
                m1[i][j] = 1;
            // Print out matrix
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Matrix of inputted values
    printf("Sales Information:\n");
    int m2[3][2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            // Enter inputted values to correct location
            if (i == 0 && j == 0)
                m2[i][j] = sat_bagel;
            else if (i == 0 && j == 1)
                m2[i][j] = sun_bagel;
            else if (i == 1 && j == 0)
                m2[i][j] = sat_flatbread;
            else if (i == 1 && j == 1)
                m2[i][j] = sun_flatbread;
            else if (i == 2 && j == 0)
                m2[i][j] = sat_muffin;
            else if (i == 2 && j == 1)
                m2[i][j] = sun_muffin;
            printf("%d ",m2[i][j]);
            // Once a column fills, move down a line
            if (j == 1)
                printf("\n");
        }
    }

    printf("\n");

    // Initialize new matrix for multiplied values
    int m3[1][2];
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            m3[i][j] = 0;
        }
    }
    // Multiplies bakery prices with inputted values
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    // Initialize variables for sales totals
    int sat_sales = 0,sun_sales = 0,weekend_sales = 0;

    // Place multiplied values in a neat matrix
    printf("Sales Values:\n");
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0)
                sat_sales = m3[i][j];
            else if (j == 1)
                sun_sales = m3[i][j];
            printf("%d ",m3[i][j]);
            // Once a column fills, move down a line
            if (j == 1)
                printf("\n");
        }
    }

    printf("\n");

    // Display sales totals
    weekend_sales = sat_sales + sun_sales;
    printf("Total sales on Saturday: $%d\n",sat_sales);
    printf("Total sales on Sunday: $%d\n",sun_sales);
    printf("Total sales of weekend: $%d\n",weekend_sales);
}
