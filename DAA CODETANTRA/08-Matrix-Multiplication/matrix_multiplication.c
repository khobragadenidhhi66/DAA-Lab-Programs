/**
 * ============================================================================
 * Program 08: Strassen's Matrix Multiplication Algorithm
 * Algorithm Design Paradigm: Divide and Conquer
 * ============================================================================
 * Description:
 *   Standard matrix multiplication requires O(n^3) operations.
 *   Volker Strassen (1969) introduced a Divide and Conquer method that
 *   partitions each matrix into 4 equal sub-matrices and computes the product
 *   using only 7 recursive multiplications (instead of 8) along with 18
 *   matrix additions and subtractions.
 *
 *   This implementation supports any arbitrary n x n dimension by automatically
 *   padding matrices to the next power of 2, computes the product using
 *   Strassen's algorithm, and cross-verifies with the standard O(n^3) method.
 *
 * Time Complexity:
 *   - Strassen's Algorithm: O(n^(log2 7)) approx O(n^2.807)
 *   - Standard Algorithm:   O(n^3)
 *
 * Space Complexity:
 *   - O(n^2) auxiliary memory for sub-matrices.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIM 64

/**
 * Allocates a 2D square matrix of size n x n.
 */
int **allocateMatrix(int n) {
    int **mat = (int **)malloc(n * sizeof(int *));
    if (mat == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for row pointers.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)calloc(n, sizeof(int));
        if (mat[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation failed for matrix columns.\n");
            exit(EXIT_FAILURE);
        }
    }
    return mat;
}

/**
 * Frees a dynamically allocated 2D square matrix.
 */
void freeMatrix(int **mat, int n) {
    if (mat == NULL) return;
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

/**
 * Adds two n x n matrices: C = A + B
 */
void addMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/**
 * Subtracts two n x n matrices: C = A - B
 */
void subtractMatrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/**
 * Standard O(n^3) iterative matrix multiplication.
 */
void standardMultiply(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/**
 * Recursive Strassen's Matrix Multiplication.
 * Assumption: n is a power of 2.
 */
void strassenRecursive(int **A, int **B, int **C, int n) {
    /* Base case: when matrix size is 1x1 */
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    /* For small submatrices (n <= 2), standard multiply is often faster and avoids overhead */
    if (n <= 2) {
        standardMultiply(A, B, C, n);
        return;
    }

    int half = n / 2;

    /* Allocate sub-matrices */
    int **A11 = allocateMatrix(half);
    int **A12 = allocateMatrix(half);
    int **A21 = allocateMatrix(half);
    int **A22 = allocateMatrix(half);

    int **B11 = allocateMatrix(half);
    int **B12 = allocateMatrix(half);
    int **B21 = allocateMatrix(half);
    int **B22 = allocateMatrix(half);

    /* Divide matrices A and B into 4 sub-matrices */
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    /* Temporary matrices for arithmetic */
    int **tempA = allocateMatrix(half);
    int **tempB = allocateMatrix(half);

    /* 7 Strassen products M1 to M7 */
    int **M1 = allocateMatrix(half);
    int **M2 = allocateMatrix(half);
    int **M3 = allocateMatrix(half);
    int **M4 = allocateMatrix(half);
    int **M5 = allocateMatrix(half);
    int **M6 = allocateMatrix(half);
    int **M7 = allocateMatrix(half);

    /* M1 = (A11 + A22) * (B11 + B22) */
    addMatrix(A11, A22, tempA, half);
    addMatrix(B11, B22, tempB, half);
    strassenRecursive(tempA, tempB, M1, half);

    /* M2 = (A21 + A22) * B11 */
    addMatrix(A21, A22, tempA, half);
    strassenRecursive(tempA, B11, M2, half);

    /* M3 = A11 * (B12 - B22) */
    subtractMatrix(B12, B22, tempB, half);
    strassenRecursive(A11, tempB, M3, half);

    /* M4 = A22 * (B21 - B11) */
    subtractMatrix(B21, B11, tempB, half);
    strassenRecursive(A22, tempB, M4, half);

    /* M5 = (A11 + A12) * B22 */
    addMatrix(A11, A12, tempA, half);
    strassenRecursive(tempA, B22, M5, half);

    /* M6 = (A21 - A11) * (B11 + B12) */
    subtractMatrix(A21, A11, tempA, half);
    addMatrix(B11, B12, tempB, half);
    strassenRecursive(tempA, tempB, M6, half);

    /* M7 = (A12 - A22) * (B21 + B22) */
    subtractMatrix(A12, A22, tempA, half);
    addMatrix(B21, B22, tempB, half);
    strassenRecursive(tempA, tempB, M7, half);

    /* Calculate C11, C12, C21, C22 */
    /* C11 = M1 + M4 - M5 + M7 */
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + half] = M3[i][j] + M5[i][j];               /* C12 = M3 + M5 */
            C[i + half][j] = M2[i][j] + M4[i][j];               /* C21 = M2 + M4 */
            C[i + half][j + half] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j]; /* C22 = M1 - M2 + M3 + M6 */
        }
    }

    /* Free all allocated intermediate matrices */
    freeMatrix(A11, half); freeMatrix(A12, half);
    freeMatrix(A21, half); freeMatrix(A22, half);
    freeMatrix(B11, half); freeMatrix(B12, half);
    freeMatrix(B21, half); freeMatrix(B22, half);
    freeMatrix(tempA, half); freeMatrix(tempB, half);
    freeMatrix(M1, half); freeMatrix(M2, half);
    freeMatrix(M3, half); freeMatrix(M4, half);
    freeMatrix(M5, half); freeMatrix(M6, half);
    freeMatrix(M7, half);
}

