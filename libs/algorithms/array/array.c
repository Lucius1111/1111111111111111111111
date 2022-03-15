#include "array.h"


void outputArray_(const int *source, size_t size) {
    for (register size_t i = 0; i < size; i++)
        printf("%d ", source[i]);
    printf("\n");
}