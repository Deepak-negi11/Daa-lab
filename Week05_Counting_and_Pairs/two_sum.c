

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int twoPointerSearch(int arr[], int n, int key, int *a, int *b) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == key) {
            *a = arr[left];
            *b = arr[right];
            return 1; 
        } else if (sum < key) {
            left++;   
        } else {
            right--;  
        }
    }

    return 0; 
}

int main() {
    int t;
    scanf("%d", &t); 

    while (t--) {
        int n;
        scanf("%d", &n); 

        int arr[100001];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]); 
        }

        int key;
        scanf("%d", &key); 

        
        mergeSort(arr, 0, n - 1);

        
        int a, b;
        if (twoPointerSearch(arr, n, key, &a, &b)) {
            printf("%d %d\n", a, b);
        } else {
            printf("No Such Elements Exist\n");
        }
    }

    return 0;
}
