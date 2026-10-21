# Experiment 06: Dijkstra's Shortest Path Algorithm

## Aim
To implement **Dijkstra's Algorithm** in C using the **Greedy Method** to find the shortest path and minimum distances from a given source vertex to all other vertices in a weighted graph with non-negative edge weights.

---

## Algorithm Description & Working

Dijkstra's algorithm computes the shortest path tree rooted at a designated source vertex:
1. **Initialization:**
   - Set $dist[v] = \infty$ for all vertices except the source vertex ($dist[src] = 0$).
   - Maintain a set $sptSet$ of vertices whose shortest distance from the source is finalized.
   - Maintain an array $parent[]$ to trace back the exact vertices forming each shortest path.
2. **Greedy Selection:**
   - In each iteration, select an unvisited vertex $u$ with minimum $dist[u]$.
   - Mark $u$ as visited ($sptSet[u] = true$).
3. **Edge Relaxation:**
   - For every adjacent vertex $v$ of $u$, check if $dist[u] + weight(u, v) < dist[v]$.
   - If true, update $dist[v] = dist[u] + weight(u, v)$ and set $parent[v] = u$.
4. **Completion:** The loop runs $V-1$ times until all reachable vertices are processed.

### Pseudocode
```text
DIJKSTRA(graph, src, V):
    dist = [INF, INF, ...]
    dist[src] = 0
    sptSet = [false, false, ...]

    for count = 0 to V - 2:
        u = minDistance(dist, sptSet, V)
        sptSet[u] = true
        for each v adjacent to u:
            if not sptSet[v] and graph[u][v] != 0 and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]
                parent[v] = u
```

---

## Complexity Analysis

| Implementation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Adjacency Matrix** (Used here) | $\mathcal{O}(V^2)$ | $\mathcal{O}(V)$ auxiliary |
| **Binary Min-Heap + Adj List** | $\mathcal{O}((V + E) \log V)$ | $\mathcal{O}(V + E)$ |
| **Fibonacci Heap + Adj List** | $\mathcal{O}(E + V \log V)$ | $\mathcal{O}(V + E)$ |

> **Note:** Dijkstra's algorithm requires all edge weights to be non-negative ($w \ge 0$). For graphs with negative edge weights, Bellman-Ford's algorithm is required.

---

## Sample Input & Output

### Input
A 5-vertex graph with source vertex 0:
```text
5
0
0 4 2 0 0
0 0 1 5 0
0 0 0 8 10
0 0 0 0 2
0 0 0 0 0
```

### Output
```text
====================================================
    DAA Lab Experiment 06: DIJKSTRA'S ALGORITHM     
====================================================

Enter number of vertices (2 to 50): 5
Enter the source vertex (0 to 4): 0

Enter the adjacency matrix (5 x 5):
(Enter 0 if there is no edge between vertices):

----------------------------------------------------------------------
   Dijkstra's Shortest Paths from Source Vertex: 0                    
----------------------------------------------------------------------
Destination  Shortest Distance  Shortest Path                 
----------------------------------------------------------------------
0            0                  0
1            4                  0 -> 1
2            2                  0 -> 2
3            9                  0 -> 1 -> 3
4            11                 0 -> 1 -> 3 -> 4
======================================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 06-Dijkstras-Algorithm

# 2. Compile source code
gcc -Wall -Wextra -std=c99 dijkstras_algorithm.c -o dijkstras_algorithm

# 3. Run executable
# On Windows:
.\dijkstras_algorithm.exe
# On Linux / macOS:
./dijkstras_algorithm
```
