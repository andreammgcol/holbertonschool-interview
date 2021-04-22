#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void h_array(int *array, size_t size);
void siftdown(int *array, size_t start, size_t end, size_t size);
void swap(int *a, int *b, size_t size, int *array);

#endif
