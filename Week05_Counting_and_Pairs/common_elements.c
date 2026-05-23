

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int m;
    scanf("%d", &m); 

    int arr1[100001];
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]); 
    }

    int n;
    scanf("%d", &n); 

    int arr2[100001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]); 
    }

    
    qsort(arr1, m, sizeof(int), compare);
    qsort(arr2, n, sizeof(int), compare);

    
    int i = 0, j = 0;
    int first = 1; 

    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            
            if (!first)
                printf(" ");
            printf("%d", arr1[i]);
            first = 0;
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++; 
        } else {
            j++; 
        }
    }

    printf("\n");

    return 0;
}
