#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int* generate_random_numbers(int);
void smarter_sort(int*, int, int);
int partition(int*, int, int);

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

void smarter_sort(int* unsortedArray, int left, int right) {
	int j = 0;
	if(left < right) {
		//Divide and conquer
		j = partition(unsortedArray, left, right);
		smarter_sort(unsortedArray, left, j-1);
		smarter_sort(unsortedArray, j+1, right);
	}
}

int partition(int* unsortedArray, int left, int right) {
	int pivot, i, j, t;
	pivot = unsortedArray[left];
	i = left;
	j = right+1;

	while(1) {
		do ++i;
		while(unsortedArray[i] <= pivot && i <= right);

		do --j;
		while(unsortedArray[j] > pivot);

		if(i >= j)
			break;

		t = unsortedArray[i];
		unsortedArray[i] = unsortedArray[j];
		unsortedArray[j] = t;
	}

	t = unsortedArray[left];
	unsortedArray[left] = unsortedArray[j];
	unsortedArray[j] = t;

	return j;
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

	smarter_sort(randomNumbersArray, 0, (numberOfRandomNumbers-1));
	printf("\n");

	printf("Random Numbers (SORTED): \n");
	for(i = 0; i < numberOfRandomNumbers; i++) {
		printf("%d ", randomNumbersArray[i]);
	}

	free(randomNumbersArray);
	return 0;
}
