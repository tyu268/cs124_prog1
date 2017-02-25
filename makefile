randmst: randmst.c prim.c graph.c
	gcc -o randmst randmst.c prim.c graph.c

graph: graph.c
	gcc graph.c -lm -o graph

graph1: graph1.c prim.c
	gcc -o graph1 graph1.c prim.c

kruskal: kruskal.c
	gcc kruskal.c -o kruskal

prim: prim.c
	gcc prim.c -o prim
