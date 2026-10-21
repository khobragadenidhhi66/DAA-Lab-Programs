/**
 * ============================================================================
 * Program 09: Breadth-First Search (BFS) Traversal
 * Algorithm Design Paradigm: Graph Traversal / Queue ADT
 * ============================================================================
 * Description:
 *   Breadth-First Search (BFS) is a fundamental graph traversal algorithm.
 *   Starting from a given source vertex, BFS explores all its neighboring
 *   vertices at the present depth level before moving on to vertices at the
 *   next depth level. It utilizes a FIFO (First-In, First-Out) queue and
 *   computes the shortest distance (in terms of number of edges) from the
 *   source to all reachable vertices.
 *
 * Time Complexity:
 *   - Using Adjacency Matrix: O(V^2)
 *   - Using Adjacency List:   O(V + E)
 *
 * Space Complexity:
 *   - O(V) auxiliary space for queue, visited array, and distance array.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

/* Queue Data Structure */
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct Queue *q) {
    return (q->front == -1);
}

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        fprintf(stderr, "Error: Queue overflow.\n");
        exit(EXIT_FAILURE);
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Error: Queue underflow.\n");
        exit(EXIT_FAILURE);
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

/**
 * Performs BFS traversal starting from startVertex.
 */
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int V, int startVertex) {
    bool visited[MAX_VERTICES];
    int distance[MAX_VERTICES];
    int traversalOrder[MAX_VERTICES];
    int orderCount = 0;

    struct Queue q;
    initQueue(&q);

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        distance[i] = -1; /* -1 represents unreachable */
    }

    /* Start from startVertex */
    visited[startVertex] = true;
    distance[startVertex] = 0;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        traversalOrder[orderCount++] = current;

        for (int neighbor = 0; neighbor < V; neighbor++) {
            if (graph[current][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                enqueue(&q, neighbor);
            }
        }
    }

    /* Display Traversal Order */
    printf("\n----------------------------------------------------\n");
    printf("BFS Traversal Sequence starting from vertex %d:\n", startVertex);
    printf("----------------------------------------------------\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%d", traversalOrder[i]);
        if (i < orderCount - 1) {
            printf(" -> ");
        }
    }
    printf("\n----------------------------------------------------\n");

    /* Display Shortest Edge Hops / Level */
    printf("%-10s %-15s %-12s\n", "Vertex", "Visited?", "Level / Hop Distance");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < V; i++) {
        if (visited[i]) {
            printf("%-10d %-15s %-12d\n", i, "Yes", distance[i]);
        } else {
            printf("%-10d %-15s %-12s\n", i, "No (Unreachable)", "Unreachable");
        }
    }
    printf("====================================================\n");
}

int main(void) {
    int V, startVertex;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("====================================================\n");
    printf("     DAA Lab Experiment 09: BREADTH-FIRST SEARCH    \n");
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
                fprintf(stderr, "Error: Adjacency matrix elements must be 0 or 1.\n");
                return EXIT_FAILURE;
            }
        }
    }

    bfs(graph, V, startVertex);

    return EXIT_SUCCESS;
}
