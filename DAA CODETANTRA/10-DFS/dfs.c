/**
 * ============================================================================
 * Program 10: Depth-First Search (DFS) Traversal
 * Algorithm Design Paradigm: Graph Traversal / Backtracking / Recursion
 * ============================================================================
 * Description:
 *   Depth-First Search (DFS) is an algorithm for traversing or searching tree
 *   or graph data structures. It starts at a designated source vertex and
 *   explores as far as possible along each branch before backtracking.
 *   This implementation uses recursive DFS, tracks discovery and finish
 *   timestamps (useful for topological sorting and cycle detection), and
 *   ensures all disconnected components of the graph are visited.
 *
 * Time Complexity:
 *   - Using Adjacency Matrix: O(V^2)
 *   - Using Adjacency List:   O(V + E)
 *
 * Space Complexity:
 *   - O(V) auxiliary space for recursion stack and visited array.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

static bool visited[MAX_VERTICES];
static int discoveryTime[MAX_VERTICES];
static int finishTime[MAX_VERTICES];
static int timer = 0;
static int traversalOrder[MAX_VERTICES];
static int orderCount = 0;

/**
 * Recursive helper function for DFS traversal from vertex u.
 */
void dfsVisit(int graph[MAX_VERTICES][MAX_VERTICES], int V, int u) {
    timer++;
    discoveryTime[u] = timer;
    visited[u] = true;
    traversalOrder[orderCount++] = u;

    for (int v = 0; v < V; v++) {
        if (graph[u][v] == 1 && !visited[v]) {
            dfsVisit(graph, V, v);
        }
    }

    timer++;
    finishTime[u] = timer;
}

/**
 * Main DFS function that traverses all connected components.
 */
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int V, int startVertex) {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        discoveryTime[i] = 0;
        finishTime[i] = 0;
    }
    timer = 0;
    orderCount = 0;

    /* First, explore starting vertex's component */
    dfsVisit(graph, V, startVertex);

    /* Explore any remaining unvisited components */
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsVisit(graph, V, i);
        }
    }

    /* Print traversal order */
    printf("\n----------------------------------------------------\n");
    printf("DFS Traversal Sequence starting from vertex %d:\n", startVertex);
    printf("----------------------------------------------------\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%d", traversalOrder[i]);
        if (i < orderCount - 1) {
            printf(" -> ");
        }
    }
    printf("\n----------------------------------------------------\n");

    /* Print discovery and finishing times */
    printf("%-10s %-16s %-16s\n", "Vertex", "Discovery Time (d)", "Finish Time (f)");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < V; i++) {
        printf("%-10d %-16d %-16d\n", i, discoveryTime[i], finishTime[i]);
    }
    printf("====================================================\n");
}

int main(void) {
    int V, startVertex;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("====================================================\n");
    printf("      DAA Lab Experiment 10: DEPTH-FIRST SEARCH     \n");
    printf("====================================================\n\n");

    printf("Enter number of vertices (1 to %d): ", MAX_VERTICES);
    if (scanf("%d", &V) != 1 || V <= 0 || V > MAX_VERTICES) {
        fprintf(stderr, "Error: Invalid number of vertices.\n");
        return EXIT_FAILURE;
    }

    printf("Enter starting vertex (0 to %d): ", V - 1);
    if (scanf("%d", &startVertex) != 1 || startVertex < 0 || startVertex >= V) {
        fprintf(stderr, "Error: Starting vertex out of range.\n");
        return EXIT_FAILURE;
    }

    printf("\nEnter the adjacency matrix (%d x %d):\n", V, V);
    printf("(1 if edge exists, 0 otherwise):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (scanf("%d", &graph[i][j]) != 1) {
                fprintf(stderr, "Error: Failed to read matrix element [%d][%d].\n", i, j);
                return EXIT_FAILURE;
            }
            if (graph[i][j] != 0 && graph[i][j] != 1) {
                fprintf(stderr, "Error: Matrix elements must be 0 or 1.\n");
                return EXIT_FAILURE;
            }
        }
    }

    dfs(graph, V, startVertex);

    return EXIT_SUCCESS;
}
