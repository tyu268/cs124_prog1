#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>

#define left(x) 2 * x + 1
#define right(x) 2 * x + 2
#define parent(x) (x - 1) / 2

typedef struct node {
  int val;
  int dist;
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
    printf("(%d: %d) ", h->nodes[i]->val, h->nodes[i]->dist);
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

minHeap* build_heap(minHeap* h, int* arr, int size) {
  int i;
  h->nodes = malloc(size * sizeof(node*));
  for (i = 0; i < size; i++) {
    node* n = malloc(sizeof(node));
    n->val = arr[i];
    n->dist = 0;
    h->nodes[h->size] = n;
    h->size++;
  }
  for (i = size / 2 + 1; i >= 0; i--) {
    heapify(h, i);
  }
  return h;
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

void insert(minHeap* h, int v, int d) {
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
  double* dist;
  dist = malloc(sizeof(int) * n);
  int* prev;
  prev = malloc(sizeof(int) * n);
  int* set;
  set = malloc(sizeof(int) * n);
  int i;
  for (i = 0; i < n; i++) {
    dist[i] = DBL_MAX;
    prev[i] = -1;
    set[i] = 0;
  }
  minHeap* h = initMinHeap();
  insert(h, 0, 0);
  dist[0] = 0.0;
  while (h->size != 0) {
    int v = deletemin(h);
    set[v] = 1;
    int w;
    for(w = 0; w < n; w++) {
      if (set[w] == 0 && g[v][w] != 0 && dist[w] > g[v][w]) {
        dist[w] = g[v][w];
        prev[w] = v;
        insert(h, w, dist[w]);
      }
    }
    //printf("Node %d: \n", v);
    //printArr(prev, n);
    //printHeap(h);
  }
  return prev;
}

double weight(double** g, int* prev, int n) {
  double sum = 0.0;
  int i;
  for (i = 0; i < n; i++) {
    if (prev[i] == -1)
      continue;
    sum += g[prev[i]][i];
  }
  return sum;
}

/*int main(int argc, const char* argv[]) {
  int size;
  size = 6;
  int arr[6] = {6, 3, 5, 2, 1, 4};
  minHeap* h = initMinHeap();
  if (build_heap(h, arr, size)) {
    printHeap(h);
  }
  else {
    printf("didn't work\n");
  }
  insert(h, 0, 0);
  insert(h, 7, 0);
  printHeap(h);


  int** g = (int **) malloc(9 * sizeof(int*));
  int i, j;
  for (i = 0; i < 9; i++) {
    g[i] = (int *) malloc(9 * sizeof(int));
    for (j = 0; j < 9; j++) {
      g[i][j] = 0;
    }
  }
  g[0][1] = g[1][0] = 1;
  g[0][3] = g[3][0] = 3;
  g[1][2] = g[2][1] = 5;
  g[1][4] = g[4][1] = 5;
  g[2][5] = g[5][2] = 2;
  g[3][6] = g[6][3] = 2;
  g[3][4] = g[4][3] = 4;
  g[4][5] = g[5][4] = 1;
  g[4][7] = g[7][4] = 5;
  g[5][8] = g[8][5] = 7;
  g[6][7] = g[7][6] = 3;
  g[7][8] = g[8][7] = 6;

  int* a = prim(g, 9);
  printArr(a, 9);

  int** g2 = (int **) malloc(7 * sizeof(int*));
  for (i = 0; i < 7; i++) {
    g2[i] = (int *) malloc(7 * sizeof(int));
    for (j = 0; j < 7; j++) {
      g2[i][j] = 0;
    }
  }
  g2[0][1] = g2[1][0] = 3;
  g2[0][2] = g2[2][0] = 4;
  g2[0][3] = g2[3][0] = 2;
  g2[0][4] = g2[4][0] = 2;
  g2[0][5] = g2[5][0] = 3;
  g2[1][6] = g2[6][1] = 5;
  g2[2][4] = g2[4][2] = 7;
  g2[2][6] = g2[6][2] = 4;
  g2[4][5] = g2[5][4] = 1;
  for (i = 0; i < 7; i++) {
    printArr(g2[i], 7);
  }
  printf("\n");
  int* b = prim(g2, 7);
  printArr(b, 7);
  printf("Sum of weights: %d\n", weight(g, a, 9));
  printf("Sum of weights: %d\n", weight(g2, b, 7));
}*/
