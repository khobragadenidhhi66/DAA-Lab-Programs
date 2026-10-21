# Experiment 11: 0/1 Knapsack Problem

## Aim
To solve the **0/1 Knapsack Problem** in C using the **Dynamic Programming** technique, compute the maximum profit attainable within a specified weight capacity, and identify the exact subset of items chosen.

---

## Algorithm Description & Working

Given $n$ items, with weights $w_1, \dots, w_n$ and profits $p_1, \dots, p_n$, and a knapsack of capacity $W$:
1. **Optimal Substructure:**
   For item $i$ and capacity $w$:
   - If item $i$ is not included: optimal profit is $DP[i-1][w]$.
   - If item $i$ is included (valid when $w_i \le w$): optimal profit is $p_i + DP[i-1][w - w_i]$.
2. **Recurrence Relation:**
   $$DP[i][w] = \begin{cases} 0 & \text{if } i = 0 \text{ or } w = 0 \\ DP[i-1][w] & \text{if } w_i > w \\ \max\big(DP[i-1][w], \; p_i + DP[i-1][w - w_i]\big) & \text{if } w_i \le w \end{cases}$$
3. **Item Backtracking:**
   Start at cell $DP[n][W]$. If $DP[i][w] \ne DP[i-1][w]$, item $i$ was included; decrement $w$ by $w_i$ and repeat.

### Pseudocode
```text
KNAPSACK_01(n, W, weights, profits):
    Initialize table DP[n + 1][W + 1] to 0

    for i = 1 to n:
        for w = 0 to W:
            if weights[i - 1] <= w:
                DP[i][w] = max(profits[i - 1] + DP[i - 1][w - weights[i - 1]], DP[i - 1][w])
            else:
                DP[i][w] = DP[i - 1][w]

    return DP[n][W]
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(n \cdot W)$ | Pseudo-polynomial time: $(n+1) \times (W+1)$ state transitions. |
| **Space Complexity** | $\mathcal{O}(n \cdot W)$ | DP table storage for full backtracing. |
| **Optimality** | Guaranteed optimal | Unlike Greedy Fractional Knapsack, 0/1 requires DP. |

---

## Sample Input & Output

### Input
4 items with capacity 8:
```text
4
8
2 3 4 5
1 2 5 6
```

### Output
```text
====================================================
      DAA Lab Experiment 11: 0/1 KNAPSACK (DP)      
====================================================

Enter number of items (1 to 100): 4
Enter maximum knapsack capacity W (1 to 1000): 8

Enter weights of 4 items:
Enter profits/values of 4 items:

Input Items:
Item #   Weight     Profit    
1        2          1         
2        3          2         
3        4          5         
4        5          6         

----------------------------------------------------
Dynamic Programming Table (DP[i][w]):
----------------------------------------------------
         0   1   2   3   4   5   6   7   8
i= 0:    0   0   0   0   0   0   0   0   0
i= 1:    0   0   1   1   1   1   1   1   1
i= 2:    0   0   1   2   2   3   3   3   3
i= 3:    0   0   1   2   5   5   6   7   7
i= 4:    0   0   1   2   5   6   6   7   8

----------------------------------------------------
   0/1 Knapsack Optimal Solution Summary            
----------------------------------------------------
Knapsack Capacity:     8
Maximum Total Profit:  8
Total Weight Utilized: 8 / 8
Number of Items Taken: 2
----------------------------------------------------
Item #     Weight     Profit    
----------------------------------------------------
2          3          2         
4          5          6         
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 11-Knapsack

# 2. Compile source code
gcc -Wall -Wextra -std=c99 knapsack.c -o knapsack

# 3. Run executable
# On Windows:
.\knapsack.exe
# On Linux / macOS:
./knapsack
```
