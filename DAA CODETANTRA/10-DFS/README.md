# Experiment 10: Depth-First Search (DFS) Traversal

## Aim
To implement the **Depth-First Search (DFS)** graph traversal algorithm in C using **Recursion / Backtracking**, record vertex discovery and finishing timestamps, and systematically explore all reachable components.

---

## Algorithm Description & Working

DFS explores as deeply as possible along each branch before backtracking:
1. **Initialize:**
   - Mark all vertices as unvisited.
   - Initialize a global timer to 0.
2. **Recursive Exploration (`dfsVisit`):**
   - Increment timer; set discovery time for the current vertex $u$.
   - Mark vertex $u$ as visited.
   - For each adjacent unvisited vertex $v$ of $u$:
     - Recursively call `dfsVisit(v)`.
   - Increment timer; set finish time for vertex $u$ once all its adjacent vertices are fully explored.
3. **Full Graph Exploration:**
   - After exploring the initial connected component, check all vertices in the graph. If any vertex remains unvisited, initiate a new DFS tree rooted at that vertex to handle disconnected components.

### Pseudocode
```text
DFS(graph, V, startVertex):
    visited = [false] * V
    time = 0

    DFS_VISIT(startVertex)
    for u = 0 to V - 1:
        if not visited[u]:
            DFS_VISIT(u)

DFS_VISIT(u):
    time = time + 1
    d[u] = time
    visited[u] = true
    print u

    for each neighbor v of u:
        if graph[u][v] == 1 and not visited[v]:
            DFS_VISIT(v)

    time = time + 1
    f[u] = time
```

---

## Complexity Analysis

| Metric | Adjacency Matrix | Adjacency List |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(V^2)$ | $\mathcal{O}(V + E)$ |
| **Space Complexity** | $\mathcal{O}(V)$ auxiliary (Recursion Stack) | $\mathcal{O}(V)$ auxiliary |
| **Applications** | Cycle detection, topological sorting, connected components, biconnectivity |

---

## Sample Input & Output

### Input
A 5-vertex directed graph starting at vertex 0:
```text
5
0
0 1 1 0 0
0 0 0 1 0
0 0 0 1 1
0 0 0 0 0
0 0 0 0 0
```

### Output
```text
====================================================
      DAA Lab Experiment 10: DEPTH-FIRST SEARCH     
====================================================

Enter number of vertices (1 to 50): 5
Enter starting vertex (0 to 4): 0

Enter the adjacency matrix (5 x 5):
(1 if edge exists, 0 otherwise):

----------------------------------------------------
DFS Traversal Sequence starting from vertex 0:
----------------------------------------------------
0 -> 1 -> 3 -> 2 -> 4
----------------------------------------------------
Vertex     Discovery Time (d) Finish Time (f) 
----------------------------------------------------
0          1                10              
1          2                5               
2          6                9               
3          3                4               
4          7                8               
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 10-DFS

# 2. Compile source code
gcc -Wall -Wextra -std=c99 dfs.c -o dfs

# 3. Run executable
# On Windows:
.\dfs.exe
# On Linux / macOS:
./dfs
```
