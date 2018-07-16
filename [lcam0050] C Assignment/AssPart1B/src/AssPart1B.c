#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {

	char ch;
	int lowercaseCounter = 0;
	int uppercaseCounter = 0;
	int whiteSpaces = 0;
	int noOfCharacters = 0;
	float averageCharacters = 0;

	//Examples:
	//The Quick Brown Fox Jumps Over The Lazy Dog!
	//The quick brown fox jumps over the lazy dog!

	printf("Please Enter Sentence Here: ");
	fflush(stdout);

	while((ch = getchar()) != EOF){
		if(isspace(ch))
			whiteSpaces++;

		if(isalpha(ch)) {
			noOfCharacters++;
			if(islower(ch) != 0)
				lowercaseCounter++;
			else
				uppercaseCounter++;
		}
	}

	//Parsing Values and Calculating Average Number of Characters in Each Word
	averageCharacters = (float)noOfCharacters / ((float)(whiteSpaces));
	printf("Average Number of Characters in Each Word: %.2f \n", averageCharacters);

	printf("Upper:Lower - %d:%d", uppercaseCounter, lowercaseCounter);

	return 0;
}
