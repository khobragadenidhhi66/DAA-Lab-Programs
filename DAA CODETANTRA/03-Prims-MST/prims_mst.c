/**
 * ============================================================================
 * Program 03: Prim's Minimum Spanning Tree (MST) Algorithm
 * Algorithm Design Paradigm: Greedy Approach
 * ============================================================================
 * Description:
 *   Prim's algorithm finds a Minimum Spanning Tree for a connected, weighted,
 *   undirected graph. It starts with an arbitrary vertex and grows the MST
 *   one edge at a time by always picking the minimum weight edge that connects
 *   a vertex in the growing tree to a vertex outside the tree (Greedy choice).
 *
 * Time Complexity:
 *   - Using Adjacency Matrix: O(V^2)
 *   - Using Adjacency List + Min-Heap: O(E log V)
 *
 * Space Complexity:
 *   - O(V) auxiliary space for key, parent, and mstSet arrays.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 50
#define INF INT_MAX

/**
 * Finds the vertex with the minimum key value among the vertices
 * not yet included in the MST.
 *
 * @param key     Array of minimum weight edge values.
 * @param mstSet  Array tracking included vertices.
 * @param V       Total number of vertices.
 * @return        Index of vertex with minimum key.
 */
int minKey(const int key[], const bool mstSet[], int V) {
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

/**
 * Computes and prints the Minimum Spanning Tree using Prim's Algorithm.
 *
 * @param graph  Adjacency matrix of the graph.
 * @param V      Number of vertices.
 */
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int parent[MAX_VERTICES]; /* Stores constructed MST */
    int key[MAX_VERTICES];    /* Key values used to pick minimum edge in cut */
    bool mstSet[MAX_VERTICES]; /* Represents set of vertices included in MST */

    /* Initialize all keys as INFINITE and mstSet[] as false */
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }

    /* Start from vertex 0: First vertex always has key 0 */
    key[0] = 0;
    parent[0] = -1; /* First node is always root of MST */

    /* The MST will have V vertices */
    for (int count = 0; count < V - 1; count++) {
        /* Pick the minimum key vertex from the set of vertices not yet in MST */
        int u = minKey(key, mstSet, V);

        if (u == -1) {
            printf("\nWarning: The graph is disconnected! A full MST cannot be formed.\n");
            break;
        }

        /* Add the picked vertex to the MST set */
        mstSet[u] = true;

        /* Update key value and parent index of the adjacent vertices of u */
        for (int v = 0; v < V; v++) {
            /* graph[u][v] is non-zero only for adjacent vertices
             * mstSet[v] is false for vertices not yet included in MST
             * Update the key only if graph[u][v] is smaller than key[v] */
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    /* Print the constructed MST */
    printf("\n----------------------------------------------------\n");
    printf("   Minimum Spanning Tree (MST) Edges & Weights      \n");
    printf("----------------------------------------------------\n");
    printf("%-10s %-10s %-10s\n", "Edge", "Src - Dest", "Weight");
    printf("----------------------------------------------------\n");

    int totalWeight = 0;
    int edgeCount = 0;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            printf("%-10d %2d - %-6d %-10d\n", edgeCount + 1, parent[i], i, graph[parent[i]][i]);
            totalWeight += graph[parent[i]][i];
            edgeCount++;
        }
    }

    printf("----------------------------------------------------\n");
    printf("Total Minimum Spanning Tree Weight: %d\n", totalWeight);
    printf("Total Edges in MST:                %d (Expected: %d)\n", edgeCount, V - 1);
    printf("====================================================\n");
}

int main(void) {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("====================================================\n");
    printf("     DAA Lab Experiment 03: PRIM'S MST ALGORITHM    \n");
    printf("====================================================\n\n");

    printf("Enter number of vertices (2 to %d): ", MAX_VERTICES);
    if (scanf("%d", &V) != 1 || V < 2 || V > MAX_VERTICES) {
        fprintf(stderr, "Error: Invalid number of vertices (must be between 2 and %d).\n", MAX_VERTICES);
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
                fprintf(stderr, "Error: Edge weights must be non-negative.\n");
                return EXIT_FAILURE;
            }
        }
    }

    primMST(graph, V);

    return EXIT_SUCCESS;
}
