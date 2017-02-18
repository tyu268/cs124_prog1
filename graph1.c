#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_number() {
	double random = rand() / (double) RAND_MAX;	
	return random;
}

int main(int argc, const char* argv[]) {
	
	int n = strtol(argv[1], NULL, 10);
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

}
