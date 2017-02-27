randmst: randmst.c prim.c graph.c
	gcc -O3 randmst.c prim.c graph.c -lm -o randmst 

graph: graph.c
	gcc graph.c -lm -o graph

prim: prim.c
	gcc prim.c -lm -o prim
