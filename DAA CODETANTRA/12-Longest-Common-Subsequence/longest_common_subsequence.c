/**
 * ============================================================================
 * Program 12: Longest Common Subsequence (LCS)
 * Algorithm Design Paradigm: Dynamic Programming
 * ============================================================================
 * Description:
 *   Given two sequences (strings) X and Y, the Longest Common Subsequence
 *   problem finds the longest sequence that appears in both strings in the
 *   same relative order, but not necessarily contiguous.
 *   This implementation computes the LCS table using bottom-up dynamic
 *   programming, displays the table, and reconstructs the actual LCS string.
 *
 * Time Complexity:
 *   - O(m * n) where m and n are lengths of strings X and Y.
 *
 * Space Complexity:
 *   - O(m * n) for the 2D DP matrix.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Computes and displays the Longest Common Subsequence of strings X and Y.
 */
void lcs(const char *X, const char *Y) {
    int m = (int)strlen(X);
    int n = (int)strlen(Y);

    /* Allocate 2D DP table */
    int **L = (int **)malloc((m + 1) * sizeof(int *));
    if (L == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for LCS table rows.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i <= m; i++) {
        L[i] = (int *)calloc(n + 1, sizeof(int));
        if (L[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation failed for LCS table columns.\n");
            exit(EXIT_FAILURE);
        }
    }

    /* Build DP table in bottom-up manner */
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    int lcsLen = L[m][n];

    /* Backtrack to reconstruct the LCS string */
    char *lcsString = (char *)malloc((lcsLen + 1) * sizeof(char));
    if (lcsString == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for LCS string.\n");
        exit(EXIT_FAILURE);
    }
    lcsString[lcsLen] = '\0'; /* Null-terminate */

    int i = m;
    int j = n;
    int index = lcsLen - 1;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsString[index--] = X[i - 1];
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    /* Print DP table if reasonably small */
    if (m <= 15 && n <= 15) {
        printf("\n----------------------------------------------------\n");
        printf("LCS Dynamic Programming Table L[i][j]:\n");
        printf("----------------------------------------------------\n");
        printf("        Ø  ");
        for (int c = 0; c < n; c++) {
            printf("%3c", Y[c]);
        }
        printf("\n");

        for (int r = 0; r <= m; r++) {
            if (r == 0) {
                printf("  Ø: ");
            } else {
                printf("  %c: ", X[r - 1]);
            }
            for (int c = 0; c <= n; c++) {
                printf("%3d", L[r][c]);
            }
            printf("\n");
        }
    }

    /* Display final results */
    printf("\n----------------------------------------------------\n");
    printf("     Longest Common Subsequence (LCS) Results       \n");
    printf("----------------------------------------------------\n");
    printf("String 1 (X):        \"%s\" (Length: %d)\n", X, m);
    printf("String 2 (Y):        \"%s\" (Length: %d)\n", Y, n);
    printf("Length of LCS:       %d\n", lcsLen);
    printf("LCS Sequence:        \"%s\"\n", lcsLen > 0 ? lcsString : "(None)");
    printf("====================================================\n");

    /* Clean up memory */
    free(lcsString);
    for (int r = 0; r <= m; r++) {
        free(L[r]);
    }
    free(L);
}

int main(void) {
    char X[MAX_LEN];
    char Y[MAX_LEN];

    printf("====================================================\n");
    printf("  DAA Lab Experiment 12: LONGEST COMMON SUBSEQUENCE \n");
    printf("====================================================\n\n");

    printf("Enter first string (X): ");
    if (scanf("%255s", X) != 1) {
        fprintf(stderr, "Error: Failed to read first string.\n");
        return EXIT_FAILURE;
    }

    printf("Enter second string (Y): ");
    if (scanf("%255s", Y) != 1) {
        fprintf(stderr, "Error: Failed to read second string.\n");
        return EXIT_FAILURE;
    }

    lcs(X, Y);

    return EXIT_SUCCESS;
}
