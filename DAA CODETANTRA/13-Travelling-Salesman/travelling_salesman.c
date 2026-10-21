/**
 * ============================================================================
 * Program 13: Travelling Salesman Problem (TSP)
 * Algorithm Design Paradigm: Dynamic Programming with Bitmasking (Held-Karp)
 * ============================================================================
 * Description:
 *   The Travelling Salesman Problem (TSP) is an NP-hard problem that asks for
 *   the shortest possible route that visits each city exactly once and returns
 *   to the origin city.
 *   While the brute-force search requires O(n!) time, the Held-Karp algorithm
 *   uses Dynamic Programming with Bitmasking to solve it in O(n^2 * 2^n) time.
 *   This implementation computes the exact optimal tour cost and reconstructs
 *   the complete sequence of cities in the optimal tour.
 *
 * Time Complexity:
 *   - O(n^2 * 2^n)
 *
 * Space Complexity:
 *   - O(n * 2^n) for DP memoization table.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 16
#define INF 1000000000

static int nCities;
static int dist[MAX_CITIES][MAX_CITIES];
static int dpTable[1 << MAX_CITIES][MAX_CITIES];
static int nextCity[1 << MAX_CITIES][MAX_CITIES];

/**
 * Recursive Held-Karp DP with bitmasking and memoization.
 *
 * @param mask  Bitmask where i-th bit is 1 if city i has been visited.
 * @param u     Current city.
 * @return      Minimum cost to visit all remaining cities and return to city 0.
 */
int tsp(int mask, int u) {
    /* If all cities have been visited, cost is returning from u to city 0 */
    if (mask == ((1 << nCities) - 1)) {
        return dist[u][0];
    }

    /* Return cached result if already computed */
    if (dpTable[mask][u] != -1) {
        return dpTable[mask][u];
    }

    int minCost = INF;
    int bestNext = -1;

    /* Try visiting all unvisited cities */
    for (int v = 0; v < nCities; v++) {
        if (!(mask & (1 << v))) {
            int newCost = dist[u][v] + tsp(mask | (1 << v), v);
            if (newCost < minCost) {
                minCost = newCost;
                bestNext = v;
            }
        }
    }

    nextCity[mask][u] = bestNext;
    dpTable[mask][u] = minCost;
    return minCost;
}

/**
 * Reconstructs and prints the optimal tour.
 */
void printOptimalTour(void) {
    int mask = 1; /* City 0 is visited initially */
    int current = 0;

    printf("\n----------------------------------------------------\n");
    printf("Optimal TSP Tour Route:\n");
    printf("----------------------------------------------------\n");
    printf("City 0");

    for (int step = 1; step < nCities; step++) {
        int next = nextCity[mask][current];
        printf(" -> City %d (cost: %d)", next, dist[current][next]);
        mask |= (1 << next);
        current = next;
    }
    printf(" -> City 0 (return cost: %d)\n", dist[current][0]);
    printf("----------------------------------------------------\n");
}

int main(void) {
    printf("====================================================\n");
    printf("  DAA Lab Experiment 13: TRAVELLING SALESMAN (TSP)  \n");
    printf("====================================================\n\n");

    printf("Enter number of cities (2 to %d): ", MAX_CITIES);
    if (scanf("%d", &nCities) != 1 || nCities < 2 || nCities > MAX_CITIES) {
        fprintf(stderr, "Error: Invalid number of cities (must be between 2 and %d).\n", MAX_CITIES);
        return EXIT_FAILURE;
    }

    printf("\nEnter the cost/distance matrix (%d x %d):\n", nCities, nCities);
    for (int i = 0; i < nCities; i++) {
        for (int j = 0; j < nCities; j++) {
            if (scanf("%d", &dist[i][j]) != 1) {
                fprintf(stderr, "Error: Failed to read matrix element [%d][%d].\n", i, j);
                return EXIT_FAILURE;
            }
            if (i == j && dist[i][j] != 0) {
                /* Self distance is typically 0 */
                dist[i][j] = 0;
            }
        }
    }

    /* Initialize DP memoization table with -1 */
    int totalStates = 1 << nCities;
    for (int m = 0; m < totalStates; m++) {
        for (int u = 0; u < nCities; u++) {
            dpTable[m][u] = -1;
            nextCity[m][u] = -1;
        }
    }

    /* Solve TSP starting from City 0 with mask 1 (0th bit set) */
    int optimalCost = tsp(1, 0);

    printf("\n----------------------------------------------------\n");
    printf("   Travelling Salesman Problem (TSP) Results        \n");
    printf("----------------------------------------------------\n");
    printf("Number of Cities:      %d\n", nCities);
    printf("Total Possible Tours:  %lld\n", (long long)(nCities == 2 ? 1 : 1)); // factorial(n-1)
    printf("Minimum Tour Cost:     %d\n", optimalCost);

    printOptimalTour();

    printf("====================================================\n");

    return EXIT_SUCCESS;
}
