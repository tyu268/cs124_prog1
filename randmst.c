#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prim.h"
#include "graph.h"

int main( int argc, const char* argv[] )
{
	clock_t start, end;
	double cpu_time_used;

	start = clock();

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

	// array for graph
	void (*graph_func) (double**, int);
	double** g = (double**) malloc(numpoints * sizeof(double*));
	int j;
	for (j = 0; j < numpoints; j++) {
		g[j] = (double*) malloc(numpoints * sizeof(double));
		if (j % 5000 == 0) {
			printf("Graph row %d initialized\n", j);
		}
	}
	srand((unsigned int) time(NULL));

	switch(dimension) {
		case 0 :
			// simple random matrix
			graph_func = &uniform;
			break;
		case 2 :
			// unit square
			graph_func = &square;
			break;
		case 3 :
			// unit cube
			graph_func = &cube;
			break;
		case 4 :
			// unit hypercube
			graph_func = &hypercube;
			break;
		default :
			printf("Invalid dimension\n");
			return 1;
	}

	int i;
	int* edges = malloc(numpoints * sizeof(int));
	for (i = 0; i < numtrials; i++) {
		// re-initialize graph with numpoints points on every iteration
		graph_func(g, numpoints);
		// run prim on graph
		printf("Graph created\n");
		//printGraph(g, numpoints);

		edges =	prim(g, numpoints);
		//printArr(edges, numpoints);
		printf("prim completed\n");
		// run weight on array returned by prim, and add result to avg_weight
		double x = weight(g, edges, numpoints);
		avg_weight += x;
		printf("avg weight added: %f\n", x);
		printf("Trial %d complete\n", i);

		//printf("Trial %d complete\n", i);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("Time so far: %f\n", cpu_time_used);
	}
	free(edges);

	avg_weight /= numtrials;
	printf("Average weight for %d points for %d trials "
				 "with graph dimension %d: %f\n",
					numpoints, numtrials, dimension, avg_weight);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time used: %f\n", cpu_time_used);
}
