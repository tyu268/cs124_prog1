#include <stdio.h>M
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

	double avg_weight = 0.0;

	int* arr = malloc(sizeof(int) * 9);
	int i;
	for (i = 0; i < 9; i++) {
		arr[i] = 0;
	}
	printArr(arr, 9);

	// array for graph
	double** g;;

	switch(dimension) {
		case 0 :
			// simple random matrix
			break;
		case 2 :
			// unit square
			break;
		case 3 :
			// unit cube
			break;
		case 4 :
			// unit hypercube
			break;
		defaultx :
			printf("Invalid dimension\n");
			return 1;
	}

	for (i = 0; i < numtrials; i++) {
		// re-initialize graph with numpoints points on every iteration
		// run prim on graph
		// run weight on array returned by prim, and add result to avg_weight
	}
	avg_weight /= numpoints;
	printf("Average weight for %d points for %d trials "
				 "with graph dimension %d: %f\n",
					numpoints, numtrials, dimension, avg_weight);
}
