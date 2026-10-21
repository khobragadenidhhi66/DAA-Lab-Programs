# Experiment 12: Longest Common Subsequence (LCS)

## Aim
To implement the **Longest Common Subsequence (LCS)** problem in C using the **Dynamic Programming** paradigm, construct the memoization scoring table, and reconstruct the longest common subsequence string between two given sequences.

---

## Algorithm Description & Working

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

### Optimal Substructure:
Let $X = \langle x_1, x_2, \dots, x_m \rangle$ and $Y = \langle y_1, y_2, \dots, y_n \rangle$:
1. If $x_m == y_n$, then $LCS(X, Y) = LCS(X_{m-1}, Y_{n-1}) + x_m$.
2. If $x_m \ne y_n$, then $LCS(X, Y)$ is the longer of $LCS(X_{m-1}, Y)$ and $LCS(X, Y_{n-1})$.

### Recurrence Relation:
$$L[i][j] = \begin{cases} 0 & \text{if } i = 0 \text{ or } j = 0 \\ 1 + L[i-1][j-1] & \text{if } X[i-1] == Y[j-1] \\ \max(L[i-1][j], \; L[i][j-1]) & \text{if } X[i-1] \ne Y[j-1] \end{cases}$$

### Backtracking:
Starting at cell $L[m][n]$:
- If characters match ($X[i-1] == Y[j-1]$), include character and move diagonally to $L[i-1][j-1]$.
- Otherwise, move in the direction of the larger neighbor ($L[i-1][j]$ or $L[i][j-1]$).

---

## Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $\mathcal{O}(m \cdot n)$ | Two nested loops filling an $(m+1) \times (n+1)$ matrix. |
| **Space Complexity** | $\mathcal{O}(m \cdot n)$ | Matrix storage for reconstructive backtracking. |
| **Backtracking Time** | $\mathcal{O}(m + n)$ | Traverses at most $m+n$ steps from $(m, n)$ to $(0, 0)$. |

---

## Sample Input & Output

### Input
```text
LONGEST
STONE
```

### Output
```text
====================================================
  DAA Lab Experiment 12: LONGEST COMMON SUBSEQUENCE 
====================================================

Enter first string (X): LONGEST
Enter second string (Y): STONE

----------------------------------------------------
LCS Dynamic Programming Table L[i][j]:
----------------------------------------------------
        Ø    S  T  O  N  E
  Ø:   0  0  0  0  0  0
  L:   0  0  0  0  0  0
  O:   0  0  0  1  1  1
  N:   0  0  0  1  2  2
  G:   0  0  0  1  2  2
  E:   0  0  0  1  2  3
  S:   0  1  1  1  2  3
  T:   0  1  2  2  2  3

----------------------------------------------------
     Longest Common Subsequence (LCS) Results       
----------------------------------------------------
String 1 (X):        "LONGEST" (Length: 7)
String 2 (Y):        "STONE" (Length: 5)
Length of LCS:       3
LCS Sequence:        "ONE"
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 12-Longest-Common-Subsequence

# 2. Compile source code
gcc -Wall -Wextra -std=c99 longest_common_subsequence.c -o longest_common_subsequence

# 3. Run executable
# On Windows:
.\longest_common_subsequence.exe
# On Linux / macOS:
./longest_common_subsequence
```
