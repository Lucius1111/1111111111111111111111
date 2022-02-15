#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int main() {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    matrix m = getMemMatrix(a, b);
    inputMatrix(m);

    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);

    outputMatrix(m);

    return 0;
}