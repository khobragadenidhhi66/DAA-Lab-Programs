# Experiment 09: Breadth-First Search (BFS) Traversal

## Aim
To implement the **Breadth-First Search (BFS)** graph traversal algorithm in C using a **FIFO Queue**, visit all reachable vertices level by level from a designated start vertex, and compute the shortest hop distance.

---

## Algorithm Description & Working

BFS explores graph vertices radially outward from a root/source vertex:
1. **Initialize:**
   - Mark all vertices as unvisited and set distance to $-1$.
   - Initialize an empty queue.
   - Enqueue the start vertex, mark it as visited, and set its distance to $0$.
2. **Level-by-Level Exploration:**
   - While the queue is not empty:
     - Dequeue front vertex $u$.
     - For each adjacent unvisited vertex $v$ of $u$:
       - Mark $v$ as visited.
       - Set $distance[v] = distance[u] + 1$.
       - Enqueue $v$.
3. **Termination:** When the queue becomes empty, all reachable vertices at all levels have been processed.

### Pseudocode
```text
BFS(graph, startVertex, V):
    visited = [false] * V
    distance = [-1] * V
    queue = EMPTY_QUEUE()

    visited[startVertex] = true
    distance[startVertex] = 0
    ENQUEUE(queue, startVertex)

    while not IS_EMPTY(queue):
        u = DEQUEUE(queue)
        print u
        for each neighbor v of u:
            if graph[u][v] == 1 and not visited[v]:
                visited[v] = true
                distance[v] = distance[u] + 1
                ENQUEUE(queue, v)
```

---

## Complexity Analysis

| Metric | Adjacency Matrix | Adjacency List |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(V^2)$ | $\mathcal{O}(V + E)$ |
| **Space Complexity** | $\mathcal{O}(V)$ auxiliary | $\mathcal{O}(V)$ auxiliary |
| **Data Structure Used** | FIFO Queue | FIFO Queue |

---

## Sample Input & Output

### Input
A 5-vertex directed/undirected graph with start vertex 0:
```text
5
0
0 1 1 0 0
1 0 0 1 1
1 0 0 0 1
0 1 0 0 0
0 1 1 0 0
```

### Output
```text
====================================================
     DAA Lab Experiment 09: BREADTH-FIRST SEARCH    
====================================================

Enter number of vertices (1 to 50): 5
Enter starting vertex (0 to 4): 0

Enter the adjacency matrix (5 x 5):
(1 if edge exists, 0 otherwise):

----------------------------------------------------
BFS Traversal Sequence starting from vertex 0:
----------------------------------------------------
0 -> 1 -> 2 -> 3 -> 4
----------------------------------------------------
Vertex     Visited?        Level / Hop Distance
----------------------------------------------------
0          Yes             0           
1          Yes             1           
2          Yes             1           
3          Yes             2           
4          Yes             2           
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 09-BFS

# 2. Compile source code
gcc -Wall -Wextra -std=c99 bfs.c -o bfs

# 3. Run executable
# On Windows:
.\bfs.exe
# On Linux / macOS:
./bfs
```
