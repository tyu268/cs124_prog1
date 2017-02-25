#include <stdio.h>
#include <stdlib.h>

#ifndef GRAPH_H_
#define GRAPH_H_

void uniform(double** g, int size);

void square(double** g, int size);

void cube(double** g, int size);

void hypercube(double** g, int size);

double** initGraph(int size);

#endif
