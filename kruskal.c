#include <stdio.h>
#include <stdlib.h>

struct set {
  struct set *parent;
  int rank;
  int node;
};

//display a set
void printset(struct set* s) {
   printf("(%d, %d, %d)\n ", s->parent->node, s->rank, s->node);
}

struct set* makeset(int x) {
  struct set *s = (struct set*) malloc(sizeof(struct set));
  if(s == NULL) return NULL;
  s->parent = s;
  s->rank = 0;
  s->node = x;
}

struct set* find(struct set* u) {
  struct set* p = u->parent;
  if(u->node != p->node) {
    p = find(p);
  }
  return p;
}

struct set* link(struct set* u, struct set* v) {
  if(u->rank > v->rank) {
    struct set* temp = u;
    u = v;
    v = temp;
  }
  if(u->rank == v->rank) {
    v->rank = v->rank + 1;
  }
  u->parent = v;
  return v;
}

void union_set(struct set* u, struct set* v) {
  link(find(u), find(v));
}

int main( int argc, const char* argv[])
{
  struct set* tree[10];
  int i;
  for (i = 0; i < 10; i++) {
    tree[i] = makeset(i);
  }

  union_set(tree[1], tree[2]);
  union_set(tree[1], tree[3]);

  for (i = 0; i < 10; i++) {
    printset(tree[i]);
  }
}
