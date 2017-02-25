#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prim.h"

double random_number() {
	double random = rand() / (double) RAND_MAX;
	return random;
}

int** makeArr(int n) {
	int** arr = malloc(n * sizeof(int*));
	int i;
	for (i = 0; i < n; i++) {
		arr[i] = malloc(n * sizeof(int));
	}
	return arr;
}

int main(int argc, const char* argv[]) {

	int n = strtol(argv[2], NULL, 10);
	double matrix[n][n];
	int i = 0, j = 0;

	srand((unsigned int)time(NULL));

	// create adjacency matrix
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			matrix[i][j] = matrix[j][i] = random_number();
			printf("%f\n", matrix[i][j]);
		}
	}

	int** (*graph_func) (int);
	graph_func = &(makeArr);
	void (*print_func) (int*, int);
	print_func = &printArr;
	int** arr = graph_func(5);
	for (i = 0; i < 5; i++) {
		print_func(arr[i], 5);
	}

}
