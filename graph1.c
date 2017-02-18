#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	// generating random numbers
	srand((unsigned int)time(NULL));
	double random = rand() / (double) RAND_MAX;

	printf("%f\n", random);
}
