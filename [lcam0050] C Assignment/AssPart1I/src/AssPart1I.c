#include <stdio.h>

int count_cats(int stops);

int count_cats(stops) {
	static int totalCats;
	int noOfCats;
	if(stops > 0){
		printf("Number of cats observed for bus stop %d: ", stops);
		fflush(stdout);
		scanf("%d", &noOfCats);

		totalCats = totalCats + noOfCats;
		stops--;
		count_cats(stops);
	}
	return totalCats;
}

int main(void) {
	int busStops;
	int totalNumberOfCats = 0;

	printf("Please enter the number of bus stops during the trip: ");
	fflush(stdout);
	scanf("%d", &busStops);

	totalNumberOfCats = count_cats(busStops);
	printf("\nThe number of cats observed during the trip was %d.", totalNumberOfCats);

	return 0;
}
