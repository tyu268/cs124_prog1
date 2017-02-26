#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "graph.h"

// generate random number
double random_number() {
	return rand() / (double) RAND_MAX;
}

// dimension 0
void uniform(double** g, int size) {
  int i, j;
  srand((unsigned int)time(NULL));

  for (i = 0; i < size; i++) {
    g[i] = calloc(size, sizeof(double*));
    /*for (j = 0; j < i; j++) {
      g[i][j] = g[j][i];
    }*/
    for (j = i + 1; j < size; j++) {
      g[i][j] = random_number();
    }
  }
}

// dimension 2
typedef struct vertex_2D {
  double x;
  double y;
} vertex_2D;

double calculate_2Ddistance(vertex_2D point1, vertex_2D point2) {
  double x_dist = point2.x - point1.x;
  double y_dist = point2.y - point1.y;
  double distance = sqrt(pow(x_dist,2) + pow(y_dist,2));
  return distance;
}

void square(double** g, int size) {
  int i, j;
  srand((unsigned int)time(NULL));

  vertex_2D* vertices = malloc(size * sizeof *vertices);
  for (i = 0; i < size; i++) {
    vertices[i].x = random_number();
    vertices[i].y = random_number();
  }

  for (i = 0; i < size; i++) {
    g[i] = malloc(size * sizeof(double*));
    for (j = 0; j < i; j++) {
      g[i][j] = g[j][i];
    }
    for (j = i + 1; j < size; j++) {
      g[i][j] = calculate_2Ddistance(vertices[i], vertices[j]);
    }
  }
}

// dimension 3
typedef struct vertex_3D {
  double x;
  double y;
  double z;
} vertex_3D;

double calculate_3Ddistance(vertex_3D point1, vertex_3D point2) {
  double x_dist = point2.x - point1.x;
  double y_dist = point2.y - point1.y;
  double z_dist = point2.z - point1.z;
  double distance = sqrt(pow(x_dist,2) + pow(y_dist,2) + pow(z_dist,2));
  return distance;
}

void cube(double** g, int size) {
  int i, j;
  srand((unsigned int)time(NULL));

  vertex_3D* vertices = malloc(size * sizeof *vertices);
  for (i = 0; i < size; i++) {
    vertices[i].x = random_number();
    vertices[i].y = random_number();
    vertices[i].z = random_number();
  }

  for (i = 0; i < size; i++) {
    g[i] = malloc(size * sizeof(double*));
    for (j = 0; j < i; j++) {
      g[i][j] = g[j][i];
    }
    for (j = i; j < size; j++) {
      g[i][j] = calculate_3Ddistance(vertices[i], vertices[j]);
    }
  }
}

// dimension 4
typedef struct vertex_4D {
  double x;
  double y;
  double z;
  double potato;
} vertex_4D;

double calculate_4Ddistance(vertex_4D point1, vertex_4D point2) {
  double x_dist = point2.x - point1.x;
  double y_dist = point2.y - point1.y;
  double z_dist = point2.z - point1.z;
  double potato_dist = point2.potato - point1.potato;
  double distance = sqrt(pow(x_dist,2) + pow(y_dist,2) + pow(z_dist,2) + pow(potato_dist,2));
  return distance;
}

void hypercube(double** g, int size) {
  int i, j;
  srand((unsigned int)time(NULL));

  vertex_4D* vertices = malloc(size * sizeof *vertices);
  for (i = 0; i < size; i++) {
    vertices[i].x = random_number();
    vertices[i].y = random_number();
    vertices[i].z = random_number();
    vertices[i].potato = random_number();
  }

  for (i = 0; i < size; i++) {
    g[i] = malloc(size * sizeof(double*));
    for (j = 0; j < i; j++) {
      g[i][j] = g[j][i];
    }
    for (j = i; j < size; j++) {
      g[i][j] = calculate_4Ddistance(vertices[i], vertices[j]);
    }
  }
}

// helpful functions
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
