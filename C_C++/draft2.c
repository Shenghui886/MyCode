#include <stdio.h>

int main() {
	// Declare a variable to hold the user's name
	char name[50];

	// Prompt the user for their name
	printf("Enter your name: ");
	
	// Read the user's input
	scanf("%49s", name);

	// Print a greeting message
	printf("Hello, %s!\n", name);

	return 0;
}
