#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"


int main() {

    test();

    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 0, 1,
                    0, 0, 1,
                    0, 0, 0,
                    1, 1, 1,
            }, 5, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 1,
                    1, 0, 1,
                    1, 1, 1,
                    1, 2, 3,
            }, 5, 3
    );

    sortByDistances(m);

    assert(areTwoMatricesEqual(m, n));

    return 0;
}
