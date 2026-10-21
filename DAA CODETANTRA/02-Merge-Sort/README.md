# Experiment 02: Merge Sort

## Aim
To implement the **Merge Sort** algorithm in C using the **Divide and Conquer** paradigm, analyze its recursive dividing and merging mechanism, and sort an array of integers in non-decreasing order.

---

## Algorithm Description & Working

Merge Sort follows a three-step divide-and-conquer sequence:
1. **Divide:** Find the middle point of the current array segment: $mid = left + (right - left) / 2$.
2. **Conquer:** Recursively sort the left sub-array $A[left \dots mid]$ and right sub-array $A[mid + 1 \dots right]$.
3. **Combine:** Merge the two sorted sub-arrays into a single sorted array using temporary auxiliary storage.
4. **Base Case:** Recursion stops when a sub-array contains only 1 element ($left \ge right$), which is trivially sorted.

### Pseudocode
```text
MERGE_SORT(A, left, right):
    if left < right:
        mid = left + (right - left) / 2
        MERGE_SORT(A, left, mid)
        MERGE_SORT(A, mid + 1, right)
        MERGE(A, left, mid, right)

MERGE(A, left, mid, right):
    Create temp arrays L[mid - left + 1] and R[right - mid]
    Copy data from A to L and R
    i = 0, j = 0, k = left
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            A[k++] = L[i++]
        else:
            A[k++] = R[j++]
    Copy any remaining elements of L and R into A
```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Best Case Time** | $\mathcal{O}(n \log n)$ | Array is divided into halves at $\log_2 n$ levels; each level takes $\mathcal{O}(n)$ merging. |
| **Average Case Time** | $\mathcal{O}(n \log n)$ | Independent of initial arrangement of elements. |
| **Worst Case Time** | $\mathcal{O}(n \log n)$ | Guaranteed $n \log n$ even on reverse or identical inputs. |
| **Space Complexity** | $\mathcal{O}(n)$ auxiliary | Requires temporary buffer space proportional to array size. |
| **Stability** | Stable | Maintains relative order of equal elements ($L[i] \le R[j]$). |

---

## Sample Input & Output

### Input
```text
8
38 27 43 3 9 82 10 19
```

### Output
```text
====================================================
         DAA Lab Experiment 02: MERGE SORT          
====================================================

Enter number of elements (1 to 1000): 8
Enter 8 integers separated by spaces:

----------------------------------------------------
Original Array: 38 27 43 3 9 82 10 19
Sorted Array:   3 9 10 19 27 38 43 82
----------------------------------------------------
Statistics:
 - Total Elements:    8
 - Total Comparisons: 17
 - Total Copy Ops:    24
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 02-Merge-Sort

# 2. Compile source code
gcc -Wall -Wextra -std=c99 merge_sort.c -o merge_sort

# 3. Run executable
# On Windows:
.\merge_sort.exe
# On Linux / macOS:
./merge_sort
```
