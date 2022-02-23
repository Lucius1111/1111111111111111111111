#include "libs/data_stuctures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

void testForTasks_task1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    5, 6, 9,
                    1, 7, 8,
            }, 3, 3
    );

    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);

    assert(m.values[1][0] == 1);
    assert(m.values[1][1] == 7);
    assert(m.values[1][2] == 8);
    assert(m.values[2][0] == 5);
    assert(m.values[2][1] == 6);
    assert(m.values[2][2] == 9);

    freeMemMatrix(m);

}

void testForTasks_task1_minAndMaxInOneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    1, 6, 9,
                    5, 7, 8,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    1, 6, 9,
                    5, 7, 8,
            }, 3, 3
    );

    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);

    assert(areTwoMatricesEqual(m, n) == true);

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task2_getMax() {
    int a[5] = {1, 2, 3, 4, 5};
    assert(getMax(a, 5) == 5);
}

void testForTasks_task2_getMax_allElementsIsEqual() {
    int a[5] = {5, 5, 5, 5, 5};
    assert(getMax(a, 5) == 5);
}

void testForTasks_task2_getMax_maxIsNegative() {
    int a[5] = {-5, -5, -1, -3, -2};
    assert(getMax(a, 5) == -1);

}

void testForTasks_task2_sortRowsByMaxElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    5, 6, 9,
                    1, 7, 8,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    1, 7, 8,
                    5, 6, 9,
            }, 3, 3
    );

    sortRowsByMaxElement(m);

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task2_sortRowsByMaxElement_maxElementsIsEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 9,
                    5, 6, 9,
                    1, 7, 9,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    4, 2, 9,
                    5, 6, 9,
                    1, 7, 9,
            }, 3, 3
    );

    sortRowsByMaxElement(m);

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task3_getMin() {
    int a[5] = {1, 2, 3, 4, 5};
    assert(getMin(a, 5) == 1);
}

void testForTasks_task3_getMin_maxIsNegative() {
    int a[5] = {-5, -5, -1, -3, -2};
    assert(getMin(a, 5) == -5);
}

void testForTasks_task3_getMin_allElementsIsEqual() {
    int a[5] = {5, 5, 5, 5, 5};
    assert(getMin(a, 5) == 5);
}

void testForTasks_task3_sortColsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    5, 6, 9,
                    1, 7, 8,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    5, 6, 9,
                    1, 7, 8,
            }, 3, 3
    );

    sortColsByMinElement(m);

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task3_sortColsByMinElement_minElementsIsEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 1, 9,
                    5, 6, 9,
                    1, 7, 1,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    4, 1, 9,
                    5, 6, 9,
                    1, 7, 1,
            }, 3, 3
    );

    sortColsByMinElement(m);

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task4_mulMatrices() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    5, 6, 9,
                    1, 7, 8,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    2, 2, 2,
                    3, 3, 3,
                    4, 4, 4,
            }, 3, 3
    );

    matrix answer = createMatrixFromArray(
            (int[]) {
                    26, 26, 26,
                    64, 64, 64,
                    55, 55, 55,
            }, 3, 3
    );

    assert(areTwoMatricesEqual(answer, mulMatrices(m, n)));

    freeMemMatrix(m);
    freeMemMatrix(n);
    freeMemMatrix(answer);
}

void testForTasks_task4_mulMatrices_mulWithEMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    5, 6, 9,
                    1, 7, 8,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            }, 3, 3
    );

    matrix answer = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    5, 6, 9,
                    1, 7, 8,
            }, 3, 3
    );

    assert(areTwoMatricesEqual(answer, mulMatrices(m, n)));

    freeMemMatrix(m);
    freeMemMatrix(n);
    freeMemMatrix(answer);
}

void testForTasks_task4_getSquareOfMatrixIfSymmetric() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 5, 1,
                    5, 6, 7,
                    1, 7, 8,
            }, 3, 3
    );

    matrix answer = createMatrixFromArray(
            (int[]) {
                    42, 57, 47,
                    57, 110, 103,
                    47, 103, 114,
            }, 3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(answer, m));

    freeMemMatrix(m);
    freeMemMatrix(answer);
}

