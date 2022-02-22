#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int main() {

    test();

    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1,
            }, 3, 3
    );

    swapPenultimateRow(m);
    assert(areTwoMatricesEqual(m, n));

    return 0;
}
