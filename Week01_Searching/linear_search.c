/*
 * Program: Linear Search
 * Week: 01, Problem: 1
 * Algorithm: Linear Search
 * Time Complexity: O(n)
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

    int found = 0;
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            found = 1;
            break;
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
