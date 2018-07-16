#include <stdio.h>

void to_base_n(int value, int toBaseNumber) {
	if(value > 0) {
		int equivalentNumber = (value%toBaseNumber);
		to_base_n((value/toBaseNumber), toBaseNumber);
		printf("%d", equivalentNumber );
	} else {
		if(value < 0)
			printf("Number is invalid");
	}
}

int main() {
    int value;
    int toBaseNumber;

    printf("Enter a value to be converted: ");
    fflush(stdout);
    scanf("%d",&value);

    printf("\nThis value is to be converted to its base-n equivalent \nwhere n is expressible as 2^y.\nEnter n: ");
    fflush(stdout);
    scanf("%d",&toBaseNumber);

    printf("\nResult: ");
    to_base_n(value, toBaseNumber);
    printf("\n");

    return 0;
}
