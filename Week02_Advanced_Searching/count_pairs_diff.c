/*
 * Program: Count Pairs with Given Difference
 * Week: 02, Problem: 3
 * Algorithm: Nested Loop / Hash Map / Two Pointer
 * Time Complexity: O(n^2) (simplest for duplicates) or O(n log n)
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
    int k;
    if (scanf("%d", &k) != 1) {
        free(arr);
        return;
    }

    int count = 0;
    // Count pairs with absolute difference K
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                count++;
            }
        }
    }

    printf("%d\n", count);
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
