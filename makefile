randmst: randmst.c prim.c
	gcc -o randmst randmst.c prim.c

graph1: graph1.c
	gcc graph1.c -o graph1

kruskal: kruskal.c
	gcc kruskal.c -o kruskal

prim: prim.c
	gcc prim.c -o prim
