#include "algorithm.h"


void swap(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char tmp = *pa;
        *pa = *pb;
        *pb = tmp;
        pa += 1;
        pb += 1;
    }
}

long long getSum(const int *a, size_t n) {
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int getMax(const int *a, int n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

int getMin(const int *a, int n) {
    int min = a[0];
    for (size_t i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    return min;
}

bool isUnique(const long long *a, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        long long potential = a[i];
        for (size_t j = i + 1; j < n; j++)
            if (a[j] == potential)
                return false;
    }
    return true;
}



