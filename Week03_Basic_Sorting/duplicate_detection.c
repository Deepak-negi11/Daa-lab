

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
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

    
    qsort(arr, n, sizeof(int), compare);

    int duplicate = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            duplicate = 1;
            break;
        }
    }

    if (duplicate) {
        printf("YES\n");
    } else {
        printf("NO\n");
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
