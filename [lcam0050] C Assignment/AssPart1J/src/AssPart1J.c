#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void compute_change(int*, int);

void compute_change(int* coins, int changeRequired) {
	int i = 0;
	int j = 0;
	int least_num = 0;

	int array[8][changeRequired+1];

	//Filling the first row with the amount
	//of change required starting from 0
	//until the amount is reached.
	for(j = 0; j <= (changeRequired); j++) {
		array[i][j] = j;
	}

	//loop to compute the least number of coins.
	for(i = 1; i < 8; i++) {
		for(j = 0; j <= (changeRequired); j++) {
			if(j >= coins[i]) {
				if(array[i-1][j] > (1+array[i][j-coins[i]]))
					array[i][j] = 1 + array[i][j-coins[i]];
				else
					array[i][j] = array[i-1][j];
			} else {
				array[i][j] = array[i-1][j];
			}
		}
	}

	for(i = 0; i < 8; i++) {
		for(j = 0; j<= (changeRequired); j++)
			printf("%d\t", array[i][j]);
			printf("\n");
	}


	//to make point to the least number of coins
	i = 7;
	j = changeRequired;

	//Value in the bottom right corner
	least_num = array[i][j];
	printf("\n");
	printf("The least number of coins that make up the change is %d.\n", least_num);

	//an array to store the coins used. The size is therefore
	//the least_num of coins computed.
	int arr2 [least_num];
	int count = 0;

	//identifying the actual coins needed from the 2D array values
	//and storing these coins in arr2[]
	while(array[i][j] != 0) {
		if(array[i][j] == array[i-1][j]) {
			i--;
		} else {
			j = j - coins[i];
			arr2[count] = coins[i];
			count ++;
		}
	}


	//printing the coins required
	printf("The coins given to the customer are ");
	for(count = 0; count < least_num; count ++) {
		if (count == least_num - 1)
			printf("%d. ", arr2[count]);
		else
			printf("%d, ", arr2[count]);
	}
}

int main(void) {
	int terminate;

	do {
		int changeRequired = 0;
		int coins[8] = {1,2,5,10,20,50,100,200};

		printf("Enter the required change in cents: ");
		fflush(stdout);
		scanf("%d", &changeRequired);

		printf("\n");

		compute_change(coins, changeRequired);


		printf("\n\n");
		printf("Press any key for further change or 0 to terminate");
		fflush(stdout);
		scanf("%d", &terminate);
		printf("\n--------------------------------------------------------------\n\n");

	} while(terminate != 0);

	return 0;
}
