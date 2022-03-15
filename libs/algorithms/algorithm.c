#include "algorithm.h"

int max2(int a, int b) {
    return a > b ? a : b;
}

void append(int *array, size_t *size, const int value) {
    *size += 1;
    array[*size - 1] = value;
}

void insert(int *const a, size_t *const n, const size_t pos, const int value) {
    assert (pos <= *n);
    if (*n == pos) {
        append(a, n, value);
        return;
    }
    (*n)++;
    for (size_t i = *n; i != pos; i--)
        a[i] = a[i - 1];
    a[pos] = value;
}

void copyArray(int *b, const int *a, size_t size) {
    for (size_t i = 0; i < size; i++)
        b[i] = a[i];
}

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

size_t binarySearch_(const int *a, size_t n, int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x)
            left = middle;
        else
            right = middle;
    }
    return a[left] == x ? left : n;
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