/**
 * Finds the nearest power of 2 greater than or equal to n.
 */
int nextPowerOf2(int n) {
    int p = 1;
    while (p < n) {
        p <<= 1;
    }
    return p;
}

/**
 * Prints an n x n matrix cleanly.
 */
void printMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("  [ ");
        for (int j = 0; j < cols; j++) {
            printf("%5d ", mat[i][j]);
        }
        printf("]\n");
    }
}

int main(void) {
    int n;

    printf("====================================================\n");
    printf("   DAA Lab Experiment 08: STRASSEN'S MATRIX MULT    \n");
    printf("====================================================\n\n");

    printf("Enter dimension n for square matrices (n x n, max %d): ", MAX_DIM);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_DIM) {
        fprintf(stderr, "Error: Invalid dimension.\n");
        return EXIT_FAILURE;
    }

    int paddedSize = nextPowerOf2(n);

    int **A = allocateMatrix(paddedSize);
    int **B = allocateMatrix(paddedSize);
    int **C_strassen = allocateMatrix(paddedSize);
    int **C_standard = allocateMatrix(paddedSize);

    printf("\nEnter elements of Matrix A (%d x %d) row by row:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
                fprintf(stderr, "Error: Failed to read Matrix A[%d][%d].\n", i, j);
                return EXIT_FAILURE;
            }
        }
    }

    printf("\nEnter elements of Matrix B (%d x %d) row by row:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &B[i][j]) != 1) {
                fprintf(stderr, "Error: Failed to read Matrix B[%d][%d].\n", i, j);
                return EXIT_FAILURE;
            }
        }
    }

    printf("\n----------------------------------------------------\n");
    printf("Matrix A:\n");
    printMatrix(A, n, n);

    printf("\nMatrix B:\n");
    printMatrix(B, n, n);

    /* Perform Strassen's Matrix Multiplication */
    strassenRecursive(A, B, C_strassen, paddedSize);

    /* Perform Standard O(n^3) Matrix Multiplication for comparison */
    standardMultiply(A, B, C_standard, n);

    printf("----------------------------------------------------\n");
    printf("Resultant Matrix C (via Strassen's Algorithm):\n");
    printMatrix(C_strassen, n, n);

    printf("\nResultant Matrix C (via Standard O(n^3) Algorithm):\n");
    printMatrix(C_standard, n, n);

    /* Verify correctness */
    bool match = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (C_strassen[i][j] != C_standard[i][j]) {
                match = false;
                break;
            }
        }
    }

    printf("----------------------------------------------------\n");
    if (match) {
        printf("[SUCCESS] Both Strassen and Standard results match perfectly!\n");
    } else {
        printf("[FAILURE] Discrepancy detected between algorithms!\n");
    }
    printf("====================================================\n");

    /* Free all memory */
    freeMatrix(A, paddedSize);
    freeMatrix(B, paddedSize);
    freeMatrix(C_strassen, paddedSize);
    freeMatrix(C_standard, paddedSize);

    return EXIT_SUCCESS;
}
