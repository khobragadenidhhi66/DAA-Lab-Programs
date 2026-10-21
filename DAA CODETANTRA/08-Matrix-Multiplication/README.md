# Experiment 08: Strassen's Matrix Multiplication

## Aim
To implement **Strassen's Matrix Multiplication Algorithm** in C using the **Divide and Conquer** paradigm, compare its theoretical and empirical performance against the standard $\mathcal{O}(n^3)$ algorithm, and compute the product of two square matrices.

---

## Algorithm Description & Working

Standard matrix multiplication of two $n \times n$ matrices takes $\mathcal{O}(n^3)$ operations and $8$ recursive multiplications when divided into $(n/2) \times (n/2)$ submatrices.

Volker Strassen's breakthrough uses **7 multiplications** and **18 additions/subtractions**:

### Partitioning:
Given square matrices $A$ and $B$:
$$A = \begin{bmatrix} A_{11} & A_{12} \\ A_{21} & A_{22} \end{bmatrix}, \quad B = \begin{bmatrix} B_{11} & B_{12} \\ B_{21} & B_{22} \end{bmatrix}$$

### 7 Intermediate Multiplication Products:
1. $M_1 = (A_{11} + A_{22}) \times (B_{11} + B_{22})$
2. $M_2 = (A_{21} + A_{22}) \times B_{11}$
3. $M_3 = A_{11} \times (B_{12} - B_{22})$
4. $M_4 = A_{22} \times (B_{21} - B_{11})$
5. $M_5 = (A_{11} + A_{12}) \times B_{22}$
6. $M_6 = (A_{21} - A_{11}) \times (B_{11} + B_{12})$
7. $M_7 = (A_{12} - A_{22}) \times (B_{21} + B_{22})$

### Constructing Result Submatrices of $C$:
- $C_{11} = M_1 + M_4 - M_5 + M_7$
- $C_{12} = M_3 + M_5$
- $C_{21} = M_2 + M_4$
- $C_{22} = M_1 - M_2 + M_3 + M_6$

If $n$ is not a power of 2, the matrices are padded with zeros to the next power of 2.

---

## Complexity Analysis

| Metric | Standard Multiplication | Strassen's Algorithm |
| :--- | :--- | :--- |
| **Recurrence Relation** | $T(n) = 8T(n/2) + \Theta(n^2)$ | $T(n) = 7T(n/2) + \Theta(n^2)$ |
| **Time Complexity** | $\mathcal{O}(n^3)$ | $\mathcal{O}(n^{\log_2 7}) \approx \mathcal{O}(n^{2.8074})$ |
| **Space Complexity** | $\mathcal{O}(1)$ auxiliary / $\mathcal{O}(n^2)$ output | $\mathcal{O}(n^2)$ auxiliary memory |

---

## Sample Input & Output

### Input
A pair of $2 \times 2$ matrices:
```text
2
1 2
3 4
5 6
7 8
```

### Output
```text
====================================================
   DAA Lab Experiment 08: STRASSEN'S MATRIX MULT    
====================================================

Enter dimension n for square matrices (n x n, max 64): 2

Enter elements of Matrix A (2 x 2) row by row:
Enter elements of Matrix B (2 x 2) row by row:

----------------------------------------------------
Matrix A:
  [     1     2 ]
  [     3     4 ]

Matrix B:
  [     5     6 ]
  [     7     8 ]
----------------------------------------------------
Resultant Matrix C (via Strassen's Algorithm):
  [    19    22 ]
  [    43    50 ]

Resultant Matrix C (via Standard O(n^3) Algorithm):
  [    19    22 ]
  [    43    50 ]
----------------------------------------------------
[SUCCESS] Both Strassen and Standard results match perfectly!
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 08-Matrix-Multiplication

# 2. Compile source code
gcc -Wall -Wextra -std=c99 matrix_multiplication.c -o matrix_multiplication

# 3. Run executable
# On Windows:
.\matrix_multiplication.exe
# On Linux / macOS:
./matrix_multiplication
```
