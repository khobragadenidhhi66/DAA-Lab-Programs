/**
 * ============================================================================
 * Program 04: Kruskal's Minimum Spanning Tree (MST) Algorithm
 * Algorithm Design Paradigm: Greedy Approach
 * ============================================================================
 * Description:
 *   Kruskal's algorithm finds a Minimum Spanning Tree for a connected, weighted
 *   graph. It operates by sorting all edges in increasing order of their weights
 *   and greedily adding the smallest edge to the MST, provided it does not
 *   create a cycle. A Disjoint Set Union (DSU) data structure with path
 *   compression and union by rank is used to detect cycles efficiently.
 *
 * Time Complexity:
 *   - Sorting Edges: O(E log E) or O(E log V)
 *   - DSU Operations: O(E * alpha(V)) where alpha is inverse Ackermann function
 *   - Overall Time Complexity: O(E log E)
 *
 * Space Complexity:
 *   - O(V + E) to store edges and DSU subsets.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

/* Structure to represent a weighted edge in the graph */
struct Edge {
    int src;
    int dest;
    int weight;
};

/* Structure to represent a subset for Union-Find */
struct Subset {
    int parent;
    int rank;
};

/**
 * Comparator function for qsort to sort edges by weight.
 */
int compareEdges(const void *a, const void *b) {
    const struct Edge *edgeA = (const struct Edge *)a;
    const struct Edge *edgeB = (const struct Edge *)b;
    return edgeA->weight - edgeB->weight;
}

/**
 * Find set of an element i using path compression technique.
 */
int findRoot(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = findRoot(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

/**
 * Performs union of two subsets x and y using union by rank.
 */
void unionSubsets(struct Subset subsets[], int x, int y) {
    int xroot = findRoot(subsets, x);
    int yroot = findRoot(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

/**
 * Main Kruskal's MST function.
 */
void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[MAX_VERTICES]; /* Stores the edges of the resultant MST */
    int e = 0;                        /* Count of edges in result[] */
    int i = 0;                        /* Initial index of sorted edges */

    /* Step 1: Sort all edges in non-decreasing order of their weight */
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    /* Allocate memory for creating V subsets */
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    if (subsets == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for subsets.\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize subsets with single elements */
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    /* Step 2: Iterate through sorted edges and pick V-1 edges without forming cycle */
    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];

        int x = findRoot(subsets, next_edge.src);
        int y = findRoot(subsets, next_edge.dest);

        /* If including this edge does not cause cycle, include it in result */
        if (x != y) {
            result[e++] = next_edge;
            unionSubsets(subsets, x, y);
        }
    }

    /* Step 3: Print result */
    printf("\n----------------------------------------------------\n");
    printf("  Kruskal's Minimum Spanning Tree (MST) Result      \n");
    printf("----------------------------------------------------\n");
    printf("%-10s %-12s %-10s\n", "Edge #", "Src -- Dest", "Weight");
    printf("----------------------------------------------------\n");

    int totalWeight = 0;
    for (int j = 0; j < e; j++) {
        printf("%-10d %2d  -- %-6d %-10d\n", j + 1, result[j].src, result[j].dest, result[j].weight);
        totalWeight += result[j].weight;
    }

    printf("----------------------------------------------------\n");
    printf("Total MST Weight: %d\n", totalWeight);
    printf("Total Edges:      %d (Expected for connected graph: %d)\n", e, V - 1);

    if (e < V - 1) {
        printf("\nWarning: The graph is not fully connected! Spanning forest formed.\n");
    }
    printf("====================================================\n");

    free(subsets);
}

int main(void) {
    int V, E;
    struct Edge edges[MAX_EDGES];

    printf("====================================================\n");
    printf("   DAA Lab Experiment 04: KRUSKAL'S MST ALGORITHM   \n");
    printf("====================================================\n\n");

    printf("Enter number of vertices (V >= 2): ");
    if (scanf("%d", &V) != 1 || V < 2 || V > MAX_VERTICES) {
        fprintf(stderr, "Error: Invalid number of vertices (must be between 2 and %d).\n", MAX_VERTICES);
        return EXIT_FAILURE;
    }

    printf("Enter number of edges (E >= 1): ");
    if (scanf("%d", &E) != 1 || E < 1 || E > MAX_EDGES) {
        fprintf(stderr, "Error: Invalid number of edges (must be between 1 and %d).\n", MAX_EDGES);
        return EXIT_FAILURE;
    }

    printf("\nEnter each edge in the format: <src> <dest> <weight>\n");
    printf("(0-indexed vertex indices, e.g., '0 1 10'):\n");
    for (int i = 0; i < E; i++) {
        if (scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight) != 3) {
            fprintf(stderr, "Error: Failed to read edge at index %d.\n", i);
            return EXIT_FAILURE;
        }

        if (edges[i].src < 0 || edges[i].src >= V || edges[i].dest < 0 || edges[i].dest >= V) {
            fprintf(stderr, "Error: Edge %d references invalid vertex out of range [0, %d].\n", i, V - 1);
            return EXIT_FAILURE;
        }
    }

    kruskalMST(edges, V, E);

    return EXIT_SUCCESS;
}
