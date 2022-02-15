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

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

int main() {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    matrix m = getMemMatrix(a, b);
    inputMatrix(m);

    getSquareOfMatrixIfSymmetric(&m);

    outputMatrix(m);

    return 0;
}
