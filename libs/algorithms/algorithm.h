#ifndef INC_ALGORITHM_H
#define INC_ALGORITHM_H

#include <stdio.h>
#include <stdbool.h>

void swap(void *a, void *b, size_t size);

long long getSum(const int *a, size_t n);

int getMax(const int *a, int n);

int getMin(const int *a, int n);

bool isUnique(const long long *a, size_t n);


#endif
