#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int main() {

    test();

    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0,
            }, 6, 2
    );

    assert(countEqClassesByRowsSum(m) == 3);

    return 0;
}
