# Experiment 01: Quick Sort

## Aim
To implement the **Quick Sort** algorithm in C using the **Divide and Conquer** paradigm, analyze its performance, and sort an array of integers in non-decreasing order.

---

## Algorithm Description & Working

Quick Sort works by partitioning an array into two sub-arrays around a chosen pivot element:
1. **Pivot Selection:** Choose an element as a pivot (in this implementation, the last element $arr[high]$ is selected).
2. **Partitioning:** Rearrange the array such that all elements less than or equal to the pivot are placed to its left, and all elements strictly greater are placed to its right.
3. **Divide & Conquer:** Recursively apply the above two steps to the sub-array of smaller elements (from $low$ to $pi-1$) and the sub-array of larger elements (from $pi+1$ to $high$).
4. **Base Case:** The recursion terminates when a sub-array contains zero or one element ($low \ge high$).

### Pseudocode
```text
QUICK_SORT(A, low, high):
    if low < high:
        pi = PARTITION(A, low, high)
        QUICK_SORT(A, low, pi - 1)
        QUICK_SORT(A, pi + 1, high)

PARTITION(A, low, high):
    pivot = A[high]
    i = low - 1
    for j = low to high - 1:
        if A[j] <= pivot:
            i = i + 1
            swap(A[i], A[j])
    swap(A[i + 1], A[high])
    return i + 1
```

---

## Complexity Analysis

| Case | Time Complexity | Reason |
| :--- | :--- | :--- |
| **Best Case** | $\mathcal{O}(n \log n)$ | Pivot splits the array into two roughly equal halves at each step. |
| **Average Case** | $\mathcal{O}(n \log n)$ | Balanced partitioning over random inputs. |
| **Worst Case** | $\mathcal{O}(n^2)$ | Occurs when the array is already sorted or reverse sorted with an unbalanced pivot choice. |
| **Space Complexity** | $\mathcal{O}(\log n)$ auxiliary | Memory utilized by recursive call stack in average case; $\mathcal{O}(n)$ worst-case. |

---

## Sample Input & Output

### Input
```text
8
24 9 29 14 19 27 1 34
```

### Output
```text
====================================================
         DAA Lab Experiment 01: QUICK SORT          
====================================================

Enter number of elements (1 to 1000): 8
Enter 8 integers separated by spaces:

----------------------------------------------------
Original Array: 24 9 29 14 19 27 1 34
Sorted Array:   1 9 14 19 24 27 29 34
----------------------------------------------------
Statistics:
 - Total Elements:   8
 - Total Comparisons: 15
 - Total Swaps:       14
====================================================
```

---

## Compilation & Execution Instructions

### Using GCC on Windows / Linux / macOS:
```bash
# 1. Navigate to directory
cd 01-Quick-Sort

# 2. Compile the source code
gcc -Wall -Wextra -std=c99 quick_sort.c -o quick_sort

# 3. Run the compiled executable
# On Windows:
.\quick_sort.exe
# On Linux / macOS:
./quick_sort
```
