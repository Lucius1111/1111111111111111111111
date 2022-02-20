#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"


int main() {

    test();

    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            }, 3, 4
    );

    printf("%lld", findSumOfMaxesOfPseudoDiagonal(m));

    return 0;
}
