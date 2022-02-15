#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols = m2.nRows);
    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            m.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; k++)
                m.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return (matrix) m;
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m3 = mulMatrices(m1, m2);
    return isEMatrix(m3);
}

int main() {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    matrix m1 = getMemMatrix(3, 3);
    matrix m2 = getMemMatrix(3, 3);
    inputMatrix(m1);
    inputMatrix(m2);

    return 0;
}
