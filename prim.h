#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>

#ifndef PRIM_H_
#define PRIM_H_

typedef struct node {
  int val;
  int dist;
} node;

typedef struct minHeap {
  int size;
  node** nodes;
} minHeap;

minHeap* initMinHeap();

void printHeap(minHeap* h);

void printArr(int* arr, int size);

void swap(node* n1, node* n2);

bool heapify (minHeap* h, int n);

minHeap* build_heap(minHeap* h, int* arr, int size);

int deletemin(minHeap* h);

void insert(minHeap* h, int v, int d);

int* prim(double** g, int n);

int weight(double** g, int* prev, int n);

#endif
