

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    
    int candidate = arr[0], count = 1;
    for (i = 1; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }
        }
    }

    
    count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    if (count > n / 2) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    
    
    qsort(arr, n, sizeof(int), compare);

    
    int median = arr[n / 2];
    printf("%d\n", median);

    return 0;
}
