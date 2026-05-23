/*
 * Program: Selection Sort
 * Week: 03, Problem: 2
 * Algorithm: Selection Sort
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdlib.h>

void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return;
        }
    }

    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap arr[i] and arr[min_idx] unconditionally (to match sample output swaps = n - 1)
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        swaps++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
    }
    printf("comparisons = %d\n", comparisons);
    printf("swaps = %d\n", swaps);

    free(arr);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
