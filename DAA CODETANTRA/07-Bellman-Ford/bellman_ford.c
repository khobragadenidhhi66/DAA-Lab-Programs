/**
 * ============================================================================
 * Program 07: Bellman-Ford Algorithm
 * Algorithm Design Paradigm: Dynamic Programming
 * ============================================================================
 * Description:
 *   The Bellman-Ford algorithm computes shortest paths from a single source
 *   vertex to all other vertices in a weighted digraph. Unlike Dijkstra's
 *   algorithm, Bellman-Ford can handle graphs with negative edge weights and
 *   is capable of detecting negative-weight cycles. It relies on the principle
 *   of relaxation, iterating |V| - 1 times over all edges.
 *
 * Time Complexity:
 *   - O(V * E) for all cases.
 *
 * Space Complexity:
 *   - O(V) auxiliary space for distance and parent arrays.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000
#define INF 1000000000 /* Use safe large number to prevent integer overflow */

/* Structure to represent a directed weighted edge */
struct Edge {
    int src;
    int dest;
    int weight;
};

/**
 * Recursive utility function to print path from source to target.
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
 * Implements the Bellman-Ford algorithm.
 *
 * @param edges  Array of edges.
 * @param V      Number of vertices.
 * @param E      Number of edges.
 * @param src    Source vertex.
 */
void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];

    /* Step 1: Initialize distances from src to all other vertices as INF */
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    /* Step 2: Relax all edges |V| - 1 times */
    for (int i = 1; i <= V - 1; i++) {
        bool updated = false;
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                updated = true;
            }
        }
        /* Early exit optimization if no relaxation occurred */
        if (!updated) {
            break;
        }
    }

    /* Step 3: Check for negative-weight cycles */
    bool hasNegativeCycle = false;
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    /* Step 4: Display results */
    printf("\n----------------------------------------------------------------------\n");
    printf("   Bellman-Ford Algorithm Results from Source Vertex: %d              \n", src);
    printf("----------------------------------------------------------------------\n");

    if (hasNegativeCycle) {
        printf("\n[!] CRITICAL WARNING: Negative-weight cycle detected in the graph!\n");
        printf("    Shortest paths cannot be determined because distances can decrease infinitely.\n");
    } else {
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
    }
    printf("======================================================================\n");
}

int main(void) {
    int V, E, src;
    struct Edge edges[MAX_EDGES];

    printf("====================================================\n");
    printf("     DAA Lab Experiment 07: BELLMAN-FORD ALGORITHM   \n");
    printf("====================================================\n\n");

    printf("Enter number of vertices (V >= 2): ");
    if (scanf("%d", &V) != 1 || V < 2 || V > MAX_VERTICES) {
        fprintf(stderr, "Error: Invalid number of vertices.\n");
        return EXIT_FAILURE;
    }

    printf("Enter number of edges (E >= 1): ");
    if (scanf("%d", &E) != 1 || E < 1 || E > MAX_EDGES) {
        fprintf(stderr, "Error: Invalid number of edges.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the source vertex (0 to %d): ", V - 1);
    if (scanf("%d", &src) != 1 || src < 0 || src >= V) {
        fprintf(stderr, "Error: Invalid source vertex.\n");
        return EXIT_FAILURE;
    }

    printf("\nEnter each directed edge as: <src> <dest> <weight>\n");
    printf("(Supports negative weights; vertices are 0-indexed):\n");
    for (int i = 0; i < E; i++) {
        if (scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight) != 3) {
            fprintf(stderr, "Error: Failed to read edge %d.\n", i);
            return EXIT_FAILURE;
        }

        if (edges[i].src < 0 || edges[i].src >= V || edges[i].dest < 0 || edges[i].dest >= V) {
            fprintf(stderr, "Error: Edge %d has invalid endpoint vertex.\n", i);
            return EXIT_FAILURE;
        }
    }

    bellmanFord(edges, V, E, src);

    return EXIT_SUCCESS;
}
