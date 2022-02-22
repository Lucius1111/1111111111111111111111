#include "matrix.h"
#include "../../algorithms/algorithm.h"

//testingStart//
void test_swapRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 3
    );
    swapRows(m, 0, 1);
    assert(m.values[0][0] == 0 && m.values[0][1] == 0 && m.values[0][2] == 0 &&
           m.values[1][0] == 1 && m.values[1][1] == 1 && m.values[1][2] == 0);

    freeMemMatrix(m);

};

void test_swapColumns() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 3
    );
    swapColumns(m, 0, 2);
    assert(m.values[0][0] == 0 && m.values[1][0] == 0 && m.values[2][0] == 1 && m.values[3][0] == 0 &&
           m.values[4][0] == 1 && m.values[0][2] == 1 && m.values[1][2] == 0 && m.values[2][2] == 0 &&
           m.values[3][2] == 0 && m.values[4][2] == 0);

    freeMemMatrix(m);

}

void test_areTwoMatricesEqual_isEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 0, 1,
                    0, 0, 1,
                    0, 0, 0,
                    1, 1, 1,
            },
            5, 3
    );
    matrix n = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 0, 1,
                    0, 0, 1,
                    0, 0, 0,
                    1, 1, 1,
            }, 5, 3
    );

    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);

}

void test_areTwoMatricesEqual_isNonEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 0, 1,
                    0, 0, 1,
                    0, 0, 0,
                    1, 1, 1,
            },
            5, 3
    );
    matrix n = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    1, 0, 1,
                    0, 0, 0,
                    0, 0, 0,
                    1, 0, 1,
            }, 5, 3
    );

    assert(!areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);

}

void test_areTwoMatricesEqual_differentDimension() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 0, 1,
                    0, 0, 1,
                    0, 0, 0,
                    1, 1, 1,
            },
            5, 3
    );
    matrix n = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    1, 0, 1,
                    0, 0, 0,
            }, 3, 3
    );

    assert(!areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);

}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 0, 1,
                    0, 0, 1,
                    0, 0, 0,
                    1, 1, 1,
            },
            5, 3
    );
    matrix n = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 1,
                    1, 0, 1,
                    1, 1, 1,
                    1, 2, 3,
            },
            5, 3
    );

    insertionSortRowsMatrixByRowCriteria(m, getSum);
    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);

}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 0, 1,
                    4, 0, 1,
                    0, 0, 0,
                    1, 1, 1,
            },
            5, 3
    );
    matrix n = createMatrixFromArray(
            (int[]) {
                    2, 3, 1,
                    0, 1, 1,
                    0, 1, 4,
                    0, 0, 0,
                    1, 1, 1,
            },
            5, 3
    );

    insertionSortColsMatrixByColCriteria(m, getSum);
    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void test_isSquareMatrix_isSquare() {
    matrix m = getMemMatrix(3, 3);
    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_isSquareMatrix_isNonSquare() {
    matrix m = getMemMatrix(5, 3);
    assert(!isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_isE() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            }, 3, 3
    );

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_isNonE_isSquare() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 3,
                    0, 1, 0,
                    2, 0, 1,
            }, 3, 3
    );

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_isNonE_isNonSquare() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 3,
                    0, 1, 0,
                    2, 0, 1,
                    3, 1, 0,
                    2, 3, 4
            }, 5, 3
    );

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_isSymmetric() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    1, 1, 3,
                    2, 3, 1,
            }, 3, 3
    );

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_isNonSymmetric_isSquare() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 3,
                    5, 1, 4,
                    2, 0, 1,
            }, 3, 3
    );

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_isNonSymmetric_isNonSquare() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 3,
                    0, 1, 0,
                    2, 0, 1,
                    3, 1, 0,
                    2, 3, 4
            }, 5, 3
    );

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 3,
                    5, 1, 4,
                    2, 0, 1,
            }, 3, 3
    );
    matrix n = createMatrixFromArray(
            (int[]) {
                    1, 5, 2,
                    0, 1, 0,
                    3, 4, 1,
            }, 3, 3
    );

    transposeSquareMatrix(m);
    assert(areTwoMatricesEqual(m, n));

    freeMemMatrix(m);
    freeMemMatrix(n);
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 2, 3,
                    5, 6, 9,
                    1, 7, 8,
            }, 3, 3
    );
    assert(getMinValuePos(m).rowIndex == 2 && getMinValuePos(m).colIndex == 0);

    freeMemMatrix(m);
}

void test() {
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_areTwoMatricesEqual_differentDimension();
    test_areTwoMatricesEqual_isNonEqual();
    test_areTwoMatricesEqual_isEqual();
    test_isSquareMatrix_isSquare();
    test_isSquareMatrix_isNonSquare();
    test_isEMatrix_isE();
    test_isEMatrix_isNonE_isSquare();
    test_isEMatrix_isNonE_isNonSquare();
    test_isSymmetricMatrix_isSymmetric();
    test_isSymmetricMatrix_isNonSymmetric_isSquare();
    test_isSymmetricMatrix_isNonSymmetric_isNonSquare();
    test_transposeSquareMatrix();
    test_getMinValuePos();
}
//testingEnd//

