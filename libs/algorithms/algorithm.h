#ifndef INC_ALGORITHM_H
#define INC_ALGORITHM_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int max2(int a, int b);

void append(int *array, size_t *size, const int value);

void insert(int *const a, size_t *const n, const size_t pos, const int value);

void copyArray(int *b, const int *a, size_t size);

void swap(void *a, void *b, size_t size);

long long getSum(const int *a, size_t n);

int getMax(const int *a, int n);

int getMin(const int *a, int n);

bool isUnique(const long long *a, size_t n);

size_t binarySearch_(const int *a, size_t n, int x);

int compare_ints(const void *a, const void *b);

#endif