void testForTasks_task4_getSquareOfMatrixIfSymmetric_isNotSymmetric() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    5, 6, 7,
                    1, 3, 8,
            }, 3, 3
    );

    matrix answer = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    5, 6, 7,
                    1, 3, 8,
            }, 3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(answer, m));

    freeMemMatrix(m);
    freeMemMatrix(answer);
}

void testForTasks_task4_getSquareOfMatrixIfSymmetric_isEMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            }, 3, 3
    );

    matrix answer = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            }, 3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(answer, m));

    freeMemMatrix(m);
    freeMemMatrix(answer);
}

void testForTasks_task5_isUnique() {
    const long long a[5] = {1, 2, 3, 4, 5};
    assert(isUnique(a, 5));
}

void testForTasks_task5_isUnique_hasNegativeElements() {
    const long long a[5] = {-1, -2, -3, -4, -5};
    assert(isUnique(a, 5));
}

void testForTasks_task5_isUnique_isNonUnique() {
    const long long a[5] = {-1, -3, -3, 5, -5};
    assert(!isUnique(a, 5));
}

void testForTasks_task5_getSum() {
    const int a[5] = {1, 3, 3, 5, 5};
    assert(getSum(a, 5) == 17);
}

void testForTasks_task5_getSum_hasNegativeElements() {
    const int a[5] = {-1, -3, -3, 5, -5};
    assert(getSum(a, 5) == -7);
}

void testForTasks_task5_transposeIfMatrixHasNotEqualSumOfRows_isUniqueRows() {

    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    5, 6, 7,
                    1, 3, 8,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    4, 5, 1,
                    5, 6, 3,
                    6, 7, 8,
            }, 3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m);

    assert(areTwoMatricesEqual(n, m));

    freeMemMatrix(m);
    freeMemMatrix(n);

}

void testForTasks_task5_transposeIfMatrixHasNotEqualSumOfRows_isNonUniqueRows() {

    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    5, 6, 4,
                    7, 7, 1,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    5, 6, 4,
                    7, 7, 1,
            }, 3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m);

    assert(areTwoMatricesEqual(n, m));

    freeMemMatrix(m);
    freeMemMatrix(n);

}

void testForTasks_task6_isMutuallyInverseMatrices_isMutuallyInverse() {

    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    5, 7
            }, 2, 2
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    7, -4,
                    -5, 3
            }, 2, 2
    );

    assert(isMutuallyInverseMatrices(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task6_isMutuallyInverseMatrices_isNonMutuallyInverse() {

    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    5, 7
            }, 2, 2
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    5, 7
            }, 2, 2
    );

    assert(!isMutuallyInverseMatrices(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task7_max() {
    int a = 3;
    int b = 5;

    assert(max(a, b) == 5);
}

void testForTasks_task7_max_isEqualValues() {
    int a = 3;
    int b = 3;

    assert(max(a, b) == 3);
}

void testForTasks_task7_max_hasNegativeValues() {
    int a = -3;
    int b = 3;

    assert(max(a, b) == 3);
}

void testForTasks_task7_findSumOfMaxesOfPseudoDiagonal() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            }, 3, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);

    freeMemMatrix(m);
}

void testForTasks_task7_findSumOfMaxesOfPseudoDiagonal_hasNegativeElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, -5, 4,
                    -1, 3, -6, 3,
                    -3, 2, 1, 2,
            }, 3, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 8);

    freeMemMatrix(m);
}

void testForTasks_task7_findSumOfMaxesOfPseudoDiagonal_allElementsIsEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 3, 3, 3,
                    3, 3, 3, 3,
                    3, 3, 3, 3,
            }, 3, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 15);

    freeMemMatrix(m);
}

void testForTasks_task8_findMin() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            }, 3, 4
    );

    assert(findMin(m, 0, 3, 0) == 5);
    assert(findMin(m, 0, 2, 1) == 3);
    assert(findMin(m, 1, 2, 2) == 1);
}

