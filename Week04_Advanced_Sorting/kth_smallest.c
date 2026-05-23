/*
 * Program: Kth Smallest Element
 * Week: 04, Problem: 3
 * Algorithm: QuickSelect (Average O(n) Time Complexity)
 * Time Complexity: O(n) average, O(n^2) worst case
 * Space Complexity: O(log n) recursion stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int random_pivot = low + rand() % (high - low + 1);
    swap(&arr[random_pivot], &arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int quick_select(int *arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int index = partition(arr, low, high);
        if (index - low == k - 1) {
            return arr[index];
        }
        if (index - low > k - 1) {
            return quick_select(arr, low, index - 1, k);
        }
        return quick_select(arr, index + 1, high, k - (index - low + 1));
    }
    return -1;
}

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

    if (k > 0 && k <= n) {
        int result = quick_select(arr, 0, n - 1, k);
        printf("%d\n", result);
    } else {
        printf("not present\n");
    }
    free(arr);
}

int main() {
    srand(time(NULL));
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
