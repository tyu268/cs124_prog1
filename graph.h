#include <stdio.h>
#include <stdlib.h>

#ifndef GRAPH_H_
#define GRAPH_H_

double random_number();

void uniform(double** g, int size);

void square(double** g, int size);

void cube(double** g, int size);

void hypercube(double** g, int size);

double** initGraph(int size);

void printGraph(double** g, int size);

#endif