void testForTasks_task8_findMin_hasNegativeElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, -5, 6,
                    3, -11, 8, 9,
                    4, 1, 12, -2
            }, 3, 4
    );

    assert(findMin(m, 0, 3, 0) == -5);
    assert(findMin(m, 1, 3, 1) == -11);
    assert(findMin(m, 0, 2, 2) == 1);
}

void testForTasks_task8_getMinInArea() {

    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            }, 3, 4
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            }, 3, 4
    );

    assert(getMinInArea(m) == 5);
    assert(getMinInArea(n) == 6);

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task8_getMinInArea_hasNegativeElements() {

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, -2, 5, 6,
                    3, 11, 8, 9,
                    -4, 1, 12, -2
            }, 3, 4
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    -6, 8, -9, 2,
                    7, 12, 3, 4,
                    10, 11, -5, 1
            }, 3, 4
    );

    assert(getMinInArea(m1) == -2);
    assert(getMinInArea(m2) == -9);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void testForTasks_task9_getDistance() {
    int a[] = {1, 2, 3, 4, 5};
    float eps = 0.000001f;
    assert(fabsf(7.416198f - getDistance(a, 5)) < eps);
}

void testForTasks_task9_getDistance_hasNegativeElements() {
    int a[] = {1, -2, 3, -4, 5};
    float eps = 0.000001f;
    assert(fabsf(7.416198f - getDistance(a, 5)) < eps);
}

void testForTasks_task9_insertionSortRowsMatrixByRowCriteriaF() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 3, 1,
                    0, 0, 0,
                    2, 1, 1,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    2, 1, 1,
                    0, 3, 1,
            }, 3, 3
    );

    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task9_insertionSortRowsMatrixByRowCriteriaF_hasNegativeElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, -3, 1,
                    0, 0, 0,
                    -2, 1, -1,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    -2, 1, -1,
                    0, -3, 1,
            }, 3, 3
    );

    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task9_sortByDistances() {
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

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task9_sortByDistances_hasNegativeElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 2, -3,
                    -1, 0, 1,
                    0, 0, -1,
                    0, 0, 0,
                    -1, -1, -1,
            }, 5, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, -1,
                    -1, 0, 1,
                    -1, -1, -1,
                    -1, 2, -3,
            }, 5, 3
    );

    sortByDistances(m);

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task9_sortByDistances_allElementsIsEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 3, 3,
                    3, 3, 3,
                    3, 3, 3,
                    3, 3, 3,
                    3, 3, 3,
            }, 5, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    3, 3, 3,
                    3, 3, 3,
                    3, 3, 3,
                    3, 3, 3,
                    3, 3, 3,
            }, 5, 3
    );

    sortByDistances(m);

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task10_countNUnique() {
    long long a[] = {1, 2, 3, 4, 5};
    assert(countNUnique(a, 5) == 5);
}

void testForTasks_task10_hasEqualElements() {
    long long a[] = {3, 3, 3, 4, 5};
    assert(countNUnique(a, 5) == 3);
}

void testForTasks_task10_hasNegativeElements() {
    long long a[] = {3, -3, 3, -4, 5};
    assert(countNUnique(a, 5) == 4);
}

void testForTasks_task10_countEqClassesByRowsSum_hasNonUniqueRows() {
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

    freeMemMatrix(m);
}

void testForTasks_task10_countEqClassesByRowsSum_allRowsIsUnique() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -7, 1,
                    3, 4,
                    4, 2,
                    6, -1,
                    2, 2,
                    3, 0,
            }, 6, 2
    );

    assert(countEqClassesByRowsSum(m) == 6);

    freeMemMatrix(m);
}

void testForTasks_task10_countEqClassesByRowsSum_allRowsIsNonUnique() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    3, 5,
                    4, 4,
                    6, 2,
                    2, 6,
                    8, 0,
            }, 6, 2
    );

    assert(countEqClassesByRowsSum(m) == 1);

    freeMemMatrix(m);
}

