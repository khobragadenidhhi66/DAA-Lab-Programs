/**
 * ============================================================================
 * Program 11: 0/1 Knapsack Problem
 * Algorithm Design Paradigm: Dynamic Programming
 * ============================================================================
 * Description:
 *   Given n items, each with a specific weight and profit, and a knapsack of
 *   capacity W, the 0/1 Knapsack problem seeks to maximize the total profit
 *   without exceeding the knapsack capacity. In 0/1 knapsack, each item must
 *   either be completely chosen or left behind (no fractions allowed).
 *   This implementation uses bottom-up Dynamic Programming and reconstructs
 *   the exact set of items selected in the optimal solution.
 *
 * Time Complexity:
 *   - O(n * W) pseudo-polynomial time.
 *
 * Space Complexity:
 *   - O(n * W) auxiliary table space.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Solves the 0/1 Knapsack problem using Dynamic Programming.
 */
void solveKnapsack(int n, int W, const int weights[], const int profits[]) {
    /* Allocate 2D DP table: (n + 1) rows x (W + 1) cols */
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    if (dp == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for DP rows.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)calloc(W + 1, sizeof(int));
        if (dp[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation failed for DP columns.\n");
            exit(EXIT_FAILURE);
        }
    }

    /* Build DP table in bottom-up manner */
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxProfit = dp[n][W];

    /* Backtrack to find which items were included */
    int selected[MAX_ITEMS];
    int selectCount = 0;
    int currW = W;
    int totalWeightUsed = 0;

    for (int i = n; i > 0 && maxProfit > 0; i--) {
        /* If profit came from including item i - 1 */
        if (dp[i][currW] != dp[i - 1][currW]) {
            selected[selectCount++] = i - 1; /* 0-indexed item */
            totalWeightUsed += weights[i - 1];
            currW -= weights[i - 1];
        }
    }

    /* Print DP Table if reasonable size */
    if (n <= 10 && W <= 20) {
        printf("\n----------------------------------------------------\n");
        printf("Dynamic Programming Table (DP[i][w]):\n");
        printf("----------------------------------------------------\n      ");
        for (int w = 0; w <= W; w++) {
            printf("%4d", w);
        }
        printf("\n");
        for (int i = 0; i <= n; i++) {
            printf("i=%2d: ", i);
            for (int w = 0; w <= W; w++) {
                printf("%4d", dp[i][w]);
            }
            printf("\n");
        }
    }

    /* Print Results */
    printf("\n----------------------------------------------------\n");
    printf("   0/1 Knapsack Optimal Solution Summary            \n");
    printf("----------------------------------------------------\n");
    printf("Knapsack Capacity:     %d\n", W);
    printf("Maximum Total Profit:  %d\n", maxProfit);
    printf("Total Weight Utilized: %d / %d\n", totalWeightUsed, W);
    printf("Number of Items Taken: %d\n", selectCount);
    printf("----------------------------------------------------\n");
    printf("%-10s %-10s %-10s\n", "Item #", "Weight", "Profit");
    printf("----------------------------------------------------\n");

    /* Print selected items in original index order */
    for (int j = selectCount - 1; j >= 0; j--) {
        int idx = selected[j];
        printf("%-10d %-10d %-10d\n", idx + 1, weights[idx], profits[idx]);
    }
    printf("====================================================\n");

    /* Free dynamically allocated memory */
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
}

int main(void) {
    int n, W;
    int weights[MAX_ITEMS];
    int profits[MAX_ITEMS];

    printf("====================================================\n");
    printf("      DAA Lab Experiment 11: 0/1 KNAPSACK (DP)      \n");
    printf("====================================================\n\n");

    printf("Enter number of items (1 to %d): ", MAX_ITEMS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_ITEMS) {
        fprintf(stderr, "Error: Invalid number of items.\n");
        return EXIT_FAILURE;
    }

    printf("Enter maximum knapsack capacity W (1 to %d): ", MAX_CAPACITY);
    if (scanf("%d", &W) != 1 || W <= 0 || W > MAX_CAPACITY) {
        fprintf(stderr, "Error: Invalid knapsack capacity.\n");
        return EXIT_FAILURE;
    }

    printf("\nEnter weights of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &weights[i]) != 1 || weights[i] <= 0) {
            fprintf(stderr, "Error: Item weight must be a positive integer.\n");
            return EXIT_FAILURE;
        }
    }

    printf("\nEnter profits/values of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &profits[i]) != 1 || profits[i] < 0) {
            fprintf(stderr, "Error: Item profit must be non-negative.\n");
            return EXIT_FAILURE;
        }
    }

    printf("\nInput Items:\n");
    printf("%-8s %-10s %-10s\n", "Item #", "Weight", "Profit");
    for (int i = 0; i < n; i++) {
        printf("%-8d %-10d %-10d\n", i + 1, weights[i], profits[i]);
    }

    solveKnapsack(n, W, weights, profits);

    return EXIT_SUCCESS;
}
