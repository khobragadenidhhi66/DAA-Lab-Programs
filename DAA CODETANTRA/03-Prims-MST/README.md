# Experiment 03: Prim's Minimum Spanning Tree (MST) Algorithm

## Aim
To implement **Prim's Algorithm** in C using the **Greedy Method** to determine the Minimum Spanning Tree (MST) of a weighted, connected, and undirected graph, and calculate its total weight.

---

## Algorithm Description & Working

Prim's algorithm builds an MST by maintaining two sets of vertices:
1. Vertices already included in the MST.
2. Vertices not yet included.

### Steps:
1. Initialize the minimum weight keys of all vertices to $\infty$ (infinity) except the starting vertex (assigned 0).
2. While the MST does not include all vertices:
   - Pick a vertex $u$ with the minimum key value not currently in the MST set.
   - Include $u$ in the MST set.
   - For every adjacent vertex $v$ of $u$, if edge weight $weight(u, v) < key[v]$ and $v$ is not yet in the MST set, update $key[v] = weight(u, v)$ and set $parent[v] = u$.
3. When $V-1$ edges are chosen, the MST is complete.

### Pseudocode
```text
PRIM_MST(graph, V):
    Initialize key[] = {INF, INF, ...}, parent[] = {-1}, mstSet[] = {false}
    key[0] = 0
    parent[0] = -1

    for count = 0 to V - 2:
        u = minKey(key, mstSet, V)
        mstSet[u] = true
        for each v adjacent to u:
            if graph[u][v] != 0 and mstSet[v] == false and graph[u][v] < key[v]:
                parent[v] = u
                key[v] = graph[u][v]
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity (Adj Matrix)** | $\mathcal{O}(V^2)$ | Searching min-key takes $\mathcal{O}(V)$ for each of the $V$ vertices. |
| **Time Complexity (Min-Heap)** | $\mathcal{O}(E \log V)$ | Heap extract-min and decrease-key operations for sparse graphs. |
| **Space Complexity** | $\mathcal{O}(V)$ auxiliary | Arrays `key[]`, `parent[]`, and `mstSet[]` of size $V$. |

---

## Sample Input & Output

### Input
A graph with 5 vertices (0 through 4) represented by the following adjacency matrix:
```text
5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
```

### Output
```text
====================================================
     DAA Lab Experiment 03: PRIM'S MST ALGORITHM    
====================================================

Enter number of vertices (2 to 50): 5

Enter the adjacency matrix (5 x 5):
(Enter 0 if there is no edge between vertices):

----------------------------------------------------
   Minimum Spanning Tree (MST) Edges & Weights      
----------------------------------------------------
Edge       Src - Dest Weight    
----------------------------------------------------
1           0 - 1      2         
2           1 - 2      3         
3           0 - 3      6         
4           1 - 4      5         
----------------------------------------------------
Total Minimum Spanning Tree Weight: 16
Total Edges in MST:                4 (Expected: 4)
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 03-Prims-MST

# 2. Compile source code
gcc -Wall -Wextra -std=c99 prims_mst.c -o prims_mst

# 3. Run executable
# On Windows:
.\prims_mst.exe
# On Linux / macOS:
./prims_mst
```
