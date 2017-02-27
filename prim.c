#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>

#define left(x) 2 * x + 1
#define right(x) 2 * x + 2
#define parent(x) (x - 1) / 2

typedef struct node {
  int val;
  double dist;
} node;

typedef struct minHeap {
  int size;
  node** nodes;
} minHeap;

minHeap* initMinHeap() {
  minHeap* h = malloc(sizeof(minHeap));
  h->size = 0;
  return h;
}

void printHeap(minHeap* h) {
  printf("[ ");
  int i;
  for (i = 0; i < h->size; i++) {
    printf("(%d: %f) ", h->nodes[i]->val, h->nodes[i]->dist);
  }
  printf("]\n");
}

void printArr(int* arr, int size) {
  printf("[ ");
  int i;
  for (i = 0; i < size; i++) {
    printf("(%d: %d) ", i, arr[i]);
  }
  printf("]\n");
}

void swap(node* n1, node* n2) {
  node temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

bool heapify (minHeap* h, int n) {
  int l = left(n);
  int r = right(n);
  int min;

  if (l < h->size && h->nodes[l]->dist < h->nodes[n]->dist)
    min = l;
  else
    min = n;
  if (r < h->size && h->nodes[r]->dist < h->nodes[min]->dist)
    min = r;
  if (min != n) {
    swap(h->nodes[n], h->nodes[min]);
    heapify(h, min);
  }
  
  return (n == 0);
}

int deletemin(minHeap* h) {
  if (h->size == 0) return -1;
  node* min = h->nodes[0];
  int min_val = min->val;
  h->nodes[0] = h->nodes[h->size - 1];
  h->size--;
  h->nodes = realloc(h->nodes, (h->size) * sizeof(node*));
  heapify(h, 0);
  return min_val;
}

void insert(minHeap* h, int v, double d) {
  if (h->size)
    h->nodes = realloc(h->nodes, (h->size + 1) * sizeof(node*));
  else
    h->nodes = malloc(sizeof(node*));
  
  node* n = malloc(sizeof(node));
  n->val = v;
  n->dist = d;
  h->nodes[h->size] = n;

  int x = h->size;
  h->size++;
  int p = parent(x);
  while (x != 0 && h->nodes[p]->dist > h->nodes[x]->dist) {
    swap(h->nodes[p], h->nodes[x]);
    x = p;
    p = parent(x);
  }
}

int* prim(double** g, int n) {
  double* dist = malloc(sizeof(double) * n);
  int* prev = malloc(n * sizeof(int));
  int* set = malloc(sizeof(int) * n);
  int i, v, w;

  for (i = 0; i < n; i++) {
    dist[i] = DBL_MAX;
    prev[i] = -1;
    set[i] = 0;
  }

  minHeap* h = initMinHeap();
  insert(h, 0, 0);
  dist[0] = 0.0;

  while (h->size != 0) {
    v = deletemin(h);
    set[v] = 1;

    for(w = 0; w < n; w++) {
      double edge = g[v][w];
      if (set[w] == 0 && edge != 0 && dist[w] > edge) {
        dist[w] = edge;
        prev[w] = v;
        insert(h, w, dist[w]);
      }
    }
  }

  free(dist);
  free(set);
  return prev;
}

double weight(double** g, int* prev, int n) {
  double sum = 0.0;
  int i;
  for (i = 1; i < n; i++) {
    int j = prev[i];
    if (j == -1) {
      printf("no prev for node %d\n", i);
      continue;
    }
    sum += g[j][i];
  }
  return sum;
}

