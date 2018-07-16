#include "SharedADT.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stack(stackS *S, int maxSize) {
	stackElement *contents;
	contents = (stackElement*)malloc(sizeof(stackElement) * maxSize);

	if (contents == NULL) {
		printf("Not enough memory to initialize stack!");
	} else {
		S -> elements = contents;
		S -> maxSize = maxSize;
		S -> topElement = -1;
	}
}

void push(stackS *S, stackElement p) {
	if(is_full(S)) {
		printf("Stack is Full!");
	} else {
		S -> elements[++S -> topElement] = p;
	}
}

stackElement pop(stackS *S) {
	stackElement p;
	if(is_empty(S)) {
		printf("Stack is Empty!");
	} else {
		p = S -> elements[S -> topElement--];
	}
	return p;
}

int is_full(stackS *S) {
	return S -> topElement >= S -> maxSize - 1;
}

int is_empty(stackS *S) {
	return S -> topElement < 0;
}

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
