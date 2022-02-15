#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int getMin(const int *a, int n) {
    int min = a[0];
    for (size_t i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

int main() {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    matrix m = getMemMatrix(a, b);
    inputMatrix(m);
    sortColsByMinElement(m);
    outputMatrix(m);

    return 0;
}