void testForTasks_task11_getNSpecialElement() {
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

    freeMemMatrix(m);
    freeMemMatrix(n);
    freeMemMatrix(k);
}

void testForTasks_task11_getNSpecialElement_hasNegativeElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -3, -5, 5, 4,
                    2, 3, -6, -7,
                    12, 2, 1, 2,
            }, 3, 4
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    3, -5, 5, -4,
                    -2, 3, -6, 7,
                    12, 22, 22, 2,
            }, 3, 4
    );

    matrix k = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, -7,
                    -1, 8, 11, 3,
            }, 3, 4
    );

    assert(getNSpecialElement(m) == 4);
    assert(getNSpecialElement(n) == 4);
    assert(getNSpecialElement(k) == 2);

    freeMemMatrix(m);
    freeMemMatrix(n);
    freeMemMatrix(k);
}

void testForTasks_task11_getNSpecialElement_notHasSpecialElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 8, 3, 3,
                    5, 3, 8, 3,
                    8, 5, 5, 6,
            }, 3, 4
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    3, -5, 5, -4,
                    -2, 3, -6, 7,
                    1, -2, -1, 3,
            }, 3, 4
    );


    assert(getNSpecialElement(m) == 0);
    assert(getNSpecialElement(n) == 4);

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task12_getLeftMin() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 8, 3, 3,
                    5, 3, 8, 3,
                    8, 5, 5, 6,
            }, 3, 4
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    3, -5, 5, -4,
                    -3, 3, -6, 7,
                    1, -2, -1, 3,
            }, 3, 4
    );

    assert(getLeftMin(m).rowIndex == 0 && getLeftMin(m).colIndex == 0);
    assert(getLeftMin(n).rowIndex == 1 && getLeftMin(n).colIndex == 2);

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task12_getLeftMin_hasEqualElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 8, 3, 3,
                    5, 3, 1, 3,
                    8, 5, 5, 6,
            }, 3, 4
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    3, -5, 5, -4,
                    -6, 3, -6, 7,
                    1, -2, -1, 3,
            }, 3, 4
    );

    assert(getLeftMin(m).rowIndex == 0 && getLeftMin(m).colIndex == 0);
    assert(getLeftMin(n).rowIndex == 1 && getLeftMin(n).colIndex == 0);

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task12_swapPenultimateRow() {
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

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task12_swapPenultimateRow_hasNegativeAndEqualElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    -4, 2, 6,
                    7, -8, 1,
            }, 3, 3
    );

    matrix n = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 2, -8,
                    7, -8, 1,
            }, 3, 3
    );

    swapPenultimateRow(m);

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void testForTasks_task13_isNonDescendingSorted() {
    int a[] = {1, 2, 3, 4, 5};
    assert(isNonDescendingSorted(a, 5));
}

void testForTasks_task13_isNonDescendingSorted_hasEqualElements() {
    int a[] = {1, 3, 3, 3, 5};
    assert(isNonDescendingSorted(a, 5));
}

void testForTasks_task13_isNonDescendingSorted_isNonIncreasingSorted() {
    int a[] = {5, 4, 3, 3, 1};
    assert(!isNonDescendingSorted(a, 5));
}

void testForTasks_task13_isNonDescendingSorted_isChaoticSorted() {
    int a[] = {5, 4, 3, 7, 1};
    assert(!isNonDescendingSorted(a, 5));
}

void testForTasks_task13_hasAllNonDescendingRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            }, 3, 3
    );

    assert(hasAllNonDescendingRows(m));

    freeMemMatrix(m);
}

void testForTasks_task13_hasAllNonDescendingRows_notHasAllNonDescendingRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1,
            }, 3, 3
    );

    assert(!hasAllNonDescendingRows(m));

    freeMemMatrix(m);
}

void testForTasks_task13_hasAllNonDescendingRows_allElementsIsEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 3, 3,
                    3, 3, 3,
                    3, 3, 3,
            }, 3, 3
    );

    assert(hasAllNonDescendingRows(m));

    freeMemMatrix(m);
}

void testForTasks_task13_countNonDescendingRowsMatrices() {
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

    freeMemMatrices(ms, nMatrices);
}

