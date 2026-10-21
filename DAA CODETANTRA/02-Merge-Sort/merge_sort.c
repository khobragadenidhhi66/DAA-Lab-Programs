/**
 * ============================================================================
 * Program 02: Merge Sort Implementation
 * Algorithm Design Paradigm: Divide and Conquer
 * ============================================================================
 * Description:
 *   Merge Sort is a stable, comparison-based sorting algorithm based on the
 *   Divide and Conquer principle. It continuously divides the unsorted list
 *   into two approximately equal sub-lists until sub-lists of size 1 are
 *   obtained (base case). It then repeatedly merges sub-lists to produce new
 *   sorted sub-lists until the entire list is sorted.
 *
 * Time Complexity:
 *   - Best Case:    O(n log n)
 *   - Average Case: O(n log n)
 *   - Worst Case:   O(n log n)
 *
 * Space Complexity:
 *   - Auxiliary Space: O(n) for temporary merging arrays + O(log n) call stack.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

/* Statistics tracking */
static long long comparisons = 0;
static long long merge_ops = 0;

/**
 * Merges two sorted subarrays of arr[].
 * First subarray is arr[left..mid]
 * Second subarray is arr[mid+1..right]
 *
 * @param arr    The master array.
 * @param left   Leftmost index.
 * @param mid    Middle index.
 * @param right  Rightmost index.
 */
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* Temporary arrays */
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        fprintf(stderr, "Error: Memory allocation failed during merge.\n");
        free(L);
        free(R);
        exit(EXIT_FAILURE);
    }

    /* Copy data to temporary arrays */
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    /* Merge temporary arrays back into arr[left..right] */
    int i = 0;    /* Initial index of first subarray */
    int j = 0;    /* Initial index of second subarray */
    int k = left; /* Initial index of merged subarray */

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        merge_ops++;
    }

    /* Copy the remaining elements of L[], if any */
    while (i < n1) {
        arr[k++] = L[i++];
        merge_ops++;
    }

    /* Copy the remaining elements of R[], if any */
    while (j < n2) {
        arr[k++] = R[j++];
        merge_ops++;
    }

    free(L);
    free(R);
}

/**
 * Recursive Merge Sort function.
 *
 * @param arr    Array to sort.
 * @param left   Left index of sub-array.
 * @param right  Right index of sub-array.
 */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        /* Prevents overflow for large left and right */
        int mid = left + (right - left) / 2;

        /* Divide and sort first and second halves */
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        /* Conquer and merge the sorted halves */
        merge(arr, left, mid, right);
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
    printf("         DAA Lab Experiment 02: MERGE SORT          \n");
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
    merge_ops = 0;
    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:   ");
    printArray(arr, n);
    printf("----------------------------------------------------\n");
    printf("Statistics:\n");
    printf(" - Total Elements:    %d\n", n);
    printf(" - Total Comparisons: %lld\n", comparisons);
    printf(" - Total Copy Ops:    %lld\n", merge_ops);
    printf("====================================================\n");

    return EXIT_SUCCESS;
}
