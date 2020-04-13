// Name: Jake Natalizia
// Date: April 12, 2020
// Description: Reads sunspot data from .csv, calculates decennial avg, outputs data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// **Function Prototypes**

// Reads data from sunspot_dataset.csv
int read_data(double sunspot_data[][3], FILE * fp);
// Reads data from sunspot_data, calculates number of sunspots for each decade
int year_avg(double sunspot_data[][3], double sunspot_avg[][3], int rows);
// Prints formatted data from arrays, handles star visualization
void print_array(double sunspot_avg[][3], int rows);

int main() {
	// File pointer to sunspot dataset
	FILE * fp;
	fp = fopen("sunspots_dataset.csv","r");
	
	// Arrays to hold sunspot data
	double sunspot_data[300][3] = {0};
	double sunspot_avg[30][3] = {0};
	
	// Checks if file pointer is null
	if (fp == NULL) {
		printf("Error");
		return -1;
	}
	
	// Reads data, stores number of rows read
	int read = read_data(sunspot_data, fp);
	
	// Prints error message if error occurs while reading
	if (feof(fp) == 0) {
		printf("File reading error. End of file was not reached.\n");
	}
	
	// Averages data for a decade, stores number of rows in sunspot_avg
	int rows_avg = year_avg(sunspot_data, sunspot_avg, read);
	
	print_array(sunspot_avg, rows_avg);
	
	fclose(fp);
	
	return 0;
}

// Reads data from sunspot_dataset.csv
int read_data(double sunspot_data[][3], FILE * fp) {
	char buff[255];
	char *token;
	
	// Array row
	int r = 0;
	
	// Reads header
	fgets(buff, 255, fp);
	
	// Reads data from file and stores in array
	while (fgets(buff, 255, fp) != NULL) {
		// Array column
		int c = 0;
		
		// Reads token with delimeter ,
		token = strtok(buff, ",");
		// Puts data in array
		while (token != NULL) {
			sunspot_data[r][c] = atof(token);
			token = strtok(NULL, ",");
			c++;
		}
		r++;
	}
	return r + 1;
}

// Reads data from sunspot_data, calculates number of sunspots for each decade
int year_avg(double sunspot_data[][3], double sunspot_avg[][3], int rows) {
	
	double sunspot_sum = 0;
	// normalized_val - stores sunspot/100, temp - what i is initialize to, year - stores year
	int count = 0,year_index = 0,normalized_val = 0,temp = 0,year = 0;
	// count - tracks iterations, year_index - makes sure loop iterates within a decade

	// Get data, store in sunspot_avg
	while (sunspot_avg[28][1] == 0) {
		// Iterates through only a decade at a time
		for (int i = temp; i < (10 + year_index); i++) {
			sunspot_sum += sunspot_data[i][2];
			year = sunspot_data[temp][1];
		}
		// Keeps track of which decade is being iterated through
		year_index += 10;
		temp += 10;
		
		normalized_val = floor(sunspot_sum / 100);
		
		// Fill sunspot_avg
		sunspot_avg[count][0] = year;
		sunspot_avg[count][1] = sunspot_sum;
		sunspot_avg[count][2] = normalized_val;
		
		// Increment count, clear sunspot_sum
		count++;
		sunspot_sum = 0;
	}
	return count;
}

// Prints formatted data from arrays, handles star visualization
void print_array(double sunspot_avg[][3], int rows) {
	// Prints the data of each row
	for (int i = 0; i < rows; i++) {
		printf("%-8.0lf %-13.1lf %.0f ", sunspot_avg[i][0], sunspot_avg[i][1], sunspot_avg[i][2]);
		// Whatever normalized_val is (sunspot_avg[i][2]), prints that many stars
		for (int j = 0; j < sunspot_avg[i][2]; j++) {
			printf("* ");
		}
		printf("\n");
	}
	printf("\n");
}