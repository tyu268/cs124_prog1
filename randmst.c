#include <stdio.h>M
#include <stdlib.h>
#include <errno.h>

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

}
