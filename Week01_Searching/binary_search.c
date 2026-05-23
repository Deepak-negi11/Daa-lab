

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

    int low = 0, high = n - 1;
    int found = 0;
    int comparisons = 0;

    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            found = 1;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
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
