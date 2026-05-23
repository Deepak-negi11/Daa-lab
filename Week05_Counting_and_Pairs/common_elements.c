/*
 * Program: Common Elements in Two Sorted Arrays
 * Week: 05
 * Problem: 3
 * Algorithm: Sort + Two Pointer Merge-like Traversal
 * Time Complexity: O(m log m + n log n) for sorting + O(m + n) for finding common
 * Space Complexity: O(1) extra space (apart from input arrays)
 *
 * Description:
 *   Given two integer arrays of size m and n, find elements common to both.
 *   Sort both arrays first, then use a two-pointer technique similar to
 *   the merge step of merge sort to find common elements in O(m+n).
 *
 * Compile: gcc common_elements.c -o common_elements
 */

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int m;
    scanf("%d", &m); // Size of first array

    int arr1[100001];
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]); // Read first array
    }

    int n;
    scanf("%d", &n); // Size of second array

    int arr2[100001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]); // Read second array
    }

    // Sort both arrays first
    qsort(arr1, m, sizeof(int), compare);
    qsort(arr2, n, sizeof(int), compare);

    /*
     * Two-pointer approach to find common elements - O(m + n):
     * - Use pointer i for arr1 and pointer j for arr2.
     * - If arr1[i] == arr2[j], it's a common element; advance both.
     * - If arr1[i] < arr2[j], advance i.
     * - If arr1[i] > arr2[j], advance j.
     */
    int i = 0, j = 0;
    int first = 1; // Flag for formatting output (space-separated)

    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            // Common element found
            if (!first)
                printf(" ");
            printf("%d", arr1[i]);
            first = 0;
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++; // arr1's element is smaller, move arr1's pointer
        } else {
            j++; // arr2's element is smaller, move arr2's pointer
        }
    }

    printf("\n");

    return 0;
}
