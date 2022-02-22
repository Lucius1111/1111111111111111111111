#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int main() {

    test();

    size_t nMatrices = 5;
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    2, 1,
                    1, 3,
                    -7, -6,

                    3, 3,
                    2, 3,
                    3, 3,

                    12, 1,
                    -2, 6,
                    4, 7,

                    3, 3,
                    3, 3,
                    3, 3,

                    3, 4,
                    3, 4,
                    4, 3,
            },
            nMatrices, 3, 2);

    printMatrixWithMinNorm(ms, nMatrices);

    return 0;
}
