#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
      g[i][j] = g[j][i];
    }
    for (j = i; j < size; j++) {
      g[i][j] = random_number();
    }
  }
}

// dimension 2
typedef struct vertex {
  double x;
  double y;
} vertex;

double calculate_distance(vertex point1, vertex point2) {
  double x_dist = point2.x - point1.x;
  double y_dist = point2.y - point1.y;
  double distance = sqrt(pow(x_dist,2) + pow(y_dist,2)); 
  return distance;
}

void square(double** g, int size) {
  int i, j; 
  srand((unsigned int)time(NULL));

  vertex* vertices = malloc(size * sizeof *vertices);
  for (i = 0; i < size; i++) {
    vertices[i].x = random_number();
    vertices[i].y = random_number();
    printf("(%f, %f)\n", vertices[i].x, vertices[i].y);
  } 

  for (i = 0; i < size; i++) {
    g[i] = malloc(size * sizeof(double*));
    for (j = 0; j < i; j++) {
      g[i][j] = g[j][i];
    }
    for (j = i; j < size; j++) {
      g[i][j] = calculate_distance(vertices[i], vertices[j]);
    }
  }
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

void printGraph(double** g, int size) {
  int i, j;
  for (i = 0; i < size; i++) {
    printf("[ ");
    for (j = 0; j < size; j++) {
      printf("%.5f ", g[i][j]);
    }
    printf("]\n");
  }
}

/*int main(void) {
  int size = 10;
  double** g = malloc(size * sizeof(double**));
  uniform(g, 10);
  printGraph(g, 10);
}*/
