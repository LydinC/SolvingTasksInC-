#include <stdio.h>

#define SIZE 256
int topElement = -1;
int balanced = 1;

void push (char stack[], char item);
int pop (char stack[]);

void push (char stack[], char item) {
	if (topElement == (SIZE-1)){
		//Stack is Full
		balanced = 0;
	} else {
		//Push is Successful
		balanced = 1;
    	++topElement;
    	stack [topElement] = item;
    }
}

int pop (char stack[]) {
    int value;
    if (topElement == -1){
    	//Stack is Empty
    	//There is nothing to Pop
    	value = 0;
    	balanced = 0;
    } else {
    	//Pop is Successful
    	balanced = 1;
    	value = stack [topElement];
    	--topElement;
    }
    return value;
}

int main(void) {
	char stack[SIZE];
	char input;

	printf("Insert the Infix Expression and press 'Enter': ");
	fflush(stdout);

	while(input!= '\n') {
		input = getchar();
		if(input == '(')
			push(stack, input);
		else if(input == ')')
			pop(stack);

		//Check whether Right Parenthesis Matched
		if(balanced == 0)
			break;
	}

	if((topElement == -1) && (balanced == 1))
		printf("Balanced");
	else
		printf("Unbalanced");

	return 0;
}
