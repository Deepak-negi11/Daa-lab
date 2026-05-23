/*
 * Program: Majority Element & Median
 * Week: 10
 * Problem: 3
 * Algorithm: Boyer-Moore Voting (majority), Sorting (median)
 * Time Complexity: O(N log N) due to sorting for median; O(N) for majority
 * Space Complexity: O(1) extra (in-place sort)
 *
 * Description:
 *   1. Find if a majority element exists (appears more than n/2 times)
 *      using Boyer-Moore Voting Algorithm.
 *   2. Find the median by sorting and picking the middle element.
 */

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (ascending order)
int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* ---- Boyer-Moore Voting Algorithm ---- */
    // Phase 1: Find candidate
    int candidate = arr[0], count = 1;
    for (i = 1; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }
        }
    }

    // Phase 2: Verify candidate (count actual occurrences)
    count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    if (count > n / 2) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    /* ---- Median ---- */
    // Sort the array to find the median
    qsort(arr, n, sizeof(int), compare);

    // Median is the middle element (0-indexed: n/2)
    int median = arr[n / 2];
    printf("%d\n", median);

    return 0;
}
