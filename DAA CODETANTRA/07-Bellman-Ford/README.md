# Experiment 07: Bellman-Ford Shortest Path Algorithm

## Aim
To implement the **Bellman-Ford Algorithm** in C using the **Dynamic Programming** paradigm to compute the shortest paths from a single source vertex to all other vertices in a directed weighted graph, and to detect the presence of **negative-weight cycles**.

---

## Algorithm Description & Working

Bellman-Ford works on the principle of edge relaxation. If a graph has $|V|$ vertices, the shortest simple path between any two vertices can contain at most $|V|-1$ edges.

### Steps:
1. **Initialize:** Set distance to source $dist[src] = 0$ and all other distances to $\infty$.
2. **Relax Edges:** Repeat $|V| - 1$ times:
   - For every directed edge $(u, v)$ with weight $w$:
     $$\text{if } dist[u] \ne \infty \text{ and } dist[u] + w < dist[v]:$$
     $$dist[v] = dist[u] + w, \quad parent[v] = u$$
3. **Negative Cycle Check:**
   - Iterate over all edges one additional time.
   - If $dist[u] + w < dist[v]$ is still possible, the graph contains a **negative-weight cycle** reachable from the source. In this case, shortest paths are undefined.

### Pseudocode
```text
BELLMAN_FORD(Edges, V, E, src):
    dist = [INF] * V
    dist[src] = 0

    for i = 1 to V - 1:
        for each edge (u, v, w) in Edges:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                parent[v] = u

    for each edge (u, v, w) in Edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            report "Negative cycle detected"
            return
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(V \cdot E)$ | Relaxes all $E$ edges across $V-1$ iterations. |
| **Best-Case Time** | $\mathcal{O}(E)$ | When all shortest paths stabilize in the first iteration (with early-break flag). |
| **Worst-Case Time** | $\mathcal{O}(V^3)$ | For complete dense graphs where $E = \mathcal{O}(V^2)$. |
| **Space Complexity** | $\mathcal{O}(V)$ auxiliary | Arrays `dist[]` and `parent[]` of size $V$. |

---

## Sample Input & Output

### Input
A 5-vertex graph with 8 edges and negative weights, source 0:
```text
5
8
0
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
```

### Output
```text
====================================================
     DAA Lab Experiment 07: BELLMAN-FORD ALGORITHM   
====================================================

Enter number of vertices (V >= 2): 5
Enter number of edges (E >= 1): 8
Enter the source vertex (0 to 4): 0

Enter each directed edge as: <src> <dest> <weight>
(Supports negative weights; vertices are 0-indexed):

----------------------------------------------------------------------
   Bellman-Ford Algorithm Results from Source Vertex: 0              
----------------------------------------------------------------------
Destination  Shortest Distance  Shortest Path                 
----------------------------------------------------------------------
0            0                  0
1            -1                 0 -> 1
2            2                  0 -> 1 -> 2
3            -2                 0 -> 1 -> 4 -> 3
4            1                  0 -> 1 -> 4
======================================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 07-Bellman-Ford

# 2. Compile source code
gcc -Wall -Wextra -std=c99 bellman_ford.c -o bellman_ford

# 3. Run executable
# On Windows:
.\bellman_ford.exe
# On Linux / macOS:
./bellman_ford
```
