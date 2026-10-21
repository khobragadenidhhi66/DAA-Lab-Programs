/**
 * ============================================================================
 * Program 05: Sum of Subsets Problem
 * Algorithm Design Paradigm: Backtracking
 * ============================================================================
 * Description:
 *   Given a set of n positive integers and a target sum M, the Sum of Subsets
 *   problem finds all unique subsets of integers whose sum equals M.
 *   This implementation uses recursive backtracking on a state space tree.
 *   To maximize efficiency, the input array is sorted in ascending order and
 *   bounding functions prune unpromising branches early.
 *
 * Time Complexity:
 *   - Worst Case: O(2^n) (exploring all subsets)
 *   - Pruned Average Case: Significantly faster due to bounding functions.
 *
 * Space Complexity:
 *   - O(n) auxiliary space for recursive stack and solution vector x[].
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Global variables for problem state */
static int w[MAX_SIZE];      /* Array of weights / numbers */
static int x[MAX_SIZE];      /* Solution vector: 1 if included, 0 if excluded */
static int targetSum;        /* Target sum M */
static int totalElements;    /* Total count of weights */
static int solutionCount = 0;/* Total number of solutions found */

/**
 * Comparator for sorting weights in ascending order.
 */
int compareInts(const void *a, const void *b) {
    return (*(const int *)a - *(const int *)b);
}

/**
 * Utility function to print a valid solution subset.
 */
void printSolution(void) {
    solutionCount++;
    printf(" Solution %2d: { ", solutionCount);
    int first = 1;
    int currentSum = 0;
    for (int i = 0; i < totalElements; i++) {
        if (x[i] == 1) {
            if (!first) {
                printf(", ");
            }
            printf("%d", w[i]);
            currentSum += w[i];
            first = 0;
        }
    }
    printf(" } -> Sum = %d\n", currentSum);
}

/**
 * Recursive backtracking function for Sum of Subsets.
 *
 * @param currentSum    Accumulated sum of elements included so far.
 * @param k             Current index in the array w being considered.
 * @param remainingSum  Sum of all remaining available elements from index k onward.
 */
void sumOfSubsets(int currentSum, int k, int remainingSum) {
    /* Generate left child: Include w[k] */
    x[k] = 1;

    if (currentSum + w[k] == targetSum) {
        /* Subset with target sum found */
        printSolution();
    } else if (k + 1 < totalElements && currentSum + w[k] + w[k + 1] <= targetSum) {
        /* Explore further down left child */
        sumOfSubsets(currentSum + w[k], k + 1, remainingSum - w[k]);
    }

    /* Generate right child: Exclude w[k] */
    x[k] = 0;

    /* Bounding condition for right child */
    if (k + 1 < totalElements &&
        currentSum + remainingSum - w[k] >= targetSum &&
        currentSum + w[k + 1] <= targetSum) {
        sumOfSubsets(currentSum, k + 1, remainingSum - w[k]);
    }
}

int main(void) {
    int totalSum = 0;

    printf("====================================================\n");
    printf("    DAA Lab Experiment 05: SUM OF SUBSETS (BACKTRACKING) \n");
    printf("====================================================\n\n");

    printf("Enter number of elements (1 to %d): ", MAX_SIZE);
    if (scanf("%d", &totalElements) != 1 || totalElements <= 0 || totalElements > MAX_SIZE) {
        fprintf(stderr, "Error: Invalid number of elements.\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d positive integers:\n", totalElements);
    for (int i = 0; i < totalElements; i++) {
        if (scanf("%d", &w[i]) != 1 || w[i] <= 0) {
            fprintf(stderr, "Error: Elements must be positive integers.\n");
            return EXIT_FAILURE;
        }
        totalSum += w[i];
        x[i] = 0;
    }

    printf("Enter the target sum (M): ");
    if (scanf("%d", &targetSum) != 1 || targetSum <= 0) {
        fprintf(stderr, "Error: Target sum must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    /* Sort weights in ascending order for pruning */
    qsort(w, totalElements, sizeof(int), compareInts);

    printf("\n----------------------------------------------------\n");
    printf("Sorted Input Elements: ");
    for (int i = 0; i < totalElements; i++) {
        printf("%d ", w[i]);
    }
    printf("\nTarget Sum (M):         %d\n", targetSum);
    printf("Total Sum of Elements:  %d\n", totalSum);
    printf("----------------------------------------------------\n");
    printf("Finding subsets that sum to %d...\n\n", targetSum);

    if (totalSum < targetSum || w[0] > targetSum) {
        printf("No subset is possible (Target exceeds total sum or is smaller than smallest element).\n");
    } else {
        solutionCount = 0;
        sumOfSubsets(0, 0, totalSum);

        if (solutionCount == 0) {
            printf("No subset exists that sums to %d.\n", targetSum);
        } else {
            printf("\nTotal distinct subsets found: %d\n", solutionCount);
        }
    }

    printf("====================================================\n");
    return EXIT_SUCCESS;
}
