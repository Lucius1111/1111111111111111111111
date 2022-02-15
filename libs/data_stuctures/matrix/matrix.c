#include "matrix.h"
#include "../../algorithms/algorithm.h"

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
        for (size_t j = 0; j < m.nCols; j++)
            swap(&m.values[i][j], &m.values[j][i], sizeof(int));
}

position getMinValuePos(matrix m) {
    position minValuePos = (position) {0, 0};
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 1; j < m.nCols; j++)
            if (m.values[i][j] < m.values[minValuePos.rowIndex]
            [minValuePos.colIndex]) {
                minValuePos.rowIndex = i;
                minValuePos.colIndex = j;
            }

    return minValuePos;
}

position getMaxValuePos(matrix m) {
    position maxValuePos = (position) {0, 0};
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 1; j < m.nCols; j++)
            if (m.values[i][j] > m.values[maxValuePos.rowIndex]
            [maxValuePos.colIndex]) {
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