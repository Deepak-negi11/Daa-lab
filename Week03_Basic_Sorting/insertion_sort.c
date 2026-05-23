

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
    int shifts = 0;

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > temp) {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }
        
        arr[j + 1] = temp;
        shifts++; 
    }

    for (int i = 0; i < n; i++) {
        printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
    }
    printf("comparisons = %d\n", comparisons);
    printf("shifts = %d\n", shifts);

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
