#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"


int main() {

    test();

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            }, 3, 4
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            }, 3, 4
    );

    assert(getMinInArea(m1) == 5);
    assert(getMinInArea(m2) == 6);

    freeMemMatrix(m1);
    freeMemMatrix(m2);

    return 0;
}
