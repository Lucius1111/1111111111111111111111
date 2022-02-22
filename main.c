#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int main() {

    test();

    size_t nMatrices = 5;
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 1,
                    1, 0,
                    0, 0,

                    1, 1,
                    2, 1,
                    1, 1,

                    0, 0,
                    0, 0,
                    4, 7,

                    0, 0,
                    0, 1,
                    0, 0,

                    0, 1,
                    0, 2,
                    0, 3,
            },
            nMatrices, 3, 2);

    printMatrixWithMaxZeroRows(ms, nMatrices);

    return 0;
}