void testForTasks_task13_countNonDescendingRowsMatrices_hasEqualElements() {
    size_t nMatrices = 4;
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    1, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    9, 9,
            },
            nMatrices, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, nMatrices) == 3);

    freeMemMatrices(ms, nMatrices);
}

void testForTasks_task13_countNonDescendingRowsMatrices_hasNegativeElements() {
    size_t nMatrices = 4;
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    1, 1,
                    -1, 1,

                    1, 6,
                    -2, 2,

                    5, -4,
                    2, 3,

                    1, 3,
                    9, 9,
            },
            nMatrices, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, nMatrices) == 3);

    freeMemMatrices(ms, nMatrices);
}

void testForTasks_task14_countValues() {
    int a[] = {1, 2, 3, 4, 5};
    assert(countValues(a, 5, 1) == 1);
}

void testForTasks_task14_countValues_hasEqualElements() {
    int a[] = {1, 2, 1, 4, 1};
    assert(countValues(a, 5, 1) == 3);
}

void testForTasks_task14_countValues_dontHasValue() {
    int a[] = {1, 2, 1, 4, 1};
    assert(countValues(a, 5, 6) == 0);
}

void testForTasks_task14_countZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    1, 1, 1,
            }, 5, 3
    );

    assert(countZeroRows(m) == 2);

    freeMemMatrix(m);
}

void testForTasks_task14_countZeroRows_dontHasZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    0, 4, 0,
                    0, 0, 1,
                    1, 2, 0,
                    1, 1, 1,
            }, 5, 3
    );

    assert(countZeroRows(m) == 0);

    freeMemMatrix(m);
}

void testForTasks_task14_countZeroRows_allRowsAreZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            }, 5, 3
    );

    assert(countZeroRows(m) == 5);

    freeMemMatrix(m);
}

void testForTasks_task15_getNormOfMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 12, 2,
                    0, 3, 0,
                    6, 0, 3,
            }, 3, 3
    );

    assert(getNormOfMatrix(m) == 12);

    freeMemMatrix(m);
}

void testForTasks_task15_getNormOfMatrix_hasNegativeElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 4, 2,
                    0, -3, -9,
                    6, 0, 3,
            }, 3, 3
    );

    assert(getNormOfMatrix(m) == 9);

    freeMemMatrix(m);
}

void testForTask1() {
    testForTasks_task1();
    testForTasks_task1_minAndMaxInOneRow();
}

void testForTask2() {
    testForTasks_task2_getMax();
    testForTasks_task2_getMax_allElementsIsEqual();
    testForTasks_task2_getMax_maxIsNegative();
    testForTasks_task2_sortRowsByMaxElement();
    testForTasks_task2_sortRowsByMaxElement_maxElementsIsEqual();
}

void testForTask3() {
    testForTasks_task3_getMin();
    testForTasks_task3_getMin_maxIsNegative();
    testForTasks_task3_getMin_allElementsIsEqual();
    testForTasks_task3_sortColsByMinElement();
    testForTasks_task3_sortColsByMinElement_minElementsIsEqual();
}

void testForTask4() {
    testForTasks_task4_mulMatrices();
    testForTasks_task4_mulMatrices_mulWithEMatrix();
    testForTasks_task4_getSquareOfMatrixIfSymmetric();
    testForTasks_task4_getSquareOfMatrixIfSymmetric_isNotSymmetric();
    testForTasks_task4_getSquareOfMatrixIfSymmetric_isEMatrix();
}

void testForTask5() {
    testForTasks_task5_isUnique();
    testForTasks_task5_isUnique_hasNegativeElements();
    testForTasks_task5_isUnique_isNonUnique();
    testForTasks_task5_getSum();
    testForTasks_task5_getSum_hasNegativeElements();
    testForTasks_task5_transposeIfMatrixHasNotEqualSumOfRows_isUniqueRows();
    testForTasks_task5_transposeIfMatrixHasNotEqualSumOfRows_isNonUniqueRows();
}

