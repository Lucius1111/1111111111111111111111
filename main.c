#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int main() {

    test();

    size_t nMatrices = 4;
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9,
            },
            nMatrices, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, nMatrices) == 2);

    return 0;
}
