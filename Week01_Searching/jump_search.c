/*
 * Program: Jump Search (Exponential Search variant)
 * Week: 01, Problem: 3
 * Algorithm: Jump/Exponential Search
 * Time Complexity: O(log n)
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
    int key;
    if (scanf("%d", &key) != 1) {
        free(arr);
        return;
    }

    int comparisons = 0;
    int found = 0;

    // Check first element
    comparisons++;
    if (arr[0] == key) {
        printf("Present %d\n", comparisons);
        free(arr);
        return;
    }

    int low = 0;
    int high = 0;
    int k = 0;
    int idx = 1; // 2^0

    while (idx < n) {
        comparisons++;
        if (arr[idx] == key) {
            found = 1;
            break;
        } else if (arr[idx] > key) {
            high = idx;
            low = 1 << (k - 1);
            if (k == 0) low = 0;
            break;
        }
        low = idx;
        k++;
        idx = 1 << k;
    }

    if (!found) {
        if (idx >= n) {
            high = n - 1;
        }
        // Linear search from low to high
        for (int i = low; i <= high; i++) {
            comparisons++;
            if (arr[i] == key) {
                found = 1;
                break;
            }
        }
    }

    if (found) {
        printf("Present %d\n", comparisons);
    } else {
        printf("Not Present %d\n", comparisons);
    }
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
