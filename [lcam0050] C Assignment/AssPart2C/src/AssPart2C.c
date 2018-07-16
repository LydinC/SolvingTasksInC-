#include <ctype.h>
#include <stdio.h>

#define SIZE 256
char stack[SIZE];
char string[SIZE];
int topElement = -1;
int balanced;

void push (char stack[], char item);
char pop (char stack[]);
void postfix_evaluation ();

void push (char stack[], char item) {
	if (topElement == (SIZE-1)){
		balanced = 0;
	} else {
		balanced = 1;
    	++topElement;
    	stack[topElement] = item;
    }
}

char pop (char stack[]) {
    char value;
    if (topElement == -1){
    	value = 0;
    	balanced = 0;
    } else {
    	balanced = 1;
    	value = stack[topElement];
    	--topElement;
    }
    return value;
}

void postfix_evaluation () {
	char z;
	int i = 0;
	int operand1;
	int operand2;

	while((z = string[i++]) != '\0') {
		if(isdigit(z)) {
			//Push operand
			push(stack, (z - 48));
		} else {
			//Pop 2 operands and evaluate
			operand2 = pop(stack);
			operand1 = pop(stack);
			switch(z) {
				case '+': push(stack, (operand1 + operand2));
					break;
				case '-': push(stack, (operand1 - operand2));
					break;
				case '*': push(stack, (operand1 * operand2));
					break;
				case '/': push(stack, (operand1 / operand2));
					break;
			}
		}
	}
	printf("\n");
	printf("Result after Evaluation: %d", stack[topElement]);
}

int main(void) {
	char character;
	char x;
	int position = 0;
	int i = 0;

	printf("Insert the Infix Expression and press 'Enter': ");
	fflush(stdout);

	while(character!= '\n') {
		character = getchar();

		if((character == '(') || (character == '+') || (character == '-') || (character == '*') || (character == '/')) {
			//Push elements to the stack
			push(stack, character);
		} else if(isdigit(character)) {
			string[position] = character;
			position++;
		} else if(character == ')') {
			//Pop elements from the stack
			x = pop(stack);
			if(x != '(') {
				//Add elements to the array
				string[position] = x;
				position++;
			}
		}
	}

	if(topElement != -1) {
		//Pop elements from the stack
		x = pop(stack);
		if(x != '(') {
			//Add the operators to the array
			string[position] = x;
			position++;
		}
	}

	printf("Expression in Postfix: ");
	for(i = 0; i < position; i++)
		printf("%c ", string[i]);

	postfix_evaluation();

	return 0;
}
