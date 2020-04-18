/*
 * Author: Jake Natalizia
 * Date: April 18, 2020
 * Description: Implements a dynamic FIFO queue.
 * Language: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// **Function Prototypes**
// Inserts data into the queue
int push(int toPush, int queue[], int queueSize);
// Prints the current elements in the queue
int queuePrint(int queue[], int currentlyQueued);

int main(int argc, char *argv[]) {
	
	// Holds user-inputted size as int (converts from char)
	int queueSize = atoi(argv[1]);
	
	// Dynamically allocates and points to an array of queueSize
	int* queue = (int*)calloc(queueSize, sizeof(int));
	
	// Stores user command and split-up command
	char input[10];
	char *command, *inputNumChar;
	
	// Stores int version of inputNumChar (char)
	int inputNumInt = 0;
	
	// Handles quit condition (quits if 1)
	int quitFactor = 0;			
	
	// Stores number of elements currently enqueued
	int currentlyQueued = 0;
	
	// While user does NOT want to quit, continue asking for input
	while (quitFactor != 1) {
	
		// Ask for and store user command
		printf("Enter command (push, print, or quit): ");
		fgets(input, 10, stdin);
		
		// Seperates user input into command and inputNumChar
		command = strtok(input, " \n");
		inputNumChar = strtok(NULL, "\n");
				
		// Converts inputNumChar to int when the user calls push()
		if (inputNumChar) {
			inputNumInt = atoi(inputNumChar);
		}
		
		// If user inputs "push"
		if (strcmp(command,"push") == 0) {
			currentlyQueued = push(inputNumInt,queue,queueSize);
		}
		// If user inputs "print"
		else if (strcmp(command,"print") == 0) {
			queuePrint(queue,currentlyQueued);
		}
		// If user inputs "quit"
		else if (strcmp(command,"quit") == 0) {
			quitFactor = 1;
		}
		else
			printf("Unknown command.\n");
	}
	
	// If user wants to quit, clears memory + exits
	if (quitFactor == 1) {
		free(queue);
		exit(0);
	}
	
	return 0;
}

// Inserts data into the queue
int push(int toPush, int queue[], int queueSize) {
	
	// Stores overflow
	int temp = 0;
	
	// Stores how many elements are currently enqueued
	static int size = 0;
	
	// If head is empty (still 0), enqueue number
	if (queue[0] == 0) {
		// Store input in head
		queue[0] = toPush;
		size++;
	}
	// If head is filled and tail is empty, enqueue number + don't print overflow
	else if ((queue[0] != 0) && (queue[queueSize-1] == 0)) {
		// Shift all elements right
		for (int i = queueSize-1; i > -1; i--) {
			queue[i] = queue[i - 1];
		}
		queue[0] = toPush;
		size++;
	}
	// If tail is filled, enqueue number + print overflow
	else if (queue[queueSize-1] != 0) {
		// Store current tail in temp
		temp = queue[queueSize-1];
		
		// Shift all elements right
		for (int i = queueSize-1; i > -1; i--) {
			queue[i] = queue[i - 1];
		}
		
		// Print temp as overflow
		printf("Overflow: %d\n", temp);
		
		queue[0] = toPush;
	}
	
	return size;
}

// Prints the current queue
int queuePrint(int queue[], int currentlyQueued) {
	
	// If no elements are enqueued
	if (currentlyQueued == 0) {
		printf("The queue is empty.\n");
	}
	
	// Print each element
	for (int i = 0; i < currentlyQueued; i++) {
		// When the last element is reached, don't append a comma
		if (i == currentlyQueued-1) {
			printf("%d\n",queue[i]);
		}
		else
			printf("%d, ",queue[i]);
	}
	
	return 0;
}