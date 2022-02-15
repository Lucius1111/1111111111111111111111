#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int getMax(const int *a, int n) {
    size_t maxIndex;
    int max = a[0];
    for (size_t i = 1; i < n; i++) {
        if (a[i] > max) {
            maxIndex = i;
            max = a[i];
        }
    }
    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int main() {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    matrix m = getMemMatrix(a, b);
    inputMatrix(m);

    sortRowsByMaxElement(m);

    outputMatrix(m);

    return 0;
}