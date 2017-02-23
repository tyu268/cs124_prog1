#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "prim.h"

int main( int argc, const char* argv[] )
{
	printf( "Hello World!\n" );

  if( argc > 1 )
	{
		int i;
		for (i = 1; i < argc; i++)
		{
			// figure out how to check for correct input
			int arg = strtol(argv[i], NULL, 10);
			printf( "arg %d: %d\n", i, arg);
		}
	}
	int* arr = malloc(sizeof(int) * 9);
	int i;
	for (i = 0; i < 9; i++) {
		arr[i] = 0;
	}
	printArr(arr, 9);
}
