# Experiment 05: Sum of Subsets Problem

## Aim
To solve the **Sum of Subsets** problem in C using the **Backtracking** technique, systematically exploring a state space tree and printing all unique subsets of elements whose sum equals a specified target.

---

## Algorithm Description & Working

The Sum of Subsets problem is modeled as finding all binary tuples $(x_1, x_2, \dots, x_n)$ where $x_i \in \{0, 1\}$ such that:
$$\sum_{i=1}^{n} w_i \cdot x_i = M$$

### Steps:
1. **Pre-sorting:** Sort the weights $w_1 \le w_2 \le \dots \le w_n$ in ascending order to enable effective bounding and pruning.
2. **State Space Tree Exploration:** Each node at level $k$ represents a decision for element $w_k$:
   - Left branch ($x_k = 1$): Include element $w_k$.
   - Right branch ($x_k = 0$): Exclude element $w_k$.
3. **Bounding Functions (Pruning):**
   - **Target Reached:** If $currentSum + w_k = M$, a solution is recorded.
   - **Left Child Validity:** Explore left branch only if $currentSum + w_k + w_{k+1} \le M$.
   - **Right Child Validity:** Explore right branch only if $currentSum + remainingSum - w_k \ge M$ and $currentSum + w_{k+1} \le M$.

### Pseudocode
```text
SUM_OF_SUBSETS(s, k, r):
    x[k] = 1
    if s + w[k] == M:
        PRINT_SUBSET(x)
    else if s + w[k] + w[k+1] <= M:
        SUM_OF_SUBSETS(s + w[k], k + 1, r - w[k])

    x[k] = 0
    if (s + r - w[k] >= M) and (s + w[k+1] <= M):
        SUM_OF_SUBSETS(s, k + 1, r - w[k])
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Worst-Case Time** | $\mathcal{O}(2^n)$ | In the absence of early pruning, a complete binary tree of height $n$ has $2^{n+1}-1$ nodes. |
| **Average-Case Time** | Significantly lower than $\mathcal{O}(2^n)$ | Bounding functions prune large subtrees early. |
| **Space Complexity** | $\mathcal{O}(n)$ | Depth of recursion stack and size of the boolean decision array $x[]$. |

---

## Sample Input & Output

### Input
```text
6
5 10 12 13 15 18
30
```

### Output
```text
====================================================
    DAA Lab Experiment 05: SUM OF SUBSETS (BACKTRACKING) 
====================================================

Enter number of elements (1 to 100): 6
Enter 6 positive integers:
Enter the target sum (M): 30

----------------------------------------------------
Sorted Input Elements: 5 10 12 13 15 18 
Target Sum (M):         30
Total Sum of Elements:  73
----------------------------------------------------
Finding subsets that sum to 30...

 Solution  1: { 5, 10, 15 } -> Sum = 30
 Solution  2: { 5, 12, 13 } -> Sum = 30
 Solution  3: { 12, 18 } -> Sum = 30

Total distinct subsets found: 3
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 05-Sum-of-Subsets

# 2. Compile source code
gcc -Wall -Wextra -std=c99 sum_of_subsets.c -o sum_of_subsets

# 3. Run executable
# On Windows:
.\sum_of_subsets.exe
# On Linux / macOS:
./sum_of_subsets
```