matrix getMemMatrix(const size_t nRows, const size_t nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (size_t i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (size_t i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, size_t nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, size_t nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, size_t nMatrices) {
    for (size_t i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void isRightIndex(size_t ambit, size_t index) {
    if (index >= ambit) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(2);
    }
}

void swapRows(matrix m, size_t i1, size_t i2) {
    isRightIndex(m.nRows, i1);
    isRightIndex(m.nRows, i2);
    swap(&m.values[i1], &m.values[i2], sizeof(int *));
}

void swapColumns(matrix m, size_t j1, size_t j2) {
    isRightIndex(m.nCols, j1);
    isRightIndex(m.nCols, j2);
    for (size_t i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1], &m.values[i][j2], sizeof(int));
}

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, size_t)) {
    int mCriteria[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        mCriteria[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 1; i < m.nRows; i++) {
        size_t j = i;
        while (j > 0 && mCriteria[j - 1] > mCriteria[j]) {
            swap(&mCriteria[j - 1], &mCriteria[j], sizeof(int));
            swapRows(m, j, j - 1);
            j--;
        }
    }
}

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, size_t)) {
    int mCriteria[m.nCols];
    for (size_t i = 0; i < m.nCols; i++) {
        int mElements[m.nRows];

        for (size_t j = 0; j < m.nRows; j++)
            mElements[j] = m.values[j][i];
        mCriteria[i] = criteria(mElements, m.nRows);
    }
    for (size_t i = 1; i < m.nCols; i++) {
        size_t j = i;
        while (j > 0 && mCriteria[j - 1] > mCriteria[j]) {
            swap(&mCriteria[j - 1], &mCriteria[j], sizeof(int));
            swapColumns(m, j, j - 1);
            j--;
        }
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    bool isEqual = m1.nRows == m2.nRows && m1.nCols == m2.nCols;
    for (size_t i = 0; i < m1.nRows && isEqual; i++)
        for (size_t j = 0; j < m1.nCols && isEqual; j++)
            if (m1.values[i][j] != m2.values[i][j])
                isEqual = false;

    return isEqual;
}

bool isEMatrix(matrix m) {
    bool isEMatrix = isSquareMatrix(m);
    for (size_t i = 0; i < m.nRows && isEMatrix; i++)
        for (size_t j = 0; j < m.nCols && isEMatrix; j++)
            if (i != j && m.values[i][j] != 0 || i == j && m.values[i][i] != 1)
                isEMatrix = false;

    return isEMatrix;
}

bool isSymmetricMatrix(matrix m) {
    bool isSymmetric = isSquareMatrix(m);
    for (size_t i = 0; i < m.nRows && isSymmetric; i++)
        for (size_t j = 0; j < i && isSymmetric; j++)
            if (m.values[i][j] != m.values[j][i])
                isSymmetric = false;

    return isSymmetric;
}

void transposeSquareMatrix(matrix m) {
    if (!isSquareMatrix(m)) {
        fprintf(stderr, "not square matrix");
        exit(3);
    }
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = i; j < m.nCols; j++)
            swap(&m.values[i][j], &m.values[j][i], sizeof(int));
}

position getMinValuePos(matrix m) {
    position minValuePos = (position) {0, 0};
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[minValuePos.rowIndex][minValuePos.colIndex]) {
                minValuePos.rowIndex = i;
                minValuePos.colIndex = j;
            }

    return minValuePos;
}

position getMaxValuePos(matrix m) {
    position maxValuePos = (position) {0, 0};
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (m.values[i][j] > m.values[maxValuePos.rowIndex][maxValuePos.colIndex]) {
                maxValuePos.rowIndex = i;
                maxValuePos.colIndex = j;
            }

    return maxValuePos;
}

matrix createMatrixFromArray(const int *a, size_t nRows,
                             size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    size_t k = 0;
    for (size_t i = 0; i < nRows; i++)
        for (size_t j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices,
                                     size_t nRows,
                                     size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int findMaximumOfPseudoDiagonal(matrix m, size_t i, size_t j) {
    int maximum = m.values[i][j];
    while (i + 1 < m.nRows && j + 1 < m.nCols) {
        maximum = max(maximum, m.values[i + 1][j + 1]);
        i++;
        j++;
    }

    return maximum;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;
    for (size_t i = 1; i < max(m.nRows, m.nCols); i++) {
        if (i < m.nRows)
            sum += findMaximumOfPseudoDiagonal(m, i, 0);
        if (i < m.nCols)
            sum += findMaximumOfPseudoDiagonal(m, 0, i);
    }

    return sum;
}

int findMin(matrix m, size_t left, size_t right, int row) {
    int minimalValue = m.values[row][left];
    for (size_t i = left + 1; i < right + 1; i++)
        if (m.values[row][i] < minimalValue)
            minimalValue = m.values[row][i];

    return minimalValue;
}

int getMinInArea(matrix m) {
    position min = getMaxValuePos(m);
    size_t left = min.colIndex;
    size_t right = min.colIndex;
    int row = min.rowIndex;
    int minimum = findMin(m, left, right, row);
    left = left == 0 ? 0 : left - 1;
    right = right == m.nCols - 1 ? right : (right + 1);
    row--;

    while (row >= 0) {
        int newMin = findMin(m, left, right, row);
        minimum = minimum > newMin ? newMin : minimum;
        left = left == 0 ? 0 : left - 1;
        right = right == m.nCols - 1 ? right : (right + 1);
        row--;
    }

    return minimum;
}

float getDistance(int *a, int n) {
    float sumSqrt = 0;
    for (size_t i = 0; i < n; i++)
        sumSqrt += powf(a[i], 2.0f);

    return sqrtf(sumSqrt);

}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(int *, int)) {
    float mCriteria[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        mCriteria[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 1; i < m.nRows; i++) {
        size_t j = i;
        while (j > 0 && mCriteria[j - 1] > mCriteria[j]) {
            swap(&mCriteria[j - 1], &mCriteria[j], sizeof(int));
            swapRows(m, j, j - 1);
            j--;
        }
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);

    int countUnique = 1;
    for (size_t i = 0; i < n - 1; i++)
        if (a[i] != a[i + 1])
            countUnique++;

    return countUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long sumRows[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        sumRows[i] = getSum(m.values[i], m.nCols);

    return countNUnique(sumRows, m.nRows);
}


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


