#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int getMaxOfCol(matrix m, size_t numOfCol) {
    int max = m.values[0][numOfCol];
    for (size_t i = 1; i < m.nRows; i++)
        max = max < m.values[i][numOfCol] ?
              m.values[i][numOfCol] : max;

    return max;
}

int SumOfCol(matrix m, size_t numOfCol) {
    int sum = 0;
    for (size_t i = 0; i < m.nRows; i++)
        sum += m.values[i][numOfCol];

    return sum;
}

size_t getNSpecialElement(matrix m) {
    size_t countSpecial = 0;
    for (size_t i = 0; i < m.nCols; i++) {
        int max = getMaxOfCol(m, i);
        if (max > SumOfCol(m, i) - max)
            countSpecial++;
    }

    return countSpecial;
}

int main() {

    test();

    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2,
            }, 3, 4
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 22, 22, 2,
            }, 3, 4
    );

    matrix k = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    1, 8, 11, 3,
            }, 3, 4
    );

    assert(getNSpecialElement(m) == 2);
    assert(getNSpecialElement(n) == 4);
    assert(getNSpecialElement(k) == 0);

    return 0;
}
