/**
 * ============================================================================
 * Program 06: Dijkstra's Single Source Shortest Path Algorithm
 * Algorithm Design Paradigm: Greedy Approach
 * ============================================================================
 * Description:
 *   Dijkstra's algorithm solves the single-source shortest path problem for
 *   a directed or undirected graph with non-negative edge weights. It starts
 *   at a given source vertex and iteratively selects the unvisited vertex with
 *   the smallest provisional distance, updating the shortest paths to its
 *   adjacent vertices.
 *
 * Time Complexity:
 *   - Using Adjacency Matrix: O(V^2)
 *   - Using Min-Heap / Priority Queue with Adjacency List: O((V + E) log V)
 *
 * Space Complexity:
 *   - O(V) auxiliary space for distance, parent, and visited arrays.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 50
#define INF INT_MAX

/**
 * Finds the vertex with the minimum distance value from the set of
 * vertices not yet included in the shortest path tree.
 */
int minDistance(const int dist[], const bool sptSet[], int V) {
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

/**
 * Recursive utility function to print the shortest path from source to target.
 */
void printPath(const int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

/**
 * Implements Dijkstra's algorithm for a graph represented by an adjacency matrix.
 */
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src) {
    int dist[MAX_VERTICES];      /* dist[i] holds the shortest distance from src to i */
    bool sptSet[MAX_VERTICES];   /* sptSet[i] is true if vertex i is included in shortest path tree */
    int parent[MAX_VERTICES];    /* parent[i] stores the predecessor of vertex i in shortest path */

    /* Initialize all distances as INFINITE and sptSet[] as false */
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
        parent[i] = -1;
    }

    /* Distance of source vertex from itself is always 0 */
    dist[src] = 0;

    /* Find shortest path for all vertices */
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        /* If remaining vertices are unreachable, break */
        if (u == -1 || dist[u] == INF) {
            break;
        }

        sptSet[u] = true;

        /* Update dist[v] only if it is not in sptSet, there is an edge from
         * u to v, and total weight of path from src to v through u is smaller than current dist[v] */
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    /* Print the constructed distance array and paths */
    printf("\n----------------------------------------------------------------------\n");
    printf("   Dijkstra's Shortest Paths from Source Vertex: %d                    \n", src);
    printf("----------------------------------------------------------------------\n");
    printf("%-12s %-18s %-30s\n", "Destination", "Shortest Distance", "Shortest Path");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("%-12d %-18s %-30s\n", i, "INF (Unreachable)", "No Path");
        } else {
            printf("%-12d %-18d ", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
    printf("======================================================================\n");
}

int main(void) {
    int V, src;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("====================================================\n");
    printf("    DAA Lab Experiment 06: DIJKSTRA'S ALGORITHM     \n");
    printf("====================================================\n\n");

    printf("Enter number of vertices (2 to %d): ", MAX_VERTICES);
    if (scanf("%d", &V) != 1 || V < 2 || V > MAX_VERTICES) {
        fprintf(stderr, "Error: Invalid number of vertices.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the source vertex (0 to %d): ", V - 1);
    if (scanf("%d", &src) != 1 || src < 0 || src >= V) {
        fprintf(stderr, "Error: Source vertex must be between 0 and %d.\n", V - 1);
        return EXIT_FAILURE;
    }

    printf("\nEnter the adjacency matrix (%d x %d):\n", V, V);
    printf("(Enter 0 if there is no edge between vertices):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (scanf("%d", &graph[i][j]) != 1) {
                fprintf(stderr, "Error: Failed to read matrix element at [%d][%d].\n", i, j);
                return EXIT_FAILURE;
            }
            if (graph[i][j] < 0) {
                fprintf(stderr, "Error: Edge weights must be non-negative for Dijkstra's algorithm.\n");
                return EXIT_FAILURE;
            }
        }
    }

    dijkstra(graph, V, src);

    return EXIT_SUCCESS;
}
