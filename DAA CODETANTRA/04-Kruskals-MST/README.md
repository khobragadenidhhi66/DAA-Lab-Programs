# Experiment 04: Kruskal's Minimum Spanning Tree (MST) Algorithm

## Aim
To implement **Kruskal's Algorithm** in C using the **Greedy Method** along with a **Disjoint Set Union (Union-Find)** data structure to find the Minimum Spanning Tree (MST) of a weighted undirected graph.

---

## Algorithm Description & Working

Kruskal's algorithm finds an MST for a connected weighted graph by treating each vertex as an independent tree and repeatedly joining trees:
1. **Edge Sorting:** Sort all edges of the graph in non-decreasing order of their weights.
2. **Cycle Checking via Union-Find:**
   - Iterate through the sorted edges.
   - For each edge $(u, v)$, find the subsets containing $u$ and $v$ using the `findRoot()` function with path compression.
   - If $u$ and $v$ belong to different subsets, adding this edge does not form a cycle. Add $(u, v)$ to the MST and combine the subsets using `unionSubsets()` with union by rank.
   - If they belong to the same subset, discard the edge to prevent cycle formation.
3. **Termination:** Continue until $V-1$ edges have been included in the MST or all edges are evaluated.

### Pseudocode
```text
KRUSKAL_MST(Graph G):
    MST = empty set
    for each vertex v in G.V:
        MAKE_SET(v)
    sort edges of G.E by non-decreasing weight

    for each edge (u, v) in G.E:
        if FIND_SET(u) != FIND_SET(v):
            MST = MST U {(u, v)}
            UNION(u, v)
            if len(MST) == V - 1:
                break
    return MST
```

---

## Complexity Analysis

| Operation | Complexity | Description |
| :--- | :--- | :--- |
| **Edge Sorting** | $\mathcal{O}(E \log E)$ | Sorting $E$ edges via QuickSort/qsort. |
| **Union-Find Operations** | $\mathcal{O}(E \cdot \alpha(V))$ | $\alpha$ is the Inverse Ackermann function ($\alpha(V) \le 4$). |
| **Overall Time Complexity** | $\mathcal{O}(E \log E)$ or $\mathcal{O}(E \log V)$ | Dominant factor is edge sorting. |
| **Space Complexity** | $\mathcal{O}(V + E)$ auxiliary | Storage for edges and subset parent/rank arrays. |

---

## Sample Input & Output

### Input
A graph with 4 vertices (0, 1, 2, 3) and 5 edges:
```text
4
5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
```

### Output
```text
====================================================
   DAA Lab Experiment 04: KRUSKAL'S MST ALGORITHM   
====================================================

Enter number of vertices (V >= 2): 4
Enter number of edges (E >= 1): 5

Enter each edge in the format: <src> <dest> <weight>
(0-indexed vertex indices, e.g., '0 1 10'):

----------------------------------------------------
  Kruskal's Minimum Spanning Tree (MST) Result      
----------------------------------------------------
Edge #     Src -- Dest  Weight    
----------------------------------------------------
1           2  -- 3      4         
2           0  -- 3      5         
3           0  -- 1      10        
----------------------------------------------------
Total MST Weight: 19
Total Edges:      3 (Expected for connected graph: 3)
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 04-Kruskals-MST

# 2. Compile source code
gcc -Wall -Wextra -std=c99 kruskals_mst.c -o kruskals_mst

# 3. Run executable
# On Windows:
.\kruskals_mst.exe
# On Linux / macOS:
./kruskals_mst
```
