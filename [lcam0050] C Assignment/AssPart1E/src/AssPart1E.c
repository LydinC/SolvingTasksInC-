#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

//function declarations
int* generate_random_numbers(int);
int* naive_sort(int, int*);

//Generating an array of random numbers
int* generate_random_numbers(int numberOfRandomNumbers) {
	int* randomNumbersArray = (int*)malloc(sizeof(int)*numberOfRandomNumbers);
	int counter, randomNumber, i;
	for(counter = 0; counter < numberOfRandomNumbers; counter++) {
		randomNumber = (rand()% 100) + 1;
		randomNumbersArray[counter] = randomNumber;
	}
	printf("Random Numbers (UNSORTED): \n");
	for(i = 0; i < numberOfRandomNumbers; i++) {
		printf("%d ", randomNumbersArray[i]);
	}
	return randomNumbersArray;
}

//Insertion Sort Method
int* naive_sort(int numberOfRandomNumbers, int* unsortedArray) {
	int i, n;
	int tempStore;
	for (i = 1; i < numberOfRandomNumbers; i++) {
		tempStore = unsortedArray[i];
		n = i - 1;
		while ((tempStore < unsortedArray[n]) && (n >= 0)) {
			unsortedArray[n + 1] = unsortedArray[n];
			n = n - 1;
		}
		unsortedArray[n + 1] = tempStore;
	}
	//even though it is named unsorted array, this function returns
	//the sorted array
	return unsortedArray;
}

int main() {
	int numberOfRandomNumbers;
	int i;

	//Used to seed the rand() function to generate different random numbers
	srand(time(NULL));

	printf("Please enter the number of Random Numbers to generate: ");
	fflush(stdout);
	scanf("%d", &numberOfRandomNumbers);

	int* randomNumbersArray;
	randomNumbersArray = (int*)malloc(sizeof(int)*numberOfRandomNumbers);
	randomNumbersArray = generate_random_numbers(numberOfRandomNumbers);

	naive_sort(numberOfRandomNumbers, randomNumbersArray);
	printf("\n");

	printf("Random Numbers (SORTED): \n");
	for(i = 0; i < numberOfRandomNumbers; i++) {
		printf("%d ", randomNumbersArray[i]);
	}

	free(randomNumbersArray);
	return 0;
}
