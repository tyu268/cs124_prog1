#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "prim.h"

int main( int argc, const char* argv[] )
{
	if (argc < 5) {
		printf("Invalid input\n");
		return 1;
	}
  int numpoints = strtol(argv[2], NULL, 10);
	int numtrials = strtol(argv[3], NULL, 10);
	int dimension = strtol(argv[4], NULL, 10);
	printf("numpoints: %d; numtrials: %d; dimension: %d\n",
					numpoints, numtrials, dimension);

	int* arr = malloc(sizeof(int) * 9);
	int i;
	for (i = 0; i < 9; i++) {
		arr[i] = 0;
	}
	printArr(arr, 9);
}
