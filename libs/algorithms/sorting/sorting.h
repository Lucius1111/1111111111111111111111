#ifndef INC_SORTING_H
#define INC_SORTING_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TIME_TEST(testCode, time) { \
 clock_t start_time = clock(); \
 testCode \
 clock_t end_time = clock();\
 clock_t sort_time = end_time - start_time; \
 time = (double) sort_time / CLOCKS_PER_SEC; \
 }

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// функция сортировки
typedef struct SortFunc {
    void (*sort)(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64];                  // имя сортировки,
    // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию
    // генерации последоват.
    char name[64];                       // имя генератора,
    // используемое при выводе
} GeneratingFunc;


double getTime();

bool isOrdered(const int *source, size_t size);

void checkTime(void (*sortFunc)(int *, size_t),
               void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName);

void generateRandomArray(int *a, size_t size);

void generateOrderedArray(int *a, size_t size);

void generateOrderedBackwards(int *a,  size_t size);

void bubbleSort(int *a, size_t size);

void selectionSort(int *a, size_t size);

void insertionSort(int *a, size_t size);

void combSort(int *a, size_t size);

void shellSort(int *a, size_t size);

void radixSort(int *a, size_t n);

#endif