void testForTask6() {
    testForTasks_task6_isMutuallyInverseMatrices_isMutuallyInverse();
    testForTasks_task6_isMutuallyInverseMatrices_isNonMutuallyInverse();
}

void testForTask7() {
    testForTasks_task7_max();
    testForTasks_task7_max_isEqualValues();
    testForTasks_task7_max_hasNegativeValues();
    testForTasks_task7_findSumOfMaxesOfPseudoDiagonal();
    testForTasks_task7_findSumOfMaxesOfPseudoDiagonal_hasNegativeElements();
    testForTasks_task7_findSumOfMaxesOfPseudoDiagonal_allElementsIsEqual();
}

void testForTask8() {
    testForTasks_task8_findMin();
    testForTasks_task8_findMin_hasNegativeElements();
    testForTasks_task8_getMinInArea();
    testForTasks_task8_getMinInArea_hasNegativeElements();
}

void testForTask9() {
    testForTasks_task9_getDistance();
    testForTasks_task9_getDistance_hasNegativeElements();
    testForTasks_task9_insertionSortRowsMatrixByRowCriteriaF();
    testForTasks_task9_insertionSortRowsMatrixByRowCriteriaF_hasNegativeElements();
    testForTasks_task9_sortByDistances();
    testForTasks_task9_sortByDistances_hasNegativeElements();
    testForTasks_task9_sortByDistances_allElementsIsEqual();
}

void testForTask10() {
    testForTasks_task10_countNUnique();
    testForTasks_task10_hasEqualElements();
    testForTasks_task10_hasNegativeElements();
    testForTasks_task10_countEqClassesByRowsSum_hasNonUniqueRows();
    testForTasks_task10_countEqClassesByRowsSum_allRowsIsUnique();
    testForTasks_task10_countEqClassesByRowsSum_allRowsIsNonUnique();
}

void testForTask11() {
    testForTasks_task11_getNSpecialElement();
    testForTasks_task11_getNSpecialElement_hasNegativeElements();
    testForTasks_task11_getNSpecialElement_notHasSpecialElements();
}

void testForTask12() {
    testForTasks_task12_getLeftMin();
    testForTasks_task12_getLeftMin_hasEqualElements();
    testForTasks_task12_swapPenultimateRow();
    testForTasks_task12_swapPenultimateRow_hasNegativeAndEqualElements();
}

void testForTask13() {
    testForTasks_task13_isNonDescendingSorted();
    testForTasks_task13_isNonDescendingSorted_hasEqualElements();
    testForTasks_task13_isNonDescendingSorted_isNonIncreasingSorted();
    testForTasks_task13_isNonDescendingSorted_isChaoticSorted();
    testForTasks_task13_hasAllNonDescendingRows();
    testForTasks_task13_hasAllNonDescendingRows_notHasAllNonDescendingRows();
    testForTasks_task13_hasAllNonDescendingRows_allElementsIsEqual();
    testForTasks_task13_countNonDescendingRowsMatrices();
    testForTasks_task13_countNonDescendingRowsMatrices_hasEqualElements();
    testForTasks_task13_countNonDescendingRowsMatrices_hasNegativeElements();
}

void testForTask14() {
    testForTasks_task14_countValues();
    testForTasks_task14_countValues_hasEqualElements();
    testForTasks_task14_countValues_dontHasValue();
    testForTasks_task14_countZeroRows();
    testForTasks_task14_countZeroRows_dontHasZeroRows();
    testForTasks_task14_countZeroRows_allRowsAreZeroRows();
}

void testForTask15() {
    testForTasks_task15_getNormOfMatrix();
    testForTasks_task15_getNormOfMatrix_hasNegativeElements();
}

void testForTasks() {
    testForTask1();
    testForTask2();
    testForTask3();
    testForTask4();
    testForTask5();
    testForTask6();
    testForTask7();
    testForTask8();
    testForTask9();
    testForTask10();
    testForTask11();
    testForTask12();
    testForTask13();
    testForTask14();
    testForTask15();
}

int main() {

    test();
    testForTasks();

    return 0;
}
