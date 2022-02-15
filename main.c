#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

long long getSum(const int *a, size_t n) {
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

bool isUnique(const long long *a, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        long long potentialSum = a[i];
        for (size_t j = i + 1; j < n; j++)
            if (a[j] == potentialSum)
                return false;
    }
    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long mSum[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        mSum[i] = getSum(m.values[i], m.nCols);
    if (isUnique(mSum, m.nRows))
        transposeSquareMatrix(m);
}

int main() {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    matrix m = getMemMatrix(a, b);
    inputMatrix(m);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    outputMatrix(m);

    return 0;
}
