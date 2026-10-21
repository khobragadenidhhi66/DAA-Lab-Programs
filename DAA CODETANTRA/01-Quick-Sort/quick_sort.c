/**
 * ============================================================================
 * Program 01: Quick Sort Implementation
 * Algorithm Design Paradigm: Divide and Conquer
 * ============================================================================
 * Description:
 *   Quick Sort is an efficient, in-place sorting algorithm that follows the
 *   Divide and Conquer strategy. It selects an element as a 'pivot' and
 *   partitions the given array around the pivot such that elements smaller
 *   than the pivot are placed before it and elements greater are placed after.
 *   The sub-arrays are then recursively sorted.
 *
 * Time Complexity:
 *   - Best Case:    O(n log n)
 *   - Average Case: O(n log n)
 *   - Worst Case:   O(n^2)  (when array is already sorted and pivot is extreme)
 *
 * Space Complexity:
 *   - Auxiliary Space: O(log n) to O(n) (recursion call stack)
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

/* Global step counter for demonstration */
static long long comparisons = 0;
static long long swaps = 0;

/**
 * Utility function to swap two integers.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

/**
 * Partition function using the Lomuto Partition Scheme.
 * Chooses the last element as the pivot, places it at its correct
 * position in the sorted array, and places all smaller elements to its left
 * and all greater elements to its right.
 *
 * @param arr   The array of integers.
 * @param low   Starting index.
 * @param high  Ending index (contains the pivot).
 * @return      The index of the pivot element.
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * Recursive Quick Sort function.
 *
 * @param arr   The array to sort.
 * @param low   Starting index.
 * @param high  Ending index.
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[pi] is now at the right place */
        int pi = partition(arr, low, high);

        /* Separately sort elements before partition and after partition */
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * Utility function to print an array.
 *
 * @param arr   The array to print.
 * @param size  The number of elements in the array.
 */
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void) {
    int n;
    int arr[MAX_SIZE];

    printf("====================================================\n");
    printf("         DAA Lab Experiment 01: QUICK SORT          \n");
    printf("====================================================\n\n");

    printf("Enter number of elements (1 to %d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: Invalid input! Please enter an integer.\n");
        return EXIT_FAILURE;
    }

    /* Input validation */
    if (n <= 0 || n > MAX_SIZE) {
        fprintf(stderr, "Error: Number of elements must be between 1 and %d.\n", MAX_SIZE);
        return EXIT_FAILURE;
    }

    printf("Enter %d integers separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error: Failed to read element at index %d.\n", i);
            return EXIT_FAILURE;
        }
    }

    printf("\n----------------------------------------------------\n");
    printf("Original Array: ");
    printArray(arr, n);

    comparisons = 0;
    swaps = 0;
    quickSort(arr, 0, n - 1);

    printf("Sorted Array:   ");
    printArray(arr, n);
    printf("----------------------------------------------------\n");
    printf("Statistics:\n");
    printf(" - Total Elements:   %d\n", n);
    printf(" - Total Comparisons: %lld\n", comparisons);
    printf(" - Total Swaps:       %lld\n", swaps);
    printf("====================================================\n");

    return EXIT_SUCCESS;
}
