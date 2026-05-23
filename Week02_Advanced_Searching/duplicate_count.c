/*
 * Program: Duplicate Count
 * Week: 02, Problem: 1
 * Algorithm: Binary Search for First and Last Occurrence
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int find_first(int *arr, int n, int key) {
    int low = 0, high = n - 1;
    int res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            res = mid;
            high = mid - 1; // look on the left
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

int find_last(int *arr, int n, int key) {
    int low = 0, high = n - 1;
    int res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            res = mid;
            low = mid + 1; // look on the right
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
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
    int key;
    if (scanf("%d", &key) != 1) {
        free(arr);
        return;
    }

    // Sort array just in case input is not fully sorted (e.g. sample has 55 before 25)
    // Using a simple bubble/insertion sort or qsort
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    int first = find_first(arr, n, key);
    if (first == -1) {
        printf("Key not present\n");
    } else {
        int last = find_last(arr, n, key);
        int count = last - first + 1;
        printf("%d - %d\n", key, count);
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
