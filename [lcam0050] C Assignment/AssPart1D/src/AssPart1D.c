#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50
char inputString[SIZE];
int length = 0;

void str_reverse() {
	//Set a temporary variable to hold character values
	char temporary;
	int i = 0;
	int k = 0;
	int j = 0;

	//Reverse the string
	for (j = 0; j < length; j++) {
		if (!isalnum(inputString[j]) || (j == length - 1)) {
			if (j < length - 1)
				k = j - 1;
			else
				k = j;
		}
	}
	while (i < k) {
		temporary = inputString[i];
		inputString[i] = inputString[k];
		inputString[k] = temporary;
		i++;
		k--;
	}

	//Print the reversed string
	printf("The reversed string is \"%s\"", inputString);
}

int main(void) {
	printf("Please enter a string argument: ");
	fflush(stdout);
	scanf("%[^\n]", inputString);

	length = strlen(inputString);
	printf("The length of the string is %d \n", length);

	str_reverse(inputString);

	return 0;
}
