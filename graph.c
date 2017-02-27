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
  double num, limiter;
  srand((unsigned int)time(NULL));

  limiter = 0.064 * (pow(2, log2(size)));

  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      num = random_number();
      if (num > limiter) {
			  g[i][j] = g[j][i] = 0;
		  }
      else {
        g[i][j] = g[j][i] = num;
      }
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
	double num, limiter;
  srand((unsigned int)time(NULL));

	limiter = 0.09;

  // create array of (x, y) points
  vertex_2D* vertices = malloc(size * sizeof *vertices);
  for (i = 0; i < size; i++) {
    vertices[i].x = random_number();
    vertices[i].y = random_number();
  }

  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      num = calculate_2Ddistance(vertices[i], vertices[j]);

			if (num > limiter) {
				g[i][j] = g[j][i] = 0;
			}
			else {
				g[i][j] = g[j][i] = num;
			}
		}
  }
	
  free(vertices);
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
	double num, limiter;
  srand((unsigned int)time(NULL));

	limiter = 0.03;

  // create array of (x, y, z) points
  vertex_3D* vertices = malloc(size * sizeof *vertices);
  for (i = 0; i < size; i++) {
    vertices[i].x = random_number();
    vertices[i].y = random_number();
    vertices[i].z = random_number();
  }

  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
			num = calculate_3Ddistance(vertices[i], vertices[j]);
      if (num > limiter) {
			  g[i][j] = g[j][i] = 0;
		  }
      else {
        g[i][j] = g[j][i] = num;
      }
    }
  }
	
  free(vertices);
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
	double num;
  srand((unsigned int)time(NULL));

  // create array of (x, y, z, potato) points
  vertex_4D* vertices = malloc(size * sizeof *vertices);
  for (i = 0; i < size; i++) {
    vertices[i].x = random_number();
    vertices[i].y = random_number();
    vertices[i].z = random_number();
    vertices[i].potato = random_number();
  }

  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      num = calculate_4Ddistance(vertices[i], vertices[j]);
			if (num > 0.09) {
				g[i][j] = g[j][i] = 0;
			}
			else {
				g[i][j] = g[j][i] = num;
			}
    }
  }
	
  free(vertices);
}

// helpful functions
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

