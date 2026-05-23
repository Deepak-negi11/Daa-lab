/*
 * Program: Randomized Quick Sort
 * Week: 04, Problem: 2
 * Algorithm: Randomized Quick Sort
 * Time Complexity: O(n log n) average, O(n^2) worst case
 * Space Complexity: O(log n) average (recursion stack)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;
long long swaps = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

int partition(int *arr, int low, int high) {
    // Select random pivot and swap with high
    int random_pivot = low + rand() % (high - low + 1);
    swap(&arr[random_pivot], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
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

    comparisons = 0;
    swaps = 0;

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
    }
    printf("comparisons = %lld\n", comparisons);
    printf("swaps = %lld\n", swaps);

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
