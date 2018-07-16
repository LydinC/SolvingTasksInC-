#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>

int* generate_random_numbers(int);
int* naive_sort(int, int*);
void smarter_sort(int*, int, int);
int partition(int*, int, int);

int* generate_random_numbers(int numberOfRandomNumbers) {
	int* randomNumbersArray = (int*)malloc(sizeof(int)*numberOfRandomNumbers);
	int counter, randomNumber, i;
	for(counter = 0; counter < numberOfRandomNumbers; counter++) {
		randomNumber = (rand()% 100) + 1;
		randomNumbersArray[counter] = randomNumber;
	}
	printf("Random Numbers (UNSORTED): ");
	for(i = 0; i < numberOfRandomNumbers; i++) {
		printf("%d ", randomNumbersArray[i]);
	}
	return randomNumbersArray;
}

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
	return unsortedArray;
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
		do i++;
		while(unsortedArray[i] <= pivot && i <= right);

		do j--;
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

int main(void) {
	int numberOfRandomNumbers;
	int i;

	//Used to seed the rand() function to generate different random numbers
	srand(time(NULL));

	printf("Number of Random Numbers to generate: ");
	fflush(stdout);
	scanf("%d", &numberOfRandomNumbers);

	int* randomNumbersArray1 = (int*)malloc(sizeof(int)*numberOfRandomNumbers);
	randomNumbersArray1 = generate_random_numbers(numberOfRandomNumbers);

	int* randomNumbersArray2 = (int*)malloc(sizeof(int)*numberOfRandomNumbers);
	memcpy(randomNumbersArray2, randomNumbersArray1, sizeof(int)*numberOfRandomNumbers);

	naive_sort(numberOfRandomNumbers, randomNumbersArray1);
	printf("\n\n");

	printf("Random Numbers (INSERTION SORTED): ");
	int sorted = 1;
	for(i = 0; i < numberOfRandomNumbers; i++) {
		printf("%d ", randomNumbersArray1[i]);
		if(&randomNumbersArray1[i] < &randomNumbersArray1[i-1])
			sorted = 0;
	}

	printf("\n");
	if(sorted == 1)
		printf("The insertion sort result is correctly sorted.");
	else
		printf("The insertion sort result is incorrect.");


	free(randomNumbersArray1);

	smarter_sort(randomNumbersArray2, 0, (numberOfRandomNumbers-1));
	printf("\n\n");

	printf("Random Numbers (QUICK SORTED): ");
	sorted = 1;
	for(i = 0; i < numberOfRandomNumbers; i++) {
		printf("%d ", randomNumbersArray2[i]);
		if(&randomNumbersArray2[i] < &randomNumbersArray2[i-1])
			sorted = 0;
	}

	printf("\n");
	if(sorted == 1)
		printf("The quick sort result is correctly sorted.");
	else
		printf("The quick sort result is incorrect.");

	free(randomNumbersArray2);
	return 0;
}
