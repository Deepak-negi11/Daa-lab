

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

    
    int found = 0;
    for (int k = 2; k < n; k++) {
        int left = 0;
        int right = k - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == arr[k]) {
                printf("%d,%d,%d\n", left + 1, right + 1, k + 1);
                found = 1;
                break;
            } else if (sum < arr[k]) {
                left++;
            } else {
                right--;
            }
        }
        if (found) break;
    }

    if (!found) {
        printf("No sequence found.\n");
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
