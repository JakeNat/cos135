// Name: Jake Natalizia
// Date: March 23, 2020
// Description: Multiplies two matrices together

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int main() {
    // Get user input, store input in seperate variables, generate seed for rand()
    char m1_input[MAX];
    char m2_input[MAX];
    int m1_row,m1_column,m2_row,m2_column;
    srand(time(0));

    // Makes sure m1 column matches m2 row
    while (m1_column != m2_row) {
        printf("Enter number of rows and columns of first matrix (row x column): ");
        fgets(m1_input, MAX, stdin);
        printf("Enter number of rows and columns of second matrix (row x column): ");
        fgets(m2_input, MAX, stdin);

        // Subtract the ASCII value of '0' from each digit to get the actual number
        m1_row = m1_input[0] - '0';
        m2_row = m2_input[0] - '0';
        m1_column = m1_input[4] - '0';
        m2_column = m2_input[4] - '0';

        // Input Validation
        if (m1_row == 0 || m2_row == 0 || m1_column == 0 || m2_column == 0)
            printf("Error: The number of rows or columns cannot be 0.\n");
        else if (m1_column != m2_row)
            printf("Error: The number of columns of the first matrix must equal the number of rows of the second matrix.\n");
    }

    // Matrix One Initialization
    printf("Matrix One:\n");
    int m1[m1_row][m1_column];
    for (int i = 0; i < m1_row; i++) {
        for (int j = 0; j < m1_column; j++) {
            // Fill with random number between 0-9
            m1[i][j] = rand() % 10;
            // Print out matrix
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Matrix Two Initialization
    printf("Matrix Two:\n");
    int m2[m2_row][m2_column];
    for (int i = 0; i < m2_row; i++) {
        for (int j = 0; j < m2_column; j++) {
            // Fill with random number between 0-9
            m2[i][j] = rand() % 10;
            // Print out matrix
            printf("%d ",m2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Initialize new matrix with 0's
    int m3[m1_row][m2_column];
    for (int i = 0; i < m1_row; ++i) {
        for (int j = 0; j < m2_column; ++j) {
            m3[i][j] = 0;
        }
    }

    // Multiplying matrix 1 and matrix 2
    for (int i = 0; i < m1_row; ++i) {
        for (int j = 0; j < m2_column; ++j) {
            for (int k = 0; k < m1_column; ++k) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // Place multiplied values in a neat matrix
    printf("Output Matrix:\n");
    for (int i = 0; i < m1_row; ++i) {
        for (int j = 0; j < m2_column; ++j) {
            printf("%d ",m3[i][j]);
            // Once a column fills, move down a line
            if (j == m2_column - 1)
                printf("\n");
        }
    }
    return 0;
}
