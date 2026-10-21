# Experiment 13: Travelling Salesman Problem (TSP)

## Aim
To solve the **Travelling Salesman Problem (TSP)** in C using the **Held-Karp Dynamic Programming with Bitmasking** algorithm, determine the minimum-cost Hamiltonian cycle, and reconstruct the exact sequence of cities visited in the optimal tour.

---

## Algorithm Description & Working

The Travelling Salesman Problem asks: *Given a list of cities and the distances between each pair, what is the shortest possible route that visits each city exactly once and returns to the origin city?*

### Held-Karp Dynamic Programming Formulation:
1. **Subproblem State:**
   $C(S, i)$ is defined as the minimum cost of traveling from city 0, visiting all cities in subset $S$ exactly once, and ending at city $i \in S$.
2. **Bitmask Representation:**
   The subset $S$ is compactly represented as an integer bitmask where the $k$-th bit is $1$ if city $k \in S$.
3. **Recurrence Relation:**
   $$C(S, i) = \min_{j \in S, j \ne i} \big( C(S \setminus \{i\}, j) + dist[j][i] \big)$$
   For our top-down implementation:
   $$TSP(mask, u) = \min_{v \notin mask} \big( dist[u][v] + TSP(mask \cup \{v\}, v) \big)$$
4. **Base Case:**
   When all $n$ cities are visited ($mask = 2^n - 1$), the return cost to starting city 0 is $dist[u][0]$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Feasible $n$ |
| :--- | :--- | :--- | :--- |
| **Brute Force Permutations** | $\mathcal{O}((n-1)!)$ | $\mathcal{O}(n)$ | $n \le 10$ |
| **Held-Karp Dynamic Programming** | $\mathcal{O}(n^2 \cdot 2^n)$ | $\mathcal{O}(n \cdot 2^n)$ | $n \le 20$ |
| **Branch and Bound** | $\mathcal{O}(2^n)$ worst-case | $\mathcal{O}(n^2)$ | $n \le 25$ |

The Held-Karp algorithm drastically reduces complexity from $\mathcal{O}(n!)$ to $\mathcal{O}(n^2 2^n)$. For $n=16$, $15! \approx 1.3 \times 10^{12}$ operations, while $16^2 \cdot 2^{16} \approx 1.6 \times 10^7$ operations (a $100,000\times$ speedup).

---

## Sample Input & Output

### Input
A 4-city cost matrix:
```text
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
```

### Output
```text
====================================================
  DAA Lab Experiment 13: TRAVELLING SALESMAN (TSP)  
====================================================

Enter number of cities (2 to 16): 4

Enter the cost/distance matrix (4 x 4):

----------------------------------------------------
   Travelling Salesman Problem (TSP) Results        
----------------------------------------------------
Number of Cities:      4
Total Possible Tours:  1
Minimum Tour Cost:     80

----------------------------------------------------
Optimal TSP Tour Route:
----------------------------------------------------
City 0 -> City 1 (cost: 10) -> City 3 (cost: 25) -> City 2 (cost: 30) -> City 0 (return cost: 15)
----------------------------------------------------
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 13-Travelling-Salesman

# 2. Compile source code
gcc -Wall -Wextra -std=c99 travelling_salesman.c -o travelling_salesman

# 3. Run executable
# On Windows:
.\travelling_salesman.exe
# On Linux / macOS:
./travelling_salesman
```
