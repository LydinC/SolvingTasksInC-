#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SharedADT.h"

int main() {
	stackS S;
	char inputString[50];
	char* pointer;

	printf("Enter a word or a sentence less than 50 characters: ");
	fflush(stdout);
	scanf("%[^\n]", inputString);

	//Initialize the stack
	stack(&S, strlen(inputString));

	printf("\n");
	printf("Characters Pushed: ");
	for(pointer = inputString; *pointer != '\0'; pointer++) {
		push(&S, *pointer);
		printf("%c", *pointer);
	}

	printf("\n");
	printf("Characters Popped: ");
	while(!is_empty(&S)) {
		printf("%c", pop(&S));
	}

	return 0;
}
