#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"

double random_number() {
	return rand() / (double) RAND_MAX;
}

// dimension 0
void uniform(double** g, int size) {
  int i, j;
  for (i = 0; i < size; i++) {
    g[i] = malloc(size * sizeof(double*));
    for (j = 0; j < i; j++) {
      g[j][i] = g[i][j];
    }
    for (j = i; j < size; j++) {
      g[i][j] = random_number();
    }
  }
}

// dimension 2
void square(double** g, int size) {
  return;
}

// dimension 3
void cube(double** g, int size) {
  return;
}

// dimension 4
void hypercube(double** g, int size) {
  return;
}

double** initGraph(int n) {
	double** arr = malloc(sizeof(double**));
  return arr;
}

/*int main(void) {
  return 0;
}*/
