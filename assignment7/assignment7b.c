// Name: Jake Natalizia
// Date: March 26, 2020
// Description: Apply matrix multiplication to a virtual storefront

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief  Print row r of the matrix x with data column width w.
 * @note   
 * @param  xr: The number of matrix x rows (xr > 0)
 * @param  xc: The number of matrix x columns (xc > 0)
 * @param  x[][xc]: Matrix with dimensions xr by xc
 * @param  r: The row to display (r >= 0)
 * @param  w: Data display width (w > 0)
 * @retval None
 */
 
void printrow(int xr, int xc, int x[][xc], int r, int w)
{

    if (r < xr) // We have data for this row
    {

        for (int c = 0; c < xc; c++)
        {
            printf("%-*d ", w, x[r][c]);
        }
    }
    else // Array doesn't have enough rows, just pad with white space
    {
        for (int c = 0; c < xc; c++)
        {
            printf("%*c ", w, ' ');
        }
    }
}

/**
 * @brief  Display matrix x multiplied by matrix y and the resulting matrix z.
 * @note   This function displays the matrices in the format specified in hw07.
 * @param  xr: The number of matrix x rows (xr > 0)
 * @param  xc: The number of matrix x columns (xc > 0)
 * @param  x[][xc]: Matrix with dimensions xr by xc
 * @param  yr: The number of matrix y rows (yr > 0)
 * @param  yc: The number of matrix y columns (yc > 0)
 * @param  y[][yc]: Matrix with dimensions yr by yc
 * @param  zr: The number of matrix z rows (zr > 0)
 * @param  zc: The number of matrix z columns (zc > 0)
 * @param  z[][zc]: Matrix with dimensions zr by zc
 * @retval None
 */

void prettyprint(int xr, int xc, int x[][xc], int yr, int yc, int y[][yc], int zr, int zc, int z[][zc])
{

    // Find the center of the longest matrix.  We will place the dot there.
    int dotrow = 0;
    if (xr > yr)
    {
        dotrow = xr / 2;
        if (xr % 2 == 0)
            dotrow--;
    }
    else
    {
        dotrow = yr / 2;
        if (yr % 2 == 0)
            dotrow--;
    }

    // Print all three matrices at the same time line by line.
    // White space padding for smaller matrices.
    for (int r = 0; r < xr || r < yr; r++)
    {

        printrow(xr, xc, x, r, 1);

        if (dotrow == r)
        {
            printf(". ");
        }
        else
        {
            printf("  ");
        }

        printrow(yr, yc, y, r, 1);

        if (r == 0)
        {
            printf("= ");
        }
        else
        {
            printf("  ");
        }

        printrow(zr, zc, z, r, 3);

        printf("\n");
    }
}

/**
 * @brief  Fill matrix x with random numbers between 1 and 9.
 * @note   
 * @param  xr: The number of matrix rows (xr > 0)
 * @param  xc: The number of matrix columns (xc > 0)
 * @param  x[][xc]: Matrix
 * @retval None
 */

void fillmatrix(int xr, int xc, int x[][xc])
{
    for (int i = 0; i < xr; i++)
    {
        for (int j = 0; j < xc; j++)
        {
            x[i][j] = x[i][j];
        }
    }
}

int main() {
    // Initializing variables, each holds sales data about a given day/item
	// Char variables are for checking correct input
    int sat_bagel = 0,sat_flatbread = 0,sat_muffin = 0,sun_bagel = 0,sun_flatbread = 0,sun_muffin = 0;
	char sat_bagel_char,sat_flatbread_char,sat_muffin_char,sun_bagel_char,sun_flatbread_char,sun_muffin_char;
	
    // Get sales input for each item/input validation
	while (sat_bagel == 0) {
		printf("Enter number of Bagel sales on Saturday: ");
		int temp = scanf("%d%c", &sat_bagel, &sat_bagel_char); // temp takes return value of scanf
		
		if (temp == 2 || sat_bagel_char == '\n') // if scanf reads correct input, ask for next variable
			break;
		else { // if not, clear input buffer and ask again
			printf("Input must be a number. Please try again.\n\n");
			while (getchar() != '\n');
		}
	}
	while (sat_flatbread == 0) {
		printf("Enter number of Flatbread sales on Saturday: ");
		int temp = scanf("%d%c", &sat_flatbread, &sat_flatbread_char); // temp takes return value of scanf
		
		if (temp == 2 || sat_flatbread_char == '\n') // if scanf reads correct input, ask for next variable
			break;
		else { // if not, clear input buffer and ask again
			printf("Input must be a number. Please try again.\n\n");
			while (getchar() != '\n');
		}
	}
	while (sat_muffin == 0) {
		printf("Enter number of Muffin sales on Saturday: ");
		int temp = scanf("%d%c", &sat_muffin, &sat_muffin_char); // temp takes return value of scanf
		
		if (temp == 2 || sat_muffin_char == '\n') // if scanf reads correct input, ask for next variable
			break;
		else { // if not, clear input buffer and ask again
			printf("Input must be a number. Please try again.\n\n");
			while (getchar() != '\n');
		}
	}
	while (sun_bagel == 0) {
		printf("Enter number of Bagel sales on Sunday: ");
		int temp = scanf("%d%c", &sun_bagel, &sun_bagel_char); // temp takes return value of scanf
		
		if (temp == 2 || sun_bagel_char == '\n') // if scanf reads correct input, ask for next variable
			break;
		else { // if not, clear input buffer and ask again
			printf("Input must be a number. Please try again.\n\n");
			while (getchar() != '\n');
		}
	}
	while (sun_flatbread == 0) {
		printf("Enter number of Flatbread sales on Sunday: ");
		int temp = scanf("%d%c", &sun_flatbread, &sun_flatbread_char); // temp takes return value of scanf
		
		if (temp == 2 || sun_flatbread_char == '\n') // if scanf reads correct input, ask for next variable
			break;
		else { // if not, clear input buffer and ask again
			printf("Input must be a number. Please try again.\n\n");
			while (getchar() != '\n');
		}
	}
	while (sun_muffin == 0) {
		printf("Enter number of Muffin sales on Sunday: ");
		int temp = scanf("%d%c", &sun_muffin, &sun_muffin_char); // temp takes return value of scanf
		
		if (temp == 2 || sun_muffin_char == '\n') // if scanf reads correct input, ask for next variable
			break;
		else { // if not, clear input buffer and ask again
			printf("Input must be a number. Please try again.\n\n");
			while (getchar() != '\n');
		}
	}
	
	printf("\n");
	
    // Bakery Item Matrix - stores prices of each item
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
        }
    }

    // Sales Value Matrix - stores sales data about each item
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
        }
    }
	
    // Initialize new matrix for multiplied values
    int m3[1][2] = {};
	
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
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0)
                sat_sales = m3[i][j];
            else if (j == 1)
                sun_sales = m3[i][j];
        }
    }
	
	// Print matrix info nicely
	printf("Sales Information: \n");
	fillmatrix(1, 3, m1);
	fillmatrix(3, 2, m2);
	fillmatrix(1, 2, m3);
	
	prettyprint(1, 3, m1, 3, 2, m2, 1, 2, m3);

    printf("\n");

    // Display sales totals
    weekend_sales = sat_sales + sun_sales;
    printf("Total sales on Saturday: $%d\n",sat_sales);
    printf("Total sales on Sunday: $%d\n",sun_sales);
    printf("Total sales of weekend: $%d\n",weekend_sales);
}
