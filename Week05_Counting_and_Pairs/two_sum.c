/*
 * Program: Two Sum using Sort + Two Pointer Approach
 * Week: 05
 * Problem: 2
 * Algorithm: Merge Sort + Two Pointer Technique
 * Time Complexity: O(n log n) for sorting + O(n) for two-pointer = O(n log n)
 * Space Complexity: O(n) for merge sort auxiliary array
 *
 * Description:
 *   Given an unsorted array of integers, find whether two elements exist
 *   such that their sum equals the given key. Sort the array first,
 *   then use the two-pointer approach from both ends.
 *
 * Compile: gcc two_sum.c -o two_sum
 */

#include <stdio.h>
#include <stdlib.h>

/* --- Merge Sort Implementation --- */

// Merge two sorted halves into a single sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

// Merge sort - O(n log n)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* --- Two Pointer Approach --- */

// Find two elements with given sum using two pointers - O(n)
// Returns 1 if found, 0 otherwise. Stores result in *a and *b.
int twoPointerSearch(int arr[], int n, int key, int *a, int *b) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == key) {
            *a = arr[left];
            *b = arr[right];
            return 1; // Found
        } else if (sum < key) {
            left++;   // Need larger sum, move left pointer right
        } else {
            right--;  // Need smaller sum, move right pointer left
        }
    }

    return 0; // Not found
}

int main() {
    int t;
    scanf("%d", &t); // Number of test cases

    while (t--) {
        int n;
        scanf("%d", &n); // Size of array

        int arr[100001];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]); // Read array elements
        }

        int key;
        scanf("%d", &key); // Target sum

        // Step 1: Sort the array using merge sort - O(n log n)
        mergeSort(arr, 0, n - 1);

        // Step 2: Use two pointer technique to find the pair - O(n)
        int a, b;
        if (twoPointerSearch(arr, n, key, &a, &b)) {
            printf("%d %d\n", a, b);
        } else {
            printf("No Such Elements Exist\n");
        }
    }

    return 0;
}
